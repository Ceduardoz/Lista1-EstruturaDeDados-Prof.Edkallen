/*
Função: Potenciais Fatoriais
Autor: Carlos Eduardo Barbosa Alves
Data:08/04/2025
Observações: o chatGPT ajudou pois tive dificuldades de entender a expreção e inicar as funções
*/


#include <stdio.h>
#include <stdlib.h>

int mdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int eh_primo(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int mod_exp(int base, int exp, int mod) {
    int resultado = 1;
    base = base % mod;

    while (exp > 0) {
        if (exp % 2 == 1) {
            resultado = (resultado * base) % mod;
        }
        exp = exp / 2;
        base = (base * base) % mod;
    }
    return resultado;
}

int eh_numero_carmichael(int n) {
    if (eh_primo(n)) return 0;

    for (int a = 2; a < n; a++) {
        if (mdc(a, n) == 1) {
            if (mod_exp(a, n - 1, n) != 1) {
                return 0;
            }
        }
    }

    return 1; 
}

int main() {
    int limite;

    printf("Digite um número limite: ");
    scanf("%d", &limite);

    int *carmichael = NULL;
    int total = 0;

    for (int i = 2; i <= limite; i++) {
        if (eh_numero_carmichael(i)) {
           
            int *novo = realloc(carmichael, (total + 1) * sizeof(int));
            if (novo == NULL) {
                printf("Erro de memória!\n");
                free(carmichael);
                return 1;
            }
            carmichael = novo;
            carmichael[total++] = i;
        }
    }

    if (total > 0) {
        printf("Números de Carmichael entre 2 e %d:\n", limite);
        for (int i = 0; i < total; i++) {
            printf("%d ", carmichael[i]);
        }
        printf("\n");
    } else {
        printf("Nenhum número de Carmichael encontrado.\n");
    }

    free(carmichael);

    return 0;
}
