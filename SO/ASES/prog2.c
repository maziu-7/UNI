#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>
#include <aio.h>
#include <bits/types/sigset_t.h>

void Usage() {
	char buff[256];
	sprintf(buff, "Usage: ./prog1 N S\n");
	write(1, buff, strlen(buff));
	exit(0);
}

void error_y_exit(char *s, int error) {
	perror(s);
	exit(error);
}

void func() {}

int main(int argc, char* argv[]) {

    if (argc != 3) Usage();

    char buff[256];
    sprintf(buff, "Hola, soy el padre %d\n", getpid());
    write(1, buff, strlen(buff));

    int N = atoi(argv[1]);
    int S = atoi(argv[2]);

    struct sigaction t;
    t.sa_handler = func;
    sigemptyset(&t.sa_mask);
    t.sa_flags = 0;
    sigaction(SIGALRM, &t, NULL);

    for (int i = 0; i < N; ++i) {
        int p = fork();
        if (p == 0) {
            sprintf(buff, "Soy el hijo %d\n", getpid());
            write(1, buff, strlen(buff));

            alarm(S);

            sigset_t m;
            sigfillset(&m);
            sigdelset(&m, SIGALRM);
            sigsuspend(&m);
            
            sprintf(buff, "Hijo %d: Adiós!\n", getpid());
            write(1, buff, strlen(buff));
            exit(0);
        }
        else if (p == -1) error_y_exit("Fork call error", 1);
    }
    while(waitpid(-1, NULL, 0) > 0);
    sprintf(buff, "FIN!\n");
    write(1, buff, strlen(buff));
}