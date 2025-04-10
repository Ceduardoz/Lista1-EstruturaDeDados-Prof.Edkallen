/*
Função: Potenciais Fatoriais
Autor: Carlos Eduardo Barbosa Alves
Data:10/04/2025
*/


#include <stdio.h>

int eh_numero_perfeito(int n) {
    int soma = 0;

    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            soma += i;
        }
    }

    return soma == n;
}

int main() {
    printf("Números perfeitos entre 1 e 100000:\n");

    for (int i = 1; i <= 100000; i++) {
        if (eh_numero_perfeito(i)) {
            printf("%d\n", i);
        }
    }

    return 0;
}
