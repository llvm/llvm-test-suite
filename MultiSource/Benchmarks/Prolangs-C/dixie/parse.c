/*
 *  Copyright (c) 1990 Regents of the University of Michigan.
 *  All rights reserved.
 *
 *  show.c
 */

#ifndef lint 
static char copyright[] = "@(#) Copyright (c) 1990 Regents of the University of Michigan.\nAll rights reserved.\n";
#endif

#include "dixie.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#if !defined(__STDC__) && !defined(VMS)
#include <memory.h>
#endif
#if !defined(MACOS) & !defined(NeXT) & !defined(DOS)
#include <sys/types.h>
#include <netinet/in.h>
#endif /* MACOS NeXT DOS */

extern int dxi_send( char type, char *buf, int buflen, char *answer, int anslen, int scope);

static char	*dxi_current;
static char	dxi_attr[ 64 ];

#ifdef VMS

long strncasecmp( char * string1, char * string2, unsigned long maxlen )
{
    char copystring1[256], copystring2[256];
    long i;

    strncpy (copystring1, string1, 256);
    strncpy (copystring2, string2, 256);
    
    i = 0;
    while ((i < 256) && (copystring1[i] != '\0'))
    {
        toupper (copystring1[i]);
    i++;
    };
    i = 0;
    while ((i < 256) && (copystring2[i] != '\0'))
    {
        toupper (copystring2[i]);
    i++;
    };
    return (strncmp (copystring1, copystring2, maxlen));
}

long strcasecmp( char * string1, char * string2)
{
  return (strncasecmp (string1, string2, 256));
}

#endif

char *dxi_findtype( char *buf, char *at )
{
	char	*p, *s, save;

	s = p = buf;
	while ( 1 ) {
		while ( *s != DXI_ATR_SEP && *s != DXI_DNS_SEP && *s != '\0' )
			s++;
		if ( *s == '\0' || *s == DXI_DNS_SEP )
			break;
		s++;

		p = s;
		while ( *s != DXI_VAL_SEP && *s != DXI_ATR_SEP
		    && *s != DXI_DNS_SEP && *s != '\0' )
			s++;
		if ( *s == '\0' )
			break;

		save = *s;
		*s = '\0';

		if ( strcasecmp( at, p ) == 0 ) {
			*s = save;
			return( p );
		}

		*s = save;
	}

	return( NULL );
}

char *dxi_firstattr( char *ent )
{
	char		*p, *a;

	for ( p = ent; *p != DXI_ATR_SEP && *p != '\0'; p++ )
		;	/* NULL */

	if ( *p == '\0' || *++p == DXI_DNS_SEP || *p == '\0' )
		return( NULL );

	a = dxi_attr;
	while ( *p != DXI_VAL_SEP && *p != DXI_ATR_SEP && *p != DXI_DNS_SEP )
		*a++ = *p++;
	*a = '\0';

	return( dxi_attr );
}

char *dxi_nextattr( char *attr )
{
	char	*p, *a;

	if ( (p = dxi_findtype( dxi_current, attr )) == NULL )
		return( NULL );

	while ( *p != DXI_ATR_SEP && *p != DXI_DNS_SEP && *p != '\0' )
		p++;

	if ( *p == '\0' || *p++ == DXI_DNS_SEP )
		return( NULL );

	a = dxi_attr;
	while ( *p != DXI_VAL_SEP && *p != DXI_ATR_SEP && *p != DXI_DNS_SEP )
		*a++ = *p++;
	*a = '\0';

	return( dxi_attr );
}

int dxi_matches( char *buf )
{
	short	matches;

	if ( buf[DXI_H_RC] != DXI_SUCCESS && buf[DXI_H_RC] != DXI_SIZELIMIT
	    && buf[DXI_H_RC] != DXI_TIMELIMIT )
		return( 0 );	/* no matches */
	else if ( buf[DXI_H_SIZE + 1] != DXI_DNS_SEP && buf[DXI_H_SIZE + 2]
	    != DXI_DNS_SEP )
		if ( buf[DXI_H_SIZE + 2] == 0 )
			return( 0 );	/* no matches */
		else
			return( 1 );	/* read result - one match */
	else if ( buf[DXI_H_VERSION] == 0 )
		return( buf[DXI_H_SIZE] );	/* search result */
	else {
		short	tmp;

		(void) memcpy( (char *) &tmp, &buf[DXI_H_SIZE], sizeof(short) );
		matches = ntohs( tmp );
		return( matches );
	}
}

int dxi_countvalues( char *avl )
{
	int	num = 0;

	while ( *avl && *avl != DXI_ATR_SEP && *avl != DXI_DNS_SEP )
		if ( *avl++ == DXI_VAL_SEP ) num++;

	return( num );
}

char *dxi_firstentry( char *buf )
{
	if ( buf[DXI_H_RC] != DXI_SUCCESS && buf[DXI_H_RC] != DXI_LIMIT
	    && buf[DXI_H_RC] != DXI_TIMELIMIT
	    || buf[DXI_H_SIZE + 2] == 0 )
		return( 0 );	/* no entries */
	if ( buf[DXI_H_SIZE + 2] == DXI_DNS_SEP )
		return( dxi_current = &buf[DXI_H_SIZE + 3] );
	else if ( buf[DXI_H_SIZE + 1] == DXI_DNS_SEP )
		return( dxi_current = &buf[DXI_H_SIZE + 2] );
	else
		return( dxi_current = &buf[DXI_H_SIZE] );
}

