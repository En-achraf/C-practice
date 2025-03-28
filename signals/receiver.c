#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void handle_signal(int sig, siginfo_t *info, void *ucontext) {
    (void)ucontext;
    static unsigned char c = 0;
    static int bit_count = 0;

    if (sig == SIGUSR1 || sig == SIGUSR2) {
        c |= (sig == SIGUSR2) << bit_count;
        bit_count++;

        if (bit_count == 8) {
            if (c == '\0') {
                write(1, "\n", 1);
            } else {
                write(1, &c, 1);
            }
            bit_count = 0;
            c = 0;
        }
        kill(info->si_pid, SIGUSR1); // Send ACK
    }
}

int main() {
    printf("Server PID: %d\n", getpid());

    struct sigaction sa;
    sa.sa_sigaction = handle_signal;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);

    // Handle both SIGUSR1 and SIGUSR2
    if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    while (1) pause(); // Wait for signals

    return 0;
}