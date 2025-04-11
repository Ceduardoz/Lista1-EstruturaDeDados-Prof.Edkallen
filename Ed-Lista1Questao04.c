/*
Função: Números Automórfico
Autor: Carlos Eduardo Barbosa Alves
Data:07/04/2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int contar_digitos(int n) {
    int contador = 0;
    while (n > 0) {
        contador++;
        n = n / 10;
    }
    return contador;
}

int eh_automorfico(int n) {
    int quadrado = n * n;
    int digitos = contar_digitos(n);
    int divisor = pow(10, digitos); 

    return (quadrado % divisor == n); 
}

int main() {
    int limite;
    int *automorficos = NULL;
    int quantidade = 0;

    printf("Digite um número: ");
    scanf("%d", &limite);

    for (int i = 2; i <= limite; i++) {
        if (eh_automorfico(i)) {
           
            int *novo = realloc(automorficos, (quantidade + 1) * sizeof(int));
            if (novo == NULL) {
                printf("Erro de memória!\n");
                free(automorficos);
                return 1;
            }
            automorficos = novo;
            automorficos[quantidade] = i;
            quantidade++;
        }
    }

    if (quantidade > 0) {
        printf("Números automórficos entre 2 e %d:\n", limite);
        for (int i = 0; i < quantidade; i++) {
            printf("%d ", automorficos[i]);
        }
        printf("\n");
    } else {
        printf("Nenhum número automórfico encontrado.\n");
    }

    free(automorficos);

    return 0;
}
