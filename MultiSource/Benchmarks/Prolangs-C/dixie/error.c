#include <stdio.h>
#include "dixie.h"
#include <string.h>

#ifdef VMS_MULTINET
extern char *dxierrlist[20];
#else
char *dxi_errlist[] = {
	"Invalid error",			/* 0 is not valid 	*/
	"Success",				/* DXI_SUCCESS 		*/
	"No matches found",			/* DXI_NOTFOUND 	*/
	"Generic DIXIE error",			/* DXI_ERROR		*/
	"Unknown op code",			/* DXI_BADCMD		*/
	"Access denied",			/* DXI_REFUSED		*/
	"Malformed DN",				/* DXI_BADDN		*/
	"Size limit exceeded",			/* DXI_SIZELIMIT	*/
	"Not bound",				/* DXI_NOTCONN		*/
	"Fragment not found",			/* DXI_SEQNOTFOUND	*/
	"Invalid attribute type",		/* DXI_BAD_ATTR		*/
	"Attribute type not found",		/* DXI_NEX_ATTR		*/
	"Invalid attribute value",		/* DXI_BAD_VALUE	*/
	"Attribute value not found",		/* DXI_NEX_VALUE	*/
	"ModRDN not allowed",			/* DXI_NO_RDN_MOD	*/
	"Entry does not exist",			/* DXI_NAME_ERROR	*/
	"Referral error",			/* DXI_REFER_ERROR	*/
	"Can't contact DSA",			/* DXI_DSA_DOWN		*/
	"Time limit exceeded",			/* DXI_TIMELIMIT	*/
	"UDP packet too big",			/* DXI_TOOBIG		*/
	"Can't contact DIXIE server",		/* DXI_DOWN		*/
	"Attr, value, or name already exists",	/* DXI_EXISTS		*/
	"Compare failed",			/* DXI_COMPAREFAILED	*/
	"Bad search filter"			/* DXI_BAD_FILTER	*/
};
#endif /* vms_multinet */

void dxi_perror( char *s )
{
	if ( dxi_errno <= DXI_BAD_FILTER && dxi_errno >= DXI_SUCCESS ) {
		fprintf( stderr, "%s: %s\n", s, dxi_errlist[dxi_errno] );
	} else {
		fprintf( stderr, "%s: Unknown error\n", s );
	}
}
