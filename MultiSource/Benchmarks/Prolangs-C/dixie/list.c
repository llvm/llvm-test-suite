/*
 *  Copyright (c) 1990 Regents of the University of Michigan.
 *  All rights reserved.
 *
 *  list.c
 */

#ifndef lint 
static char copyright[] = "@(#) Copyright (c) 1990 Regents of the University of Michigan.\nAll rights reserved.\n";
#endif

#include "dixie.h"
#include <string.h>
#include <stdio.h>

/*
 * dxi_list - do a dixie (X.500) list operation.  The DN of the entry to
 * list is supplied (in text form).  The result of the list
 * is passed back in ans, which should point to enough space.
 *
 * Example:
 *	dxi_list( "c=us@cn=bob", answerbuffer )
 */

extern int dxi_send( char type, char *buf, int buflen, char *answer, int anslen, int scope );

int dxi_list( char *who, char *ans )
{
	int		len;
	extern char	*dxi_buffer;
	extern int	dxi_errno;
	extern int	dxi_limitiserror;

	strcpy( dxi_buffer, who );
	len = strlen( who ) + 1;

	/* and now ship it */
	if ( dxi_send( DXI_LIST, dxi_buffer, len, ans, MAX_PKT_SIZE, 0 )
	    == -1 ) {
		dxi_errno = DXI_DOWN;
		return( -1 );
	}
	dxi_errno = ans[DXI_H_RC];

	if ( dxi_limitiserror )
		return( dxi_errno == DXI_SUCCESS ? 0 : -1 );
	else
		return( dxi_errno == DXI_SUCCESS || dxi_errno == DXI_SIZELIMIT
		    || dxi_errno == DXI_TIMELIMIT ? 0 : -1 );
}
