#include <stdio.h>
#include <unistd.h>  // For fork()

int main() {
    int i;
    pid_t cpid = fork();  // Create a new process

    if (cpid > 0) {
        // This block is executed by the parent process
        for (i = 0; i < 10; i++) {
            printf("Parent: %d\n", i);
            // sleep(1);  // Uncomment if you want to add a 1-second delay
        }
    } else if (cpid == 0) {
        // This block is executed by the child process
        for (i = 0; i > -10; i--) {
            printf("Child: %d\n", i);
            // sleep(1);  // Uncomment if you want to add a 1-second delay
        }
    } else {
        // fork() failed
        printf("Fork failed!\n");
        return 1;
    }

    return 0;
}
