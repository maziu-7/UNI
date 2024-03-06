/*
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>

void Usage() {
	char buff[256];
	sprintf(buff,"Usage: ./program nprocs nelems\n");
	write(1,&buff,strlen(buff));
	exit(0);
}

void error_y_exit(char *s, int error) {
	perror(s);
	exit(error);
}
*/