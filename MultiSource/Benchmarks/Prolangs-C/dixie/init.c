/*
 *  Copyright (c) 1990 Regents of the University of Michigan.
 *  All rights reserved.
 *
 *  show.c
 */

#ifndef lint 
static char copyright[] = "@(#) Copyright (c) 1990 Regents of the University of Michigan.\nAll rights reserved.\n";
#endif

#include "dixie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if !defined(__STDC__) && !defined(VMS)
#include <memory.h>
#endif
#ifdef DOS
#include <malloc.h>
#endif
#if defined(MACOS) || defined(DOS)
#include <types.h>
#include "tcp.h"
#else
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <signal.h>
#endif

#ifndef INADDR_LOOPBACK
#define INADDR_LOOPBACK 0x7f000001
#endif

extern u_long inet_addr( char *s );
extern int add_server( u_long ns );

/*
 * dxi_init - initialize the dixie library.  host is used as the dixie
 * host, timeout and retries as the default initial number of seconds
 * to wait before retransmitting packets, and number of retries to make,
 * respectively.  Supplying 0 for timeout or retries resorts to the
 * default values of 2 and 4, respectively.  Supplying NULL for the host
 * causes the localhost to be used.
 *
 * Example:
 *	dxi_init( "some.host.some.domain", 2, 4 )
 */

int dxi_init( char *host, int timeout, int retries )
{
#if defined(MACOS) || defined(DOS)
	struct hostInfo *hip;
#else
	extern void attempt_rebind();
	struct hostent	*hp;
#endif
	unsigned long	server;
	extern char	*dxi_buffer;
	extern int	dxi_timeout, dxi_retries;

	dxi_errno = DXI_ERROR;	/* pessimistic, but efficient... */
	if ( dxi_buffer == NULL ) {
		if ( (dxi_buffer = (char *) malloc( MAX_PKT_SIZE )) == NULL )
			return( -1 );
	}

	if ( host != NULL ) {
#if defined(MACOS) || defined(DOS)
		if ( (hip = gethostinfobyname( host )) == NULL ) {
			return( -1 );
		}
		(void) memcpy( (char *) & server, (char *) &hip->addr[ 0 ],
		    sizeof(long) );
		
#else
		if ( (server = inet_addr( host )) == -1 ) {
			if ( (hp = gethostbyname( host )) == NULL ) {
				return( -1 );
			}
			(void) memcpy( (char *) &server, (char *) hp->h_addr,
			    sizeof(long) );
		}
#endif
	} else {
		server = INADDR_LOOPBACK;
	}

	if ( add_server( server ) < 0 )
		return( -1 );

#if !defined(MACOS) && !defined(DOS)
	(void) signal( SIGPIPE, attempt_rebind );
#endif

	dxi_timeout = timeout <= 0 ? 2 : timeout;
	dxi_retries = retries <= 0 ? 4 : retries;
	dxi_options = 0;

	dxi_errno = DXI_SUCCESS;
	return( 0 );
}
