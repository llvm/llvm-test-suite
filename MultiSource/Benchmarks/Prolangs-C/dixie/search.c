/*
 *  Copyright (c) 1990 Regents of the University of Michigan.
 *  All rights reserved.
 *
 *  search.c
 */

#ifndef lint 
static char copyright[] = "@(#) Copyright (c) 1990 Regents of the University of Michigan.\nAll rights reserved.\n";
#endif

#include <ctype.h>
#include <stdio.h>
#include "dixie.h"
#include <string.h>

extern int dxi_send( char type, char *buf, int buflen, char *answer, int anslen, int scope );

/*
 * dxi_search - do a dixie (X.500) search operation.  Parameters are
 * 	base:		text form of the DN to start the search at
 *	scope:		the search scope (see dixie.h)
 *	filter:		a string containing the filter (e.g., cn~=bob)
 *	attrlist:	list of attribute types to return for matches
 *	answer:		buffer where the result will be placed
 *
 * Example:
 *	char	*attrs[] = { "mail", "title", 0 };
 *	dxi_search( "c=us@o=university of michigan", DXI_SRCH_SUBTREE,
 *	    "cn~=bob", attrs, answerbuffer )
 */

int dxi_search( char *base, int scope, char *filter, char *attrlist[], char *answer )
{
	int	i, len, rc;
	extern char	*dxi_buffer;
	extern int	dxi_errno;
	extern int	dxi_limitiserror;

	dxi_errno = DXI_SUCCESS;

	strcpy( dxi_buffer, base );
	len = strlen( base );
	dxi_buffer[len++] = DXI_VAL_SEP;
	dxi_buffer[len] = '\0';
	strcat( dxi_buffer, filter );
	len += strlen( filter );
	if ( attrlist == NULL ) {
		dxi_buffer[len++] = '\0';
	} else {
		for ( i = 0; attrlist[i] != NULL; i++ ) {
			dxi_buffer[len++] = DXI_VAL_SEP;
			dxi_buffer[len] = '\0';
			strcat( dxi_buffer, attrlist[i] );
			len += strlen( attrlist[i] );
		}
		dxi_buffer[++len] = '\0';
	}
	for ( i = 0; i < len; i++ ) {
		if ( dxi_buffer[i] == DXI_VAL_SEP )
			dxi_buffer[i] = '\0';
	}

	/* ship it */
	if ( (rc = dxi_send( DXI_SEARCH_GEN, dxi_buffer, len, answer,
	    MAX_PKT_SIZE, scope )) < 0 ) {
		dxi_errno = DXI_DOWN;
		return( rc );
	}

	dxi_errno = answer[DXI_H_RC];
	if ( dxi_limitiserror )
		return( dxi_errno == DXI_SUCCESS || dxi_errno == DXI_NOTFOUND
		    ? 0 : -1 );
	else
		return( dxi_errno == DXI_SUCCESS || dxi_errno == DXI_SIZELIMIT
		    || dxi_errno == DXI_TIMELIMIT || dxi_errno == DXI_NOTFOUND
		    ? 0 : -1 );
}
