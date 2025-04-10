/*
Função: Potenciais Fatoriais
Autor: Carlos Eduardo Barbosa Alves
Data:07/04/2025
*/

#include <stdio.h>

void soma_numeros(int num, int *soma) {
    *soma = 0;

    printf("Divisores do número %d: ", num);
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            printf("%d ", i);
            *soma += i;
        }
    }
    printf("\nSoma dos divisores de %d: %d\n", num, *soma);
}

void verifica_numeros(int a, int b) {
    int somaA, somaB;

    printf("\nAnalisando os números %d e %d...\n", a, b);
    
    soma_numeros(a, &somaA);
    soma_numeros(b, &somaB);

    if (somaA == b && somaB == a) {
        printf("Os números %d e %d são amigáveis!\n", a, b);
    } else {
        printf("Os números %d e %d NÃO são amigáveis.\n", a, b);
    }
}

int main() {
    int num1, num2;

    printf("=== Números Amigáveis ===\n");
    printf("Digite o primeiro número: ");
    scanf("%d", &num1);
    printf("Digite o segundo número: ");
    scanf("%d", &num2);

    verifica_numeros(num1, num2);

    return 0;
}
