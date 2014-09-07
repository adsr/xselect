#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

#define STDIN 0

int main(int argc, char *argv[]) {
    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(STDIN, &readfds);

    /* Bail if STDIN is not a pipe */
    if (1 == isatty(STDIN)) {
        fprintf(stderr, "error: stdin appears to be a tty\n");
        exit(EXIT_FAILURE);
    }

    /* Wait for stdin */
    if (-1 == select(1, &readfds, NULL, NULL, NULL)) {
        perror("select");
        exit(EXIT_FAILURE);
    }

    /* Exec */
    if (argc < 2) {
        /* Nothing to exec */
        exit(EXIT_SUCCESS);
    }
    argv++;
    if (-1 == execvp(argv[0], argv)) {
        perror("execvp");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}
