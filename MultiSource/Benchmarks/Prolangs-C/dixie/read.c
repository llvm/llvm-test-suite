/*
 *  Copyright (c) 1990 Regents of the University of Michigan.
 *  All rights reserved.
 *
 *  show.c
 */

#ifndef lint 
static char copyright[] = "@(#) Copyright (c) 1990 Regents of the University of Michigan.\nAll rights reserved.\n";
#endif

#include <stdio.h>
#include "dixie.h"
#include <string.h>

extern int dxi_send( char type, char *buf, int buflen, char *answer, int anslen, int scope );


/*
 * dxi_read - do a dixie (X.500) read operation.  The DN of the entry to
 * read is supplied (in text form), along with the attributes to read
 * (in attrs).  Attrs is a null-terminated array of attribute types to
 * be returned, NULL if all attrs are wanted.  The result of the read
 * is passed back in ans, which should point to enough space.
 *
 * Example:
 *	char	*attrs[] = { "cn", "sn", "mail", 0 };
 *	dxi_read( "c=us@cn=bob", attrs, answerbuffer )
 */

int dxi_read( char *who, char **attrs, char *ans )
{
	int		i, len;
	extern char	*dxi_buffer;
	extern int	dxi_errno;

	if ( attrs == NULL ) {
		strcpy( dxi_buffer, who );
		len = strlen( who );
		dxi_buffer[len++] = '\0';
		dxi_buffer[len++] = '\0';
	} else {
		strcpy( dxi_buffer, who );
		len = strlen( who );
		for ( i = 0; attrs[i] != NULL; i++ ) {
			dxi_buffer[len++] = DXI_VAL_SEP;
			dxi_buffer[len] = '\0';
			strcat( dxi_buffer, attrs[i] );
			len += strlen( attrs[i] );
		}
		for ( i = 0; i < len; i++ ) {
			if ( dxi_buffer[i] == DXI_VAL_SEP )
				dxi_buffer[i] = '\0';
		}
		dxi_buffer[++len] = '\0';
		len++;
	}

	/* and now ship it */
	if ( (i = dxi_send( DXI_READ, dxi_buffer, len, ans, MAX_PKT_SIZE, 0 ))
	    == -1 ) {
		dxi_errno = DXI_DOWN;
		return( -1 );
	}
	dxi_errno = ans[DXI_H_RC];

	return( dxi_errno == DXI_SUCCESS ? 0 : -1 );
}
