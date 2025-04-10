/*
Função: Potenciais Fatoriais
Autor: Carlos Eduardo Barbosa Alves
Data:08/04/2025
*/


#include <stdio.h>

int eh_numero_armstrong(int n) {
    int original = n, soma = 0;

    while (n > 0) {
        int digito = n % 10;
        soma += digito * digito * digito;
        n /= 10;
    }

    return soma == original;
}

int main() {
    printf("Números de Armstrong entre 1 e 999:\n");

    for (int i = 1; i <= 999; i++) {
        if (eh_numero_armstrong(i)) {
            printf("%d\n", i);
        }
    }

    return 0;
}
