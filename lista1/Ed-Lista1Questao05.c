#include <stdio.h>

double soma_fatoriais_inversos(int n){
    double fatorial = 1.0, soma = 0.0;

    for (int i = 1; i <= n; i++){
        fatorial *= i;
        soma += 1.0 / fatorial;
    }

    return soma;
}

int main(){
    int n;

    do {
        printf("Digite o valor do inteiro 1: ");
        scanf("%d", &n);

        if (n <= 0) printf("Digite um número maior que 0\n");
        
    } while (n < 1);

    double resultado = soma_fatoriais_inversos(n);
    printf("A soma dos fatoriais inversos até %d! é: %.2f\n", n, resultado);
    
    return 0;
}
