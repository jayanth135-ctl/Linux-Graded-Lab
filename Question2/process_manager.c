#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int main() {
    pid_t pid;
    int status;

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {
        printf("Child Process Started (PID = %d)\n", getpid());

        sleep(10);

        printf("Child Process Finished\n");
        exit(0);
    }
    else {
        printf("Parent Process (PID = %d)\n", getpid());

        sleep(3);

        printf("Child is taking too long. Sending SIGTERM...\n");
        kill(pid, SIGTERM);

        waitpid(pid, &status, 0);

        printf("Child process cleaned up. No zombie process created.\n");
    }

    return 0;
}

