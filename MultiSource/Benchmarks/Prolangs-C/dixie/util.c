#include "dixie.h"
#include <string.h>
#if defined(MACOS) || defined(DOS)
#include <stdlib.h>
#include <stdio.h>
#endif
#include <ctype.h>

/*
 * Print arbitrary stuff, for debugging.
 */

#ifdef DEBUG

#define BPLEN	48

void dxi_bprint( char *data, int len )
{
    static char	hexdig[] = "0123456789abcdef";
    char	out[ BPLEN ];
    int		i = 0;

    bzero( out, BPLEN );
    for ( ;; ) {
	if ( len < 1 ) {
	    printf( "\t%s\n", ( i == 0 ) ? "(end)" : out );
	    break;
	}

	if ( isgraph( (unsigned char)*data )) {
	    out[ i ] = ' ';
	    out[ i+1 ] = *data;
	} else {
	    out[ i ] = hexdig[ ( *data & 0xf0 ) >> 4 ];
	    out[ i+1 ] = hexdig[ *data & 0x0f ];
	}
	i += 2;
	len--;
	data++;

	if ( i > BPLEN - 2 ) {
	    printf( "\t%s\n", out );
	    bzero( out, BPLEN );
	    i = 0;
	    continue;
	}
	out[ i++ ] = ' ';
    }
}

#endif


#ifndef DOS

#undef SUNOS3
#ifdef SUNOS3
char *strdup( char *p )
{
	char	*r;

	r = (char *) malloc( strlen( p ) + 1 );
	strcpy( r, p );

	return( r );
}
#endif

#ifdef NEEDINETADDR
/*
 * this implementation works for decimal dot separated strings only!
 */
u_long inet_addr( char *s )
{
	int		i;
	char 	*p;
	u_long	addr;
	
	addr = 0;
	
	for ( i = 0; i < 3; ++i ) {
		if (( p = strchr( s, '.' )) == NULL ) {
			return( 0 );
		}
		*p = '\0';
		addr += atoi( s );
		addr <<= 8;
		*p = '.';
	}
	
	return( addr );
}
#endif
#endif
