#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int n, t;

    scanf("%d", &n); //número de filhos
    scanf("%d", &t);//tempo para dormir

    for(int i = 0; i < n; i++)
    {
        pid_t pid = fork(); //fork retorna o pid do filho criado 

        if(pid < 0) //erro
        {
            printf("Erro ao criar filho\n");
            exit(1);
        }

        if(pid == 0) //se filho
        {
            printf("FILHO: PID=%d | PID DO SEU PAI: PPID=%d\n",
                   getpid(),
                   getppid());

            sleep(t);

            printf("FILHO %d terminou\n",
                   getpid());

            exit(0); //filho deve terminar
        }
        else //se pai
        {
            printf("PAI: PID=%d criou filho PID=%d\n",
                   getpid(),
                   pid); //gerado em fork()

            wait(NULL); //pai deve esperar filho terminar
        }
    }

    return 0;
}