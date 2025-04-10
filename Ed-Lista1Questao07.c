/*
Função: Potenciais Fatoriais
Autor: Carlos Eduardo Barbosa Alves
Data:08/04/2025

*/


#include <stdio.h>
#include <stdlib.h>

int soma_quadrados_dos_digitos(int n) {
    int soma = 0;
    while (n > 0) {
        int digito = n % 10;
        soma += digito * digito;
        n /= 10;
    }
    return soma;
}

int eh_numero_feliz(int n) {
    int visitados[1000] = {0};

    while (n != 1 && !visitados[n]) {
        visitados[n] = 1;
        n = soma_quadrados_dos_digitos(n);
    }

    return n == 1;
}

int main() {
    int n;

    printf("Digite um número: ");
    scanf("%d", &n);

    if (eh_numero_feliz(n)) {
        printf("%d é um número feliz!\n", n);
    } else {
        printf("%d não é um número feliz.\n", n);
    }

    return 0;
}
