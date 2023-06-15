#include <stdio.h>
#include <signal.h>
#include <unistd.h>

volatile int number = 0;
volatile int bit_count = 0;

void handle_signal(int signal) {
    number = number << 1;
    if (signal == SIGUSR2) {
        number = number | 1;
    }
    bit_count++;
}

int main() {
    printf("Receiver PID: %d\n", getpid());
    printf("Enter transmitter PID: ");
    int transmitter_pid;
    scanf("%d", &transmitter_pid);

    signal(SIGUSR1, handle_signal);
    signal(SIGUSR2, handle_signal);

    while (bit_count < sizeof(int) * 8) {
        pause();
    }

    printf("Received: %d\n", number);

    return 0;
}
