#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "dixie.h"
#include <string.h>
#if !defined(__STDC__) && !defined(VMS)
#include <memory.h>
#endif
#if defined(MACOS) || defined(DOS)
#include <memory.h>
#include <stdlib.h>
#endif

extern char *dxi_dn2ufn( char *dn );

static char *getlinex( char *line, int len, FILE *s, char *prompt )
{
	printf(prompt);

	if ( fgets( line, len, s ) == NULL ) {
		dxi_close();
		exit( 0 );
	}

	line[ strlen( line ) - 1 ] = '\0';

	return( line );
}

static void print_listpacket( char *ans )
{
	char	*entry, *dn;
	int	i;

	if ( (i = dxi_matches( ans )) != -1 )
		printf("%d matches:\n", i);

	for ( entry = dxi_firstentry( ans ); entry != NULL;
	    entry = dxi_nextentry() ) {
		dn = dxi_getdn( entry );
		printf("\t%s\n", dn);
		printf("\t(UFN) %s\n", dxi_dn2ufn( dn ));
		free( dn );
	}
}

static void print_packet( char *ans )
{
	char	*entry, *at, *dn;
	char	**av;
	int	i;

	/*
	 * step through each attr type in attrs and print the
	 * corresponding values
	 */

	if ( (i = dxi_matches( ans )) != -1 )
		printf("%d matches:\n", i);

	for ( entry = dxi_firstentry( ans ); entry != NULL;
	    entry = dxi_nextentry() ) {
		dn = dxi_getdn( entry );
		printf("\n%s\n", dn);
		printf("(UFN) %s\n", dxi_dn2ufn( dn ));
		free( dn );

		for ( at = dxi_firstattr( entry ); at != NULL;
		    at = dxi_nextattr( at ) ) {
			printf("\t%s\n", at);
			av = dxi_getvalues( entry, at );
			if ( av == (char **) 0 )
				printf("\t\t*** NO VALUES ***\n");
			else {
				if ( strcmp( at, "photo" ) == 0 ) {
					unsigned long	len;

					(void) memcpy( (char *) &len, av[0],
					    sizeof(len) );
					printf("\t\t%d bytes of %s photo\n",
					    len, av[0][4] == DXI_PHOTO_JPEG ?
					    "JPEG" : "G3Fax");
				} else {
					for ( i = 0; av[i] != NULL; i++ ) {
						printf("\t\t%s\n", av[i]);
					}
				}
				dxi_valuefree( av );
			}
		}
	}
}

static char **get_list( char *prompt )
{
	static char	buf[256];
	int		num;
	char		**result;

	num = 0;
	result = (char **) 0;
	while ( 1 ) {
		getlinex( buf, sizeof(buf), stdin, prompt );

		if ( *buf == '\0' )
			break;

		if ( result == (char **) 0 )
			result = (char **) malloc( sizeof(char *) );
		else
			result = (char **) realloc( result,
			    sizeof(char *) * (num + 1) );

		result[num++] = (char *) strdup( buf );
	}
	if ( result == (char **) 0 )
		return( NULL );
	result = (char **) realloc( result, sizeof(char *) * (num + 1) );
	result[num] = NULL;

	return( result );
}

