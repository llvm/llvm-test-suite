/*
 *  Copyright (c) 1990 Regents of the University of Michigan.
 *  All rights reserved.
 *
 *  send.c
 */

#ifndef lint 
static char copyright[] = "@(#) Copyright (c) 1990 Regents of the University of Michigan.\nAll rights reserved.\n";
#endif

#include <stdio.h>
#include <stdlib.h>
#include "dixie.h"
#include <string.h>
#if !defined(__STDC__) && !defined(VMS)
#include <memory.h>
#endif
#if defined(MACOS)
#include "tcp.h"
#else
#ifdef VMS
#include <types.h>
#include <in.h>
#include <signal.h>
#else
#include <sys/types.h>
#include <sys/uio.h>
#include <netinet/in.h>
#endif
#include <sys/param.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <arpa/nameser.h>
#include <resolv.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <unistd.h>
#endif

#define MAX_RETRY		3
#define MAX_DIXIE_SERVERS	5

#define DXI_GETLEN(x, y) { (void) memcpy( (char *) &x, &y[DXI_H_TOTLEN], \
			sizeof(long)); x = ntohl(x);}
#define DXI_GETID(x, y) { (void) memcpy( (char *) &x, &y[DXI_H_ID], \
			sizeof(short));}
#define DXI_SETID(x, y) { (void) memcpy( (char *) &y[DXI_H_ID], (char *) &x, \
			sizeof(short));}
#define DXI_SETOP(x, y) { (void) memcpy( (char *) &y[DXI_H_OP], (char *) &x, \
			sizeof(short));}
#define DXI_SETSCOPE(x, y) {y[DXI_H_SRCH_SCOPE] = x;}
#define DXI_SETVERSION(x, y) {y[DXI_H_VERSION] = x;}
#define DXI_SETOPTIONS(x, y) {y[DXI_H_OPTIONS] = x;}
#define DXI_SETTIMELIMIT(x, y) { (void) memcpy( &y[DXI_H_TIMELIMIT], \
			(char *) &x, sizeof(short));}
#define DXI_SETSIZELIMIT(x, y) { (void) memcpy( &y[DXI_H_SIZELIMIT], \
			(char *) &x, sizeof(short));}

extern void *memset(void *s, int c, size_t n);
extern int errno, dxi_debug, dxi_timeout, dxi_retries;
extern char dxi_options;

#ifndef INADDR_LOOPBACK
#define INADDR_LOOPBACK 0x7f000001
#endif

#ifndef FD_SET
#define	NFDBITS		32
#define	FD_SETSIZE	32
#define	FD_SET(n, p)	((p)->fds_bits[(n)/NFDBITS] |= (1 << ((n) % NFDBITS)))
#define	FD_CLR(n, p)	((p)->fds_bits[(n)/NFDBITS] &= ~(1 << ((n) % NFDBITS)))
#define	FD_ISSET(n, p)	((p)->fds_bits[(n)/NFDBITS] & (1 << ((n) % NFDBITS)))
#define FD_ZERO(p)	(void) memset((char *)(p), 0, sizeof(*(p)))
#endif

#ifndef VMS
char    *h_errlist[] = {
	"Error 0",
	"Unknown host",                         /* 1 HOST_NOT_FOUND */
	"Host name lookup failure",             /* 2 TRY_AGAIN */
	"Unknown server error",                 /* 3 NO_RECOVERY */
	"No address associated with name",      /* 4 NO_ADDRESS */
};
#endif

static int			s = -1;		/* socket used for UDP */
#if defined(MACOS) || defined(DOS)
ip_addr				dixieaddr;	/* address of dixie server */
#else
void attempt_rebind();
struct sockaddr_in		dixieaddr;	/* address of dixie server */
extern int nullbound;
#endif
static int			servers;
static char		*dxibuf;

