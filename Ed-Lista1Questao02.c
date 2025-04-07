#include <stdio.h>

//calcular e imprimir o fatorial normal
void fatorial(int n, int *resultado) {
    *resultado = 1;
    for (int i = 2; i <= n; i++) {
        *resultado *= i;
        if (*resultado < 0) {
            printf("Erro: Overflow ao calcular fatorial de %d.\n", n);
            *resultado = -1;
            return;
        }
    }
}

//calcular e imprimir o fatorial duplo
void fatorial_duplo(int n, int *resultado) {
    *resultado = 1;
    for (int i = n; i >= 1; i -= 2) {
        *resultado *= i;
        if (*resultado < 0) { 
            printf("Erro: Overflow ao calcular fatorial duplo de %d.\n", n);
            *resultado = -1;
            return;
        }
    }
}

int main() {
    int inicio = 2, fim = 10; 
    int fatoriais[fim - inicio + 1];
    int fatoriais_duplos[fim - inicio + 1];
    int diferencas[fim - inicio + 1];

    FILE *arquivo;
    arquivo = fopen("resultados.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    //texto da tabela
    printf("%-10s %-15s %-15s %-15s\n", "n", "Fatorial", "Fatorial Duplo", "Diferença");
    printf("-------------------------------------------------------------\n");
    fprintf(arquivo, "%-10s %-15s %-15s %-15s\n", "n", "Fatorial", "Fatorial Duplo", "Diferença");
    fprintf(arquivo, "-------------------------------------------------------------\n");

    //arrays e exibindo os valores
    for (int n = inicio; n <= fim; n++) {
        fatorial(n, &fatoriais[n - inicio]);
        fatorial_duplo(n, &fatoriais_duplos[n - inicio]);

        //se tiver overflow, ignora esse valor
        if (fatoriais[n - inicio] == -1 || fatoriais_duplos[n - inicio] == -1) {
            continue;
        }

        diferencas[n - inicio] = fatoriais[n - inicio] - fatoriais_duplos[n - inicio];

        //exibir na tela
        printf("%-10d %-15d %-15d %-15d\n", n, fatoriais[n - inicio], fatoriais_duplos[n - inicio], diferencas[n - inicio]);
        //exibir no arquivo
        fprintf(arquivo, "%-10d %-15d %-15d %-15d\n", n, fatoriais[n - inicio], fatoriais_duplos[n - inicio], diferencas[n - inicio]);
    }

    fclose(arquivo);
    printf("\nResultados salvos em 'resultados.txt'.\n");

    return 0;
}