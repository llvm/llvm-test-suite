/* $Header$
 *
 *    Copyright (c) 1989, Larry Wall
 *
 *    You may distribute under the terms of the GNU General Public License
 *    as specified in the README file that comes with the perl 3.0 kit.
 *
 * $Log$
 * Revision 1.2  2004/07/21 14:09:51  brukman
 * Add missing function declarations.
 *
 * Revision 1.1  2004/02/17 22:21:17  criswell
 * Initial commit of the perl Malloc Benchmark.  I've cheated a little by
 * generating the yacc output files and committing them directly, but it was
 * easier than disabling the Bison Voodoo that gets executed by default.
 *
 * Revision 4.0  91/03/20  01:56:48  lwall
 * 4.0 baseline.
 * 
 */

EXT int *screamfirst INIT(Null(int*));
EXT int *screamnext INIT(Null(int*));

char	*safemalloc();
char	*saferealloc();
char	*cpytill();
char	*instr();
char	*fbminstr();
char	*screaminstr();
void	fbmcompile();
char	*savestr();
void	my_setenv(char *, char *);
int	envix();
void	growstr();
char	*ninstr();
char	*rninstr();
char	*nsavestr();
FILE	*mypopen();
int	mypclose();
#ifndef HAS_MEMCPY
#ifndef HAS_BCOPY
char	*bcopy();
#endif
#ifndef HAS_BZERO
char	*bzero();
#endif
#endif
unsigned long scanoct();
unsigned long scanhex();
void fatal(char*,long,long,long,long);
void fatal(va_list);