#if !defined(NOUDP) && !defined(VMS_MULTINET)
int xres_selwait(int sock, struct timeval *timeout)
{
        fd_set dsmask;
        register int n;

        FD_ZERO(&dsmask);
        FD_SET(sock, &dsmask);
        n = select(sock+1, &dsmask, (fd_set *)NULL, (fd_set *)NULL, timeout);
        return(n);
}
#endif /* !NOUDP & !vms_multinet */

int dxi_send( char type, char *buf, int buflen, char *answer, int anslen, int scope )
{
	int			i, n;
	int			retry;
	long		resplen, totlen;
	short			nshort;
#ifndef NOUDP
	struct timeval		timeout;
#endif
	static unsigned short 	id = 0;
	extern int		dxi_bound;

	if ( dxibuf == NULL )
		dxibuf = (char *) calloc( MAX_PKT_SIZE + DXI_H_SIZE, 1 );

	/*
	 *  First, we need to take the buffer we were given and the type
	 *  that was specified and build a valid packet.  The query type
	 *  should be put in the first byte of the header, which should
	 *  then be padded out with zeroes.
	 *
	 *  Then update the buffer size to reflect the addition of the
	 *  header and point buffer to the newly formed packet.
	 */

	bzero(dxibuf, DXI_H_SIZE);
	DXI_SETOP(type, dxibuf);
	DXI_SETSCOPE(scope, dxibuf);
	DXI_SETVERSION(1, dxibuf);
	DXI_SETOPTIONS(dxi_options, dxibuf);
	DXI_SETTIMELIMIT(dxi_timelimit, dxibuf);
	DXI_SETSIZELIMIT(dxi_sizelimit, dxibuf);
	(void) memcpy(&dxibuf[DXI_H_SIZE], buf, buflen);
	buflen += DXI_H_SIZE;
	buf = dxibuf;

	/* use the default DIXIE server if none defined */
	if (servers == 0)
		add_server(INADDR_LOOPBACK);
	id++;
	nshort = htons(id);

	/* if bound to a DSA use our open TCP socket */
	if (dxi_bound >= 0) {
		(void) memcpy( &buf[DXI_H_ID], (char *) &nshort, sizeof(short));
		(void) memset( answer, 0, DXI_H_SIZE );
#ifdef DEBUG
		if (dxi_debug > 5) {
			printf("Sending (%d) over TCP:\n", buflen);
			dxi_bprint(buf, buflen);
		}
#endif

#if defined(DOS) || defined(MACOS) || defined VMS_MULTINET
#ifdef DOS
		if ( netwrite( dxi_bound, (u_char *) buf, buflen ) < 0 ) {
			return( -1 );
		}
		if ( (resplen = nread( dxi_bound, answer, anslen )) < 0 ) {
			return( -1 );
		}
#else /* macos or vms */
#ifdef MACOS
		if (tcpwrite(dxi_bound, (u_char *)buf, buflen ) != 0 ) {
			return(-1);
		}
		if ((resplen = tcpread(dxi_bound, 0, (u_char *)answer, anslen, (DialogPtr)NULL )) < 0 ) {
			return( -1 );
		}
#else /* vms */
                while (TRUE)
                {
                    if (socket_write(dxi_bound, buf, buflen) != buflen)
                        if (socket_errno == EWOULDBLOCK)
                        {
                            continue;
                        }
                        else
                        {
                            socket_perror("write");
                            return(-1);
                        };
                    break;
                }
                while (TRUE)
                {
                    if ((resplen = socket_read(dxi_bound, answer, anslen)) < 0)
                        if (socket_errno == EWOULDBLOCK)
                        {
                            continue;
                        }
                        else
                        {
                            socket_perror("read");
                            return(-1);
                        };
                    break;
                }
#endif /* vms */
#endif /* macos or vms */
#else /* unix */
		for ( i = 0; i < 2; i++ ) {
			if (write(dxi_bound, buf, buflen) != buflen) {
				if ( dxi_bound >= 0 )
					close( dxi_bound );
				dxi_bound = -1;

				if ( ! nullbound )
					return( -1 );

				(void) dxi_bind( NULL, NULL );
				continue;
			}

			if ((resplen = read(dxi_bound, answer, anslen)) <= 0) {
				if ( dxi_bound >= 0 )
					close( dxi_bound );
				dxi_bound = -1;

				if ( ! nullbound )
					return( -1 );

				(void) dxi_bind( NULL, NULL );
				continue;
			}
			break;
		}

		if ( dxi_bound < 0 ) {
			return(-1);
		}
#endif
		DXI_GETLEN( totlen, answer );
		totlen += DXI_H_SIZE;
		n = resplen;
		if ( dxi_debug > 5 ) printf("totlen is %d\n", totlen );
		while ( resplen < totlen ) {
			if ( dxi_debug > 5 ) 
				printf("...%d to go\n", totlen - resplen);
#if defined(DOS) || defined(MACOS) || defined(VMS_MULTINET)
#ifdef DOS
			if ( (n = nread( dxi_bound, answer + resplen,
			    totlen - n )) < 0 ) {
				return( -1 );
			}
#else /* MACOS or VMS_MULTINET */
#ifdef MACOS
			if ((n = tcpread( dxi_bound, 0, (u_char *)answer + resplen, totlen - n,
				(DialogPtr)NULL )) < 0 ) {
				return( -1 );
			}
#else /* VMS_MULTINET */
			if ( (n = socket_read( dxi_bound, answer + resplen,
				totlen - n )) < 0 ) {
			        socket_perror( "read" );
				return( -1 );
			}
#endif /* MACOS */
#endif /* MACOS or VMS_MULTINET */
#else /* UNIX */
			if ( (n = read( dxi_bound, answer + resplen,
			    totlen - n )) <= 0 ) {
				perror( "read" );
				return( -1 );
			}
#endif
			if ( dxi_debug > 5 ) 
				printf("...read %d\n", n );
			resplen += n;
		}
#ifdef DEBUG
		if (dxi_debug > 5) {
			printf("Received (%d):\n", resplen);
			dxi_bprint(answer, resplen);
		}
#endif
		return(resplen);
	}

	/*
	 *  OK, we weren't bound, so we'll need to use UDP.
	 */
#ifndef NOUDP

	/* Get a socket if we don't already have one */
	if ( s < 0 ) {
		if ( (s = socket( AF_INET, SOCK_DGRAM, 0 )) < 0 ) {
			perror( "socket" );
			return( -1 );
		}
	}

	DXI_SETID( nshort, buf );
	(void) memset( answer, 0, DXI_H_SIZE );
	timeout.tv_sec = 0;
	timeout.tv_usec = 0;
	for ( retry = 0; retry < dxi_retries; retry++ ) {
#ifdef DEBUG
		if ( dxi_debug & 4 ) {
			printf("Sending (%d) try #%d:\n", buflen, retry);
			dxi_bprint( buf, buflen );
		}
#endif
		if ( sendto( s, buf, buflen, 0, (struct sockaddr *)&dixieaddr,
		    sizeof(struct sockaddr)) < 0 ) {
			perror( "sendto" );
			return( -1 );
		}

		/* wait for a reply (exponential back off) */
		timeout.tv_sec = timeout.tv_sec == 0 ? dxi_timeout
		    : 2 * timeout.tv_sec;
		timeout.tv_usec = 0;

wait:
#ifndef VMS_MULTINET
		if ( (n = xres_selwait( s, &timeout )) < 0 ) {
			perror( "xres_selwait" );
			continue;
		}

		/* timed out */
		if (n == 0)
			continue;

		/* didn't timeout -- read the packet */
		if ( (resplen = recv( s, answer, anslen, 0 )) < 0 ) {
			perror( "recv" );
			return( -1 );
		}
#endif
#ifdef DEBUG
		if ( dxi_debug & 4 ) {
			printf("Received (%d):\n", resplen);
			dxi_bprint( answer, resplen );
		}
#endif
		/*
		 *  Fetch out the id, convert it to host order
		 *  and see if its in response to the current request.
		 */

		DXI_GETID( nshort, answer );
		if ( id != (nshort = ntohs(nshort)) ) {
			if ( dxi_debug & 4 )
				printf("expecting id %d got %d\n", id, nshort);
			goto wait;
		}

		DXI_GETLEN( totlen, answer );
		if ( totlen + DXI_H_SIZE != resplen ) {
			answer[DXI_H_RC] = DXI_TOOBIG;
			return( DXI_H_SIZE );
		}

		return( resplen );
	}

	if (s >= 0) {
#ifdef VMS_MULTINET
		(void) socket_close( s );
#else
		(void) close( s );
#endif /* vms */
		s = -1;
	}
#ifdef VMS_MULTINET
	socket_errno = ETIMEDOUT;
#else
	errno = ETIMEDOUT;
#endif /* vms */
#endif

	return (-1);
}

