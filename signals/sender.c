#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

void send_bit(pid_t pid, char c) {
    for (int i = 7; i >= 0; i--) {
        int bit = (c >> i) & 1;
        kill(pid, bit ? SIGUSR2 : SIGUSR1);
        usleep(100); // Small delay to prevent signal merging
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <receiver_pid>\n", argv[0]);
        return 1;
    }

    int receiver_pid = atoi(argv[1]);
    char *message = "Hello";

    for (int i = 0; message[i]; i++) {
        send_bit(receiver_pid, message[i]);
    }
    send_bit(receiver_pid, '\0');  // End of message

    return 0;
}