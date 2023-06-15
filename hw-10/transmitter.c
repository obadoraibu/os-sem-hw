#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    int receiver_pid, number, bit;

    printf("Transmitter PID: %d\n", getpid());
    printf("Enter receiver PID: ");
    scanf("%d", &receiver_pid);

    printf("Send: ");
    scanf("%d", &number);

    for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
        bit = (number >> i) & 1;
        if (bit == 0) {
            kill(receiver_pid, SIGUSR1);
        } else {
            kill(receiver_pid, SIGUSR2);
        }
        usleep(100000); 
    }

    return 0;
}
