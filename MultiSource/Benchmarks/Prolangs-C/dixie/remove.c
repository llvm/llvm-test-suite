/*
 *  Copyright (c) 1990 Regents of the University of Michigan.
 *  All rights reserved.
 *
 *  remove.c
 */

#ifndef lint 
static char copyright[] = "@(#) Copyright (c) 1990 Regents of the University of Michigan.\nAll rights reserved.\n";
#endif

#include <stdio.h>
#include "dixie.h"
#include <string.h>

extern int dxi_send( char type, char *buf, int buflen, char *answer, int anslen, int scope );

/*
 * dxi_remove - do a dixie (X.500) remove operation.  The DN of the entry to
 * remove is supplied (in text form).
 *
 * Example:
 *	dxi_remove( "c=us@cn=bob" )
 */

int dxi_remove( char *who )
{
	int		len;
	char		ans[ DXI_H_SIZE + 1 ];
	extern char	*dxi_buffer;
	extern int	dxi_errno;

	strcpy( dxi_buffer, who );
	len = strlen( dxi_buffer ) + 1;

	/* ship it */
	if ( dxi_send( DXI_REMOVE, dxi_buffer, len, ans, sizeof(ans), 0 )
	    == -1 ) {
		dxi_errno = DXI_DOWN;
		return( -1 );
	}
	dxi_errno = ans[DXI_H_RC];

	return( dxi_errno == DXI_SUCCESS ? 0 : -1 );
}
