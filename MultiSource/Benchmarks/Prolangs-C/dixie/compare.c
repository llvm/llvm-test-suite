/*
 *  Copyright (c) 1990 Regents of the University of Michigan.
 *  All rights reserved.
 *
 *  compare.c
 */

#ifndef lint 
static char copyright[] = "@(#) Copyright (c) 1990 Regents of the University of Michigan.\nAll rights reserved.\n";
#endif

#include <stdio.h>
#include "dixie.h"
#include <string.h>

extern int dxi_send( char type, char *buf, int buflen, char *answer, int anslen, int scope );

/*
 * dxi_compare - do a dixie (X.500) compare operation.  The DN of the entry
 * is supplied (in text form), along with the attribute and value to compare
 * (in attr and value).
 *
 * Example:
 *	dxi_compare( "c=us@cn=bob", "userPassword", "foo")
 */

int dxi_compare( char *who, char *attr, char *value)
{
	int		len;
	extern char	*dxi_buffer;
	extern int	dxi_errno;
	char	ans[ DXI_H_SIZE + 1 ];
	char *p;

	strcpy( dxi_buffer, who );
	len = strlen( who );
	p = &dxi_buffer[len];
	p++;
	len++;
	strcpy(p,attr);
	p += strlen(attr) + 1;
	len += strlen(attr) + 1;
	strcpy(p,value);
	len += strlen(value) + 1;
	/* and now ship it */

	if ( dxi_send( DXI_COMPARE, dxi_buffer, len, ans, sizeof(ans), 0 )
	    == -1 ) {
		dxi_errno = DXI_DOWN;
		return( -1 );
	}
	dxi_errno = ans[DXI_H_RC];

	return( dxi_errno == DXI_SUCCESS ? 0 : 
	    dxi_errno == DXI_COMPAREFAILED ? 1 : -1 );
}
