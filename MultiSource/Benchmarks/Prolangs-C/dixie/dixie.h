/* dixie.h */
/*
 * Copyright (c) 1990 Regents of the University of Michigan.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of Michigan at Ann Arbor. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 */

#ifdef MACOS
#include "macos.h"
#define NOUDP		1
#define NEEDINETADDR	1
#endif

#ifdef DOS
#define NOUDP	1

typedef unsigned short us;
typedef unsigned long ul;
#define ntohs(i) ((us)( (((us)i & 0xff) << 8)  + (((us)i & 0xff00) >> 8) ))
#define ntohl(i) ((ul)( (((ul)i & 0xff) << 24) + (((ul)i & 0xff00) << 8) + \
			(((ul)i & 0xff0000) >> 8) +  \
			(((ul)i & 0xff000000) >> 24) ))
#define htons(i) ((unsigned) (((unsigned)i & 0xff00) >> 8) + \
			(((unsigned) i & 0xff) << 8))

typedef unsigned long ip_addr;
typedef unsigned long u_long;
typedef unsigned char u_char;

#include <malloc.h>
#include "proto.h"
#endif /* DOS */

#define DXI_PORT 	96

#define K		1024
#define MAX_PKT_SIZE	(30*K)
#define MAX_PKT_FRAG	(K/2)

/* dixie op codes */
#define DXI_READ		0x01
#define DXI_WRITE		0x02
#define DXI_SEARCH		0x03
#define DXI_BIND		0x04
#define DXI_SEARCH1		0x05
#define DXI_ACK			0x06
#define DXI_NACK		0x07
#define DXI_SEARCH_APPROX	0x08
#define DXI_SEARCH_EXACT	0x09
#define DXI_RESEND		0x0a
#define DXI_PING		0x0b
#define DXI_SEARCH_ISUB		0x0c
#define DXI_SEARCH_FSUB		0x0d
#define DXI_SEARCH_IFSUB	0x0e
#define DXI_SEARCH_GEN		0x0f
#define DXI_LIST		0x10
#define DXI_ADD			0x11
#define DXI_REMOVE		0x12
#define DXI_MODRDN		0x13
#define DXI_COMPARE		0x14

/* dixie search scopes */
#define DXI_SRCH_BASE		0x01
#define DXI_SRCH_ONELEVEL	0x02
#define DXI_SRCH_SUBTREE	0x03

/* dixie return values */
#define DXI_SUCCESS		0x01
#define DXI_NOTFOUND		0x02
#define DXI_ERROR		0x03
#define DXI_BADCMD		0x04
#define DXI_REFUSED		0x05
#define DXI_BADDN		0x06
#define DXI_SIZELIMIT		0x07
#define DXI_NOTCONN		0x08
#define DXI_SEQNOTFOUND		0x09
#define DXI_BAD_ATTR		0x0a
#define DXI_NEX_ATTR		0x0b
#define DXI_BAD_ATTRVAL		0x0c
#define DXI_NEX_ATTRVAL		0x0d
#define DXI_NO_RDN_MOD		0x0e
#define DXI_NAME_ERROR		0x0f
#define DXI_REFER_ERROR 	0x10
#define DXI_DSA_DOWN		0x11
#define DXI_TIMELIMIT		0x12
#define DXI_TOOBIG		0x13
#define DXI_DOWN		0x14
#define DXI_EXISTS		0x15
#define DXI_COMPAREFAILED	0x16
#define DXI_BAD_FILTER		0x17

/* for compatibility ... */
#define DXI_LIMIT	0x07

#define DXI_VAL_SEP	0x01
#define DXI_ATR_SEP	0x02
#define DXI_DNS_SEP	0x03
#define DXI_ATEND_FLAG	0x04

#define DXI_H_RC		0	/* char */
#define DXI_H_OP		0	/* char */
#define DXI_H_ID		1	/* short */
#define DXI_H_TOTLEN		3	/* long */
#define DXI_H_SEQUENCE		7	/* short */
#define DXI_H_OPTIONS		9	/* char */
#define DXI_H_VERSION 		10	/* char */
#define DXI_H_SRCH_SCOPE	11	/* char */
#define DXI_H_TIMELIMIT		12	/* short */
#define DXI_H_SIZELIMIT		14	/* short */
#define DXI_H_SIZE		16	/* unused */

#define DXI_OPT_FILEATTR		1
#define DXI_OPT_DONTDEREF		2
#define DXI_OPT_DONTSEARCHALIASES	4

#define DXI_PHOTO_G3FAX_TWODIM	0x01
#define DXI_PHOTO_JPEG		0x02

#define ID	short

#if !defined(MACOS) & !defined(DOS)
extern int bprint();

extern int dxi_init(char *host, int timeout, int retries);
extern int dxi_bind(char *who, char *passwd);
extern int dxi_udpbind(char *who, char *passwd);
extern int dxi_read(char *who, char **attrs, char *ans);
extern int dxi_list(char *who, char *ans);
extern int dxi_search(char *base, int scope, char *filter, char *attrlist[],
                      char *answer);
extern int dxi_modify(char *who, char **what);
extern int dxi_modrdn(char *who, char *newrdn);
extern int dxi_add(char *who, char **entry);
extern int dxi_remove(char *who);
extern void dxi_perror(char *s);
extern int dxi_matches(char *buf);
extern int dxi_close(void);
extern int dxi_compare(char *who, char *attr, char *value);
extern void dxi_det61(char *s);

extern char *dxi_firstentry(char *buf);
extern char *dxi_nextentry(void);
extern char *dxi_getdn(char *buf);
extern char *dxi_lastdncomp(char *dn);
extern char *dxi_firstattr(char *ent);
extern char *dxi_nextattr(char *attr);

extern char **dxi_getvalues(char *buf, char *at);

extern void dxi_valuefree(char **av);
#endif /* MACOS DOS */

extern int dxi_debug;
extern int dxi_errno;
extern int dxi_not61;
extern char dxi_options;
extern short dxi_sizelimit;
extern short dxi_timelimit;
extern char *dxi_errlist[];
#ifdef VMS
#define index(x) strchr(x)
#define rindex(x) strrchr(x)
#endif

#ifdef __svr4__
#define bzero(x,y) memset(x,0,y)
#endif
