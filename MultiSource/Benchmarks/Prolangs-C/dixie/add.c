/*
 *  Copyright (c) 1990 Regents of the University of Michigan.
 *  All rights reserved.
 *
 *  add.c
 */

#ifndef lint 
static char copyright[] = "@(#) Copyright (c) 1990 Regents of the University of Michigan.\nAll rights reserved.\n";
#endif

#include <stdio.h>
#include "dixie.h"
#include <string.h>

extern int dxi_send( char type, char *buf, int buflen, char *answer, int
                     anslen, int scope );

/*
 * dxi_add - do a dixie (X.500) add operation.  The DN of the entry to
 * add is supplied (in text form) in who.  The attributes that the new
 * entry will have are supplied in the array of char *'s entry.
 *
 * Example:
 *	dxi_add( "c=us@cn=bob", entry )
 */

int dxi_add(char *who, char **entry )
{
	int		i, len;
	char		*tmp;
	char		ans[ DXI_H_SIZE + 1 ];
	extern char	*dxi_buffer;
	extern int	dxi_errno;

	strcpy( dxi_buffer, who );
	len = strlen( dxi_buffer ) + 1;
	tmp = dxi_buffer + len;
	for ( i = 0; entry[i] != NULL; i++ ) {
		strcpy( tmp, entry[i] );
		len += strlen( entry[i] ) + 1;
		tmp = dxi_buffer + len;
	}

	/* and now ship it */
	if ( (i = dxi_send( DXI_ADD, dxi_buffer, len, ans, sizeof(ans), 0 ))
	    == -1 ) {
		dxi_errno = DXI_DOWN;
		return( -1 );
	}
	dxi_errno = ans[DXI_H_RC];

	return( dxi_errno == DXI_SUCCESS ? 0 : -1 );
}
