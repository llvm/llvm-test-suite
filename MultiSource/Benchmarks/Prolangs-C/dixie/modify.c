/*
 *  Copyright (c) 1990 Regents of the University of Michigan.
 *  All rights reserved.
 *
 *  mod.c
 */

#ifndef lint 
static char copyright[] = "@(#) Copyright (c) 1990 Regents of the University of Michigan.\nAll rights reserved.\n";
#endif

#include <stdio.h>
#include "dixie.h"
#include <string.h>
#include <ctype.h>

extern int	dxi_limit;
extern char	*dxi_buffer;
extern int	dxi_errno;
extern int	dxi_debug;
extern int	dxi_bound;

extern int dxi_send( char type, char *buf, int buflen, char *answer, int anslen, int scope );

/*
 * dxi_modify - do a dixie (x.500) modify operation.  Who contains the DN
 * of the entry to modify, what contains null-terminated array of char *
 * changes to make, each of which has one of the following forms:
 *	attribute		: delete attribute
 *	attribute=value		: make value the sole value for attribute
 *	attribute+=value	: add value to attribute
 *	attribute-=value	: remove value from attribute
 * value can specify multiple values by separating them with &'s.
 *
 * Example:
 *	char	*changes[] = { "cn+=bob", "mail-=fred@bob.edu", 0 };
 *	dxi_modify( "c=us@cn=bob", changes );
 */

int dxi_modify( char *who, char **what )
{
	int	i, rc, len;
	char	*tmp;
	char	answer[ DXI_H_SIZE + 1 ];

	/* we need to be talking over TCP */
	if ( dxi_bound < 0 ) {
		dxi_errno = DXI_NOTCONN;
		return( -1 );
	}

	strcpy( dxi_buffer, who );
	len = strlen( dxi_buffer ) + 1;
	tmp = dxi_buffer + len;
	for ( i = 0; what[i] != NULL; i++ ) {
		strcpy( tmp, what[i] );
		len += strlen( what[i] ) + 1;
		tmp = dxi_buffer + len;
	}

	/* ship it */
	if ( (rc = dxi_send( DXI_WRITE,  dxi_buffer, len, answer,
	    sizeof(answer), 0 )) < 0 ) {
		dxi_errno = DXI_DOWN;
		return( rc );
	}
	dxi_errno = answer[DXI_H_RC];

	return( dxi_errno == DXI_SUCCESS ? 0 : -1 );
}
