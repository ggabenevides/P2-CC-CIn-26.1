#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>     // For the syscall functions.
#include <sys/wait.h>   // For wait and related macros.


int main() {
    pid_t pid = fork(); // Fork a child process.
    if (pid < 0) { // Error occurred.
        fprintf(stderr, "Fork failed!\n");
        return 1;
    } else if (pid == 0) { // Child process.
        printf("[CHILD] PID = %d\n", getpid());
        while (1)
        {
            char entrada;
            entrada = getchar();
            if (entrada == 'E' || entrada == 'e') 
            {
                printf("[CHILD] Ending normally...\n");
                exit(42);
            }
        }
        // printf("[CHILD]: I'm finished.\n");
        // return 42;
    } else { // Parent process.

        printf("[PARENT] PID = %d\n", getpid());
        printf("[PARENT] Child created with PID = %d\n", pid);
        printf("[PARENT]: Waiting on child.\n");

        int wstatus;
        wait(&wstatus);
        if (WIFEXITED(wstatus)) {
            printf("[PARENT]: Child returned with code %d.\n",
                   WEXITSTATUS(wstatus));
        }
        else if (WIFSIGNALED(wstatus)) {

            printf("\n[PARENT] Child killed by signal.\n");
            printf("[PARENT] Kill sign = %d\n",
                   WTERMSIG(wstatus));
        }
    }
    return 0;
}
