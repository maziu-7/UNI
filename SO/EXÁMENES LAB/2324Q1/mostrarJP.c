#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <>

void Usage() {
    char buff[256];
    sprintf(buff, "Usage: ./mostrarJP PID\n");
    write(1, buff, strlen(buff));
    exit(0);
}

void error_y_exit(char* s, int e) {
    perror(s);
    exit(e);
}

int main(int argc, char* argv[]) {
    if (argc != 2)
}