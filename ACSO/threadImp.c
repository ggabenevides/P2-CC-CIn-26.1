#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int main (void)
{
    int c1, c2;
    c2 = 0;
    if (c1 = fork() < 0)
    {
        printf("O fork falhou - código de erro %d\n");
        exit(0);
    }
    if (c1 == 0)
    {
        c2 = fork();
    }

    fork();

    if (c2 > 0)
    {
        fork();
    }

    printf("Eu sou o processo %d filho do processo %d e vejo c2 igual a %d\n", getpid(), getppid(), c2); 
    
    sleep(15);
}