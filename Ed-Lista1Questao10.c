/*
Função: Potenciais Fatoriais
Autor: Carlos Eduardo Barbosa Alves
Data:10/04/2025
*/


#include <stdio.h>
#include <stdlib.h>

int* fibonacci_max(int max) {
    int *fibonacci = NULL;
    int tamanho = 0;

    int a = 0, b = 1;

    while (a <= max) {

        int *temp = realloc(fibonacci, (tamanho + 1) * sizeof(int));
        if (temp == NULL) {
            free(fibonacci);
            printf("Erro de memória.\n");
            return NULL;
        }

        fibonacci = temp;
        fibonacci[tamanho] = a;
        tamanho++;

        int proximo = a + b;
        a = b;
        b = proximo;
    }

    int *temp = realloc(fibonacci, (tamanho + 1) * sizeof(int));
    if (temp == NULL) {
        free(fibonacci);
        printf("Erro de memória.\n");
        return NULL;
    }
    fibonacci = temp;
    fibonacci[tamanho] = -1;

    return fibonacci;
}

int main() {
    int max;

    printf("Digite o valor máximo para a série de Fibonacci: ");
    scanf("%d", &max);

    int *sequencia = fibonacci_max(max);
    if (sequencia == NULL) return 1;

    printf("Sequência de Fibonacci até %d:\n", max);
    for (int i = 0; sequencia[i] != -1; i++) {
        printf("%d ", sequencia[i]);
    }
    printf("\n");

    free(sequencia);
    return 0;
}
