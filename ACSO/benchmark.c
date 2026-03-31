#include <stdio.h>
#include <time.h>

/* 
instruções para executar o teste:
compilar com o comando 'gcc -O0 benchmark.c -o benchmark' para evitar que o compilador otimize o código
sugestão de número para teste: 45
*/

// usando uma função recursiva para gerar carga de trabalho
unsigned long long fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(void) {
    
    // recebendo uma entrada que vai determinar a escala do teste
    int num;
    scanf("%d", &num);

    clock_t tempo_inicial = clock(); // ínicio do teste

    unsigned long long resultado = fibonacci(num);

    double tempo_passado = (double)(clock() - tempo_inicial) / CLOCKS_PER_SEC; // fim do teste

    // relatório final
    printf("Programa executado em %f segundos\n", tempo_passado);
    printf("Resultado de Fibonacci(%d): %llu\n", num, resultado);

    return 0;
}
