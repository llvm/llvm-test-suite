/*
 *  Copyright (c) 1990 Regents of the University of Michigan.
 *  All rights reserved.
 *
 *  bind.c
 */

#ifndef lint 
static char copyright[] = "@(#) Copyright (c) 1990 Regents of the University of Michigan.\nAll rights reserved.\n";
#endif

#include <stdio.h>
#include <stdlib.h>
#include "dixie.h"
#include <string.h>
#if defined(MACOS) || defined(DOS) || defined(VMS)
#include <types.h>
#include <stdlib.h>
#ifdef MACOS
#include "tcp.h"
#endif
#ifdef VMS
#include <in.h>
#endif
#else
#include <sys/types.h>
#include <netinet/in.h>
#endif

extern int	dxi_limit;
extern char	*dxi_buffer;
extern int	dxi_errno;
extern int	dxi_debug;
extern int	dxi_bound;

extern int dxi_send( char type, char *buf, int buflen, char *answer, int anslen, int scope );
extern int open_sock( unsigned long address, int port );
extern u_long inet_addr( char *s );

int nullbound;

/*
 * dxi_udpbind - bind to the dixie server (and X.500).  The dn and password
 * of the entry to which to bind are supplied.  0 is returned on success,
 * -1 if the DSA could not be contacted, or the length of the error packet
 * in case or other trouble.
 *
 * Example:
 *	dxi_udpbind( "c=us@o=university of michigan@cn=manager", "secret" )
 */

int dxi_udpbind(char *who, char *passwd)
{
	char		answer[256];
	char		*temp;
	int		len, i;
	unsigned long	address;
	int		port;

	dxi_errno = 0;

	/* 
	 * build the packet.  it looks like this:
	 * 	who\0passwd\0
	 */

	nullbound = (who == NULL || *who == '\0');
	if ( who == NULL )
		who = "";
	if ( passwd == NULL )
		passwd = "";
	strcpy( dxi_buffer, who );
	len = strlen( who ) + 1;
	temp = dxi_buffer + len;
	strcpy( temp, passwd );
	len += strlen( passwd );
	dxi_buffer[len++] = '\0';

	/* send it */
	if ( (len = dxi_send( DXI_BIND,  dxi_buffer, len, answer,
	    sizeof(answer), 0 )) < 0 ) {
		dxi_errno = DXI_DOWN;
		return( len );
	}
	dxi_errno = answer[DXI_H_RC];

	/* see if it was successful */
	switch ( dxi_errno ) {
	case DXI_SUCCESS :
		if ( dxi_bound >= 0 )
			return( 0 );
		temp = NULL;
		for ( i = DXI_H_SIZE; i < len; i++ ) {
			if ( answer[i] == DXI_VAL_SEP ) {
				answer[i] = '\0';
				if ( temp == NULL )
					temp = &(answer[i + 1]);
			}
		}
		address = inet_addr( &(answer[DXI_H_SIZE]) );
		port = atoi( temp );
		dxi_bound = open_sock( address, port );
		return( dxi_bound < 0 ? -1 : 0 );

	default:
		return( -1 );
	}
}

/*
 * dxi_bind - bind to the dixie server (and X.500).  The dn and password
 * of the entry to which to bind are supplied.  0 is returned on success,
 * -1 if the DSA could not be contacted, or the length of the error packet
 * in case or other trouble.  This bind is done via TCP.
 *
 * Example:
 *	dxi_bind( "c=us@o=university of michigan@cn=manager", "secret" )
 */

#if defined(MACOS) || defined(DOS)
extern ip_addr dixieaddr;
#else
extern struct sockaddr_in dixieaddr;
#endif

int dxi_bind( char *who, char *passwd )
{
	nullbound = (who == NULL || *who == '\0');
	if ( dxi_bound >= 0 )
		return( dxi_udpbind( who, passwd ) );
#if defined(MACOS) || defined(DOS)
	dxi_bound = open_sock( dixieaddr, DXI_PORT );
#else
	dxi_bound = open_sock( dixieaddr.sin_addr.s_addr, DXI_PORT );
#endif

	if ( dxi_bound < 0 )
		return( -1 );

	dxi_errno = DXI_SUCCESS;
	if ( who == NULL || *who == '\0' )
		return( 0 );

	return( dxi_udpbind( who, passwd ) );
}
