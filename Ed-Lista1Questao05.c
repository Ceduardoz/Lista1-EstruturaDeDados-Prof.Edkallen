/*
Função: Soma dos Fatoriais Inversos
Autor: Carlos Eduardo Barbosa Alves
Data:07/04/2025
*/


#include <stdio.h>

int fatorial(int n) {
    int resultado = 1;
    for (int i = 2; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

float soma_fatoriais_inversos(int n) {
    float soma = 0;

    for (int i = 1; i <= n; i++) {
        soma += 1.0 / fatorial(i);
    }

    return soma;
}

int main() {
    int n;

    printf("Digite um número positivo: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Por favor, digite um número maior ou igual a 1.\n");
        return 1;
    }

    float resultado = soma_fatoriais_inversos(n);
    printf("A soma dos fatoriais inversos até %d é: %.5f\n", n, resultado);

    return 0;
}
