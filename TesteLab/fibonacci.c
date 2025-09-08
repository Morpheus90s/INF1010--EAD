#include <stdio.h>
#include <time.h>

void fibonacci(int n) {
    int a = 0, b = 1, auxiliar;

    for (int i = 0; i < n; i++) {
        if (i <= 1) {
            auxiliar = i;
        } else {
            auxiliar = a + b;
            a = b;
            b = auxiliar;
        }

        for (volatile int j = 0; j < 100000; j++) {
          
        }

    }
}

int recursao_fibonacci(int n) {
    
    for (volatile int j = 0; j < 10000; j++) {
        // faz nada
    }

    if (n <= 1) {
        return n;
    } else {
        return recursao_fibonacci(n - 1) + recursao_fibonacci(n - 2);
    }
}

int main(void) {
    int n;

    clock_t inicio, fim, ini_rec, fim_rec;
    double tempo_decorrido, tempo_decorrido_rec;

    printf("Digite um número: ");
    scanf("%d", &n);

    printf("\nVersão Iterativa:\n");

    inicio = clock();
    fibonacci(n);
    fim = clock();

    tempo_decorrido = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo Decorrido: %f segundos\n", tempo_decorrido);

    printf("\nVersão Recursiva:\n");

    ini_rec = clock();
    for (int i = 0; i < n; i++) {
        recursao_fibonacci(i);
       
    }
    fim_rec = clock();

    tempo_decorrido_rec = ((double)(fim_rec - ini_rec)) / CLOCKS_PER_SEC;
    printf("Tempo Decorrido Recursão: %f segundos\n", tempo_decorrido_rec);

    return 0;
}