int main( int argc, char **argv )
{
	char	*ans;
	int	alen;
	char	line[256], command, *lp;
	char	searchattr[80], attr[180], who[256];
	char	new1[80], value[256];
	int	genscope;
	char	**entry;
	extern int	dxi_debug;

	if (( ans = (char *) malloc( MAX_PKT_SIZE )) == NULL ) {
		perror( "malloc" );
		exit(1);
	}
#if defined(MACOS) || defined(DOS)
	getlinex( line, sizeof(line), stdin, "dixie server? " );
	if ( dxi_init( line, 2, 4 ) != 0 ) {
#else
	if ( dxi_init( argc > 1 ? argv[1] : NULL, 2, 4 ) != 0 ) {
#endif
		perror( "dxi_init" );
		exit(1);
	}

	while ( getlinex( line, sizeof(line), stdin, "\ncommand? " ) != NULL ) {
		command = line[0];
		for ( lp = line; *lp && !isspace(*lp); lp++ )
			;	/* NULL */
		
		alen = 0;
		switch ( command ) {
		case 'l':	/* list */
			getlinex( who, sizeof(who), stdin, "dn? " );

			alen = dxi_list( who, ans );
			break;

		case 'r':	/* read */
			getlinex( who, sizeof(who), stdin, "dn? " );
			entry = get_list( "attr to return? " );

			alen = dxi_read( who, entry, ans );
			break;

		case 's':	/* search */
			getlinex( who, sizeof(who), stdin, "searchbase? " );
			getlinex( line, sizeof(line), stdin,
			    "scope (1=Base, 2=One Level, 3=Subtree)?" );
			genscope = atoi( line );
			getlinex( searchattr, sizeof(searchattr), stdin,
			    "search filter (e.g. sn=jones)? " );
			entry = get_list( "attr to return? " );

			alen = dxi_search( who, genscope, searchattr, entry,
			    ans );
			break;

		case 'm':	/* modify */
			getlinex( who, sizeof(who), stdin, "dn? " );
			entry = get_list( "modify list? " );

			alen = dxi_modify( who, entry );

			dxi_valuefree( entry );
			break;

		case 'a':	/* add */
			getlinex( who, sizeof(who), stdin, "dn? " );
			entry = get_list( "attr to return? " );

			alen = dxi_add( who, entry );

			dxi_valuefree( entry );
			break;

		case 'v':	/* remove */
			getlinex( who, sizeof(who), stdin, "dn? " );

			alen = dxi_remove( who );
			break;

		case 'c':	/* modify rdn */
			getlinex( who, sizeof(who), stdin, "olddn? " );
			getlinex( new1, sizeof(new1), stdin, "newrdn? " );

			alen = dxi_modrdn( who, new1 );
			break;

		case 'p':	/* compare */
			getlinex( who, sizeof(who), stdin, "dn? " );
			getlinex( attr, sizeof(attr), stdin, "attr? " );
			getlinex( value, sizeof(value), stdin, "value? " );
			if ( (alen = dxi_compare( who, attr, value )) == -1 )
				break;
			printf("%d\n", alen);
			continue;

		case 'u':	/* udp bind */
			getlinex( who, sizeof(who), stdin, "dn? " );
			getlinex( line, sizeof(line), stdin, "password? " );

			alen = dxi_udpbind( who, line );
			break;

		case 'b':	/* tcp bind */
			getlinex( who, sizeof(who), stdin, "dn? " );
			if ( who[0] != '\0' )
				getlinex( line, sizeof(line), stdin,
				    "password? " );
			else
				line[0] = '\0';

			alen = dxi_bind( who, line );
			break;

		case 'd':	/* turn on debugging */
			getlinex( line, sizeof(line), stdin, "debug level? " );
			dxi_debug = atoi( line );
			continue;
			break;

		case 'o':	/* set dxi_options, size & time limits */
			getlinex( line, sizeof(line), stdin,
			   "options (not61 or s# or t# or #)? " );
			if ( line[0] == 's' )
				dxi_sizelimit = atoi( line + 1 );
			else if ( line[0] == 't' )
				dxi_timelimit = atoi( line + 1 );
			else if ( line[0] == 'n' )
				dxi_not61 = 1;
			else
				dxi_options = atoi( line );
			continue;
			break;

		case 'q':	/* quit */
			dxi_close();
			exit( 0 );
			break;

		case '?':	/* help */
			printf("Commands: [r]ead, [s]earch, [m]odify, ");
			printf("[b]ind, [l]ist, [q]uit, [d]ebug, [?]help\n");
			printf("          [a]dd, remo[v]e, [c]modifyrdn, ");
			printf("[u]dpbind [o]ptions [p]compare\n");
			continue;
			break;

		default:
			printf("Invalid command.  Type ? for help.\n");
			continue;
			break;
		}

		line[ 0 ] = command;
		line[ 1 ] = '\0';
		
		if ( alen < 0 ) {	/* alen < 0 is an error */
			dxi_perror( line );
		} else {		/* alen == 0 might be OK */
			if ( dxi_errno != DXI_SUCCESS )
				dxi_perror( line );

			if ( command == 's' || command == 'r' )
				print_packet( ans );
			else if ( command == 'l' )
				print_listpacket( ans );
		} 
	}

	dxi_close();
	return 0;
}
