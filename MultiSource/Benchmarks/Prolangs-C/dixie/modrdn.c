/*
 *  Copyright (c) 1990 Regents of the University of Michigan.
 *  All rights reserved.
 *
 *  modrdn.c
 */

#ifndef lint 
static char copyright[] = "@(#) Copyright (c) 1990 Regents of the University of Michigan.\nAll rights reserved.\n";
#endif

#include "dixie.h"
#include <string.h>
#include <stdio.h>

/*
 * dxi_modrdn - do a dixie (X.500) modrdn operation.  The DN of the entry to
 * modrdn is supplied (in text form), along with the new RDN.
 *
 * Example:
 *	dxi_modrdn( "c=us@cn=bob", "cn=fred" )
 */

extern int dxi_send( char type, char *buf, int buflen, char *answer, int anslen, int
		     scope );

int dxi_modrdn( char *who, char *newrdn )
{
	int		len;
	char		*tmp, ans[ DXI_H_SIZE + 1 ];
	extern char	*dxi_buffer;
	extern int	dxi_errno;

	strcpy( dxi_buffer, who );
	len = strlen( who ) + 1;
	tmp = dxi_buffer + len;
	strcpy( tmp, newrdn );
	len += strlen( newrdn ) + 1;

	/* ship it */
	if ( dxi_send( DXI_MODRDN, dxi_buffer, len, ans, sizeof(ans), 0 )
	    == -1 ) {
		dxi_errno = DXI_DOWN;
		return( -1 );
	}
	dxi_errno = ans[DXI_H_RC];

	return( dxi_errno == DXI_SUCCESS ? 0 : -1 );
}