char *dxi_getreadentry( char *buf )
{
	if ( buf[DXI_H_RC] != DXI_SUCCESS && buf[DXI_H_RC] != DXI_LIMIT
	    && buf[DXI_H_RC] != DXI_TIMELIMIT
	    || buf[DXI_H_SIZE + 2] == 0 )
		return( 0 );	/* no entries */
	if ( buf[DXI_H_SIZE + 2] == DXI_DNS_SEP )
		return( &buf[DXI_H_SIZE + 3] );
	else if ( buf[DXI_H_SIZE + 1] == DXI_DNS_SEP )
		return( &buf[DXI_H_SIZE + 2] );
	else
		return( &buf[DXI_H_SIZE] );
}

char *dxi_nextentry(void)
{
	dxi_current = strchr( dxi_current, DXI_DNS_SEP );
	return( dxi_current ? ++dxi_current : NULL );
}

char *dxi_getdn( char *buf )
{
	char	*result, *p, save;

	for ( p = buf; *p && *p != DXI_ATR_SEP && *p != DXI_DNS_SEP; p++ )
		;	/* NULL */

	save = *p;
	*p = '\0';
	result = (char *) strdup( buf );
	*p = save;

	return( result );
}

char **dxi_getvalues( char *buf, char *at )
{
	char	*p, *s, save;
	char	**av;
	int	num, i;

	if ( (p = dxi_findtype( buf, at )) == NULL )
		return( (char **) 0 );

	if ( (num = dxi_countvalues( p )) == 0 )
		return( (char **) 0 );

	if ( (av = (char **) calloc( num + 1, sizeof(char *) )) == (char **) 0 )
		return( (char **) 0 );

	p = strchr( p, DXI_VAL_SEP ) + 1;
	for ( i = 0; i < num; i++ ) {
		s = p;
		while ( *s && *s != DXI_VAL_SEP && *s != DXI_ATR_SEP
		    && *s != DXI_DNS_SEP )
			s++;
		save = *s;
		*s = '\0';

		if ( *p == DXI_ATEND_FLAG ) {
			char		*last;
			unsigned long	len;

			/* 
			 * find the end of the packet - what we want should
			 * be just after that
			 */

			last = strchr( s + 1, '\0' );
			last++;

			(void) memcpy( (char *) &len, last, sizeof(len) );

			if ( (av[i] = (char *) malloc( len + 4 )) == NULL )
				return( (char **) 0 );

			(void) memcpy( av[i], last, len + 4 );
		} else {
			av[i] = (char *) strdup( p );
			if ( dxi_not61 )
				dxi_det61( av[i] );
		}

		*s = save;
		p = s + 1;
	}
	av[num] = NULL;

	return( av );
}

void dxi_valuefree( char **av )
{
	int	i;

	if ( av == (char **) 0 )
		return;

	for ( i = 0; av[i] != NULL; i++ )
		free( av[i] );
	free( av );
}

char *dxi_lastdncomp( char *dn )
{
	char	*p;

	if ( (p = strrchr( dn, '@' )) == NULL )
		p = dn;

	while ( *p && *p != '=' ) p++;

	return( ++p );
}

#ifdef DOS
/* for some reason, this wasn't working in dos, so we write our own! */
static char *mystrcat( char *a, char *b )
{
	char	*save = a;

	while ( *a )
		a++;

	while ( *a++ = *b++ )
		;	/* NULL */

	return( save );
}
#endif

/*
 * dxi_dn2ufn returns the ufn representation of dn.  dn may be trashed.
 */

char *dxi_dn2ufn( char *dn )
{
	char		*p;
	int		first;
	static char	buf[512];

	buf[0] = '\0';
	first = 1;
	while ( (p = strrchr( dn, '=' )) != NULL ) {
		if ( first == 0 )
#ifdef DOS
			mystrcat( buf, ", " );
#else
			strcat( buf, ", " );
#endif
		else
			first = 0;

#ifdef DOS
		mystrcat( buf, p + 1 );
#else
		strcat( buf, p + 1 );
#endif

		if ( (p = strrchr( dn, '@' )) != NULL )
			*p = '\0';
		else
			break;
	}

	return( buf );
}

#define T61	"{T.61}"
#define T61LEN	6

void dxi_det61( char *s )
{
	char	*next = s;
	int	c, hex;

	while ( *s ) {
		switch ( *s ) {
		case '{' :
			if ( strncasecmp( s, T61, T61LEN) == 0 ) {
				s += T61LEN;
			} else {
				*next++ = *s++;
			}
			break;

		case '\\':
			c = *(s + 1);
			if ( c == '\n' ) {
				s++;
				*next++ = *s++;
				break;
			      }
			if ( isdigit( c ) )
				hex = c - '0';
			else if ( isupper( c ) )
				hex = c - 'A' + 10;
			else
				hex = c - 'a' + 10;
			hex <<= 4;
			c = *(s + 2);
			if ( isdigit( c) )
				hex += c - '0';
			else if ( isupper( c ) )
				hex += c - 'A' + 10;
			else
				hex += c - 'a' + 10;

			*next++ = hex;
			s += 3;
			break;

		default:
			*next++ = *s++;
			break;
		}
	}
	*next = '\0';
}