#if defined(MACOS) || defined(DOS)
int open_sock(unsigned long address, short port)
{
	short	s;
	
	if (( s = tcpopen( NULL, TCP_BUFSIZ )) < 0 ) {
		return( s );
	}
	
	if ( tcpconnect( s, address, port ) < 0 ) {
		return( -1 );
	}
	
	return( s );
}
#else
int open_sock( unsigned long address, int port )
{
	int s;
	struct sockaddr_in sock;

	sock.sin_addr.s_addr = htonl( address );
	sock.sin_family = AF_INET;
	sock.sin_port = htons( port );
	if ( (s = socket( AF_INET, SOCK_STREAM, 0 )) < 0 ) {
		dxi_errno = DXI_ERROR;
		return( s );
	}
	if ( connect( s, (struct sockaddr *) &sock, sizeof(sock) ) < 0 ) {
		dxi_errno = DXI_DOWN;
		return( -1 );
	}
	if (dxi_debug) printf("open_sock returning %d\n", s);
	return( s );
}
#endif

int add_server( u_long ns )
{
#if !defined(MACOS) & !defined(DOS)
	struct hostent *hp;
	struct servent *sp;
	struct in_addr in;
	extern int h_errno;
#endif
	int port;

	/* give up if earlier routines failed */
	if ( ns == 0 ) return( -1 );

	/* DIXIE port? */
#if defined(MACOS) || defined(DOS)
	port = DXI_PORT;
	dixieaddr = ns;
#else
	if ( (sp = getservbyname( "dixie", "udp" )) == NULL )
		port = DXI_PORT;
	else
		port = sp->s_port;
	in.s_addr = ns;

	/* add the new server */
	hp = gethostbyaddr( (char *) &in, sizeof(in), AF_INET );
	if ( hp == NULL && h_errno != TRY_AGAIN ) {
		return( -1 );
	}
	dixieaddr.sin_addr.s_addr = htonl( ns );
	dixieaddr.sin_family = AF_INET;
	dixieaddr.sin_port = htons( port );
#endif
	servers = 1;

	return( 0 );
}


int dxi_close(void)
{
	extern int dxi_bound;

	if (dxi_bound >= 0) {
#ifndef NOUDP
		if ( s >= 0 ) {			/* close UDP socket */
			close( s );
			s = -1;
		}
#endif

#if defined(MACOS) || defined(DOS)
		tcpclose( dxi_bound );	/* close TCP socket */
#else
		close( dxi_bound );		/* close TCP socket */
#endif
	}
	
	if (dxi_debug) printf("**** dxi_close ****\n");
	dxi_bound = -1;
	if ( dxibuf != NULL ) {		/* free the message buffer */
		free( dxibuf );
		dxibuf = NULL;
	}
	return -99;
}

#if !defined(MACOS) && !defined(DOS)

void attempt_rebind(void)
{

}

#endif
