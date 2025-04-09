#include <stdio.h>

//calcular e imprimir a potência fatorial crescente
void potencia_fatorial_crescente(int x, int n, FILE *arquivo) {
    int resultado = 1;
    for (int i = 0; i < n; i++) {
        resultado *= (x + i);
    }
    printf("%-5d %-20d", n, resultado);
    fprintf(arquivo, "%-5d %-20d", n, resultado);
}

//calcular e imprimir a potência fatorial decrescente
void potencia_fatorial_decrescente(int x, int n, FILE *arquivo) {
    int resultado = 1;
    for (int i = 0; i < n; i++) {
        resultado *= (x - i);
    }
    printf("%-20d\n", resultado);
    fprintf(arquivo, "%-20d\n", resultado);
}

int main() {
    int x, n, i, j;
    FILE *arquivo; 

    //abrir o arquivo para escrita
    arquivo = fopen("questao1.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    //entrada do usuário
    printf("Digite um valor para x (base): ");
    scanf("%d", &x);
    printf("Digite um valor para n (expoente fatorial): ");
    scanf("%d", &n);

    //exibir no terminal
    printf("\nTabela para x fixo (x = %d) e n variando de 2 a %d:\n", x, n);
    fprintf(arquivo, "Tabela para x fixo (x = %d) e n variando de 2 a %d:\n", x, n);
    
    printf("%-5s %-20s %-20s\n", "n", "Fatorial Crescente", "Fatorial Decrescente");
    fprintf(arquivo, "%-5s %-20s %-20s\n", "n", "Fatorial Crescente", "Fatorial Decrescente");
    
    printf("-----------------------------------------------------\n");
    fprintf(arquivo, "-----------------------------------------------------\n");
    
    for (i = 2; i <= n; i++) { 
        potencia_fatorial_crescente(x, i, arquivo);
        potencia_fatorial_decrescente(x, i, arquivo);
    }

    //escrever no arquivo txt
    printf("\nTabela para n fixo (n = %d) e x variando de 2 a %d:\n", n, x);
    fprintf(arquivo, "\nTabela para n fixo (n = %d) e x variando de 2 a %d:\n", n, x);
    
    printf("%-5s %-20s %-20s\n", "x", "Fatorial Crescente", "Fatorial Decrescente");
    fprintf(arquivo, "%-5s %-20s %-20s\n", "x", "Fatorial Crescente", "Fatorial Decrescente");
    
    printf("-----------------------------------------------------\n");
    fprintf(arquivo, "-----------------------------------------------------\n");
    
    for (j = 2; j <= x; j++) {
        printf("%-5d ", j);
        fprintf(arquivo, "%-5d ", j);
        
        potencia_fatorial_crescente(j, n, arquivo);
        potencia_fatorial_decrescente(j, n, arquivo);
    }

    //fechar o arquivo
    fclose(arquivo);

    printf("\nResultados foram salvos em 'questao.txt'\n");
    
    return 0;
}
