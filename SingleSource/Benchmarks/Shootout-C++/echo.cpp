// -*- mode: c++ -*-
// $Id$
// http://www.bagley.org/~doug/shootout/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <netinet/in.h>

using namespace std;

#define DATA "Hello there sailor\n"

void myabort (char *m) { fprintf(stderr, "%s\n", m); exit(1); }
void sysabort (char *m) { perror(m); exit(1); }

int sigchld = 0;
void reaper (int sig) { sigchld = 1; }

int
server_sock () {
    int ss, optval = 1;
    struct sockaddr_in sin;
    if ((ss = socket(PF_INET, SOCK_STREAM, 0)) == -1)
	sysabort("server/socket");
    if (setsockopt(ss, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1)
	sysabort("server/setsockopt");
    memset(&sin,0,sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    sin.sin_port = 0;
    if (bind(ss, (sockaddr *)&sin, sizeof(sin)) == -1)
	sysabort("server/bind");
    listen(ss, 2);
    return(ss);
}


int
get_port (int sock) {
    struct sockaddr_in sin;
    socklen_t slen = sizeof(sin);
    if (getsockname(sock, (sockaddr *)&sin, &slen) == -1)
	sysabort("server/getsockname");
    return(sin.sin_port);
}    


int
client_sock (int port) {
    struct sockaddr_in sin;
    int sock;
    if ((sock = socket(PF_INET, SOCK_STREAM, 0)) == -1)
	sysabort("client/socket");
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    sin.sin_port = port;
    if (connect(sock, (sockaddr *)&sin, sizeof(sin)) == -1)
	sysabort("client/connect");
    return(sock);
}


void
echo_client (int n, int port) {
    int i, sock, olen, len, nwritten, nread;
    char *offset, obuf[64], ibuf[64];
    char *end = ibuf + sizeof(ibuf);

    sock = client_sock(port);
    strcpy(obuf, DATA);
    olen = strlen(obuf);
    for (i=0; i<n; i++) {
	len = olen;
	offset = obuf;
	while (len > 0) {
	    if ((nwritten = write(sock, offset, len)) == -1)
		sysabort("client/write");
	    offset += nwritten;
	    len -= nwritten;
	}
	offset = ibuf;
	while ((nread = read(sock, offset, (end - offset))) > 0) {
	    offset += nread;
	    if (*(offset-1) == '\n') break;
	}
	if (nread == -1)
	    sysabort("client/read");
	*offset = 0;
	if ((strcmp(obuf, ibuf)) != 0) {
	    char mbuf[128];
	    sprintf(mbuf, "client: \"%s\" ne \"%s\"", obuf, ibuf);
	    myabort(mbuf);
	}
    }
    close(sock);
}


void
echo_server (int n) {
    int ssock, csock, len, nwritten, total_bytes;
    pid_t pid;
    char buf[64], *offset;
    struct sockaddr_in sin;
    socklen_t slen = sizeof(sin);
    int status;

    ssock = server_sock();
    signal(SIGCHLD, reaper);
    if ((pid = fork()) == -1)
	sysabort("server/fork");
    if (pid) {
	/* parent is server */
	if ((csock = accept(ssock, (sockaddr *)&sin, &slen)) == -1)
	    sysabort("server/accept");
	total_bytes = 0;
	while ((len = read(csock, buf, sizeof(buf))) > 0) {
	    if (sigchld) myabort("server/sigchld");
	    offset = buf;
	    total_bytes += len;
	    while (len > 0) {
		if ((nwritten = write(csock, offset, len)) == -1)
		    sysabort("server/write");
		offset += nwritten;
		len -= nwritten;
	    }
	}
	if (len == -1)
	    sysabort("server/read");
	close(csock);
	fprintf(stdout, "server processed %d bytes\n", total_bytes);
    } else {
	/* child is client */
	echo_client(n, get_port(ssock));
    }
    wait(&status);
}


int
main(int argc, char *argv[]) {
    int n = ((argc == 2) ? atoi(argv[1]) : 100000);
    echo_server(n);
    return(0);
}
