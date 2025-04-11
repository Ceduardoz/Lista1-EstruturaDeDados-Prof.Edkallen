/*
Função:: Crescimento Populacional (opcional) Adaptado por Neilor Tonin, URI Brasil 
Autor: Carlos Eduardo Barbosa Alves
Data:10/04/2025
Observações: Fiz usando total o chatGPT pois não compreendi muito na hora de iniciar, fiz no intuito de aprender e decidi mandar mesmo assim 
*/

#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T); // Lê o número de casos de teste

    for (int i = 0; i < T; i++) {
        int PA, PB;
        double G1, G2;

        // Lê os valores do caso: População de A, B e taxas
        scanf("%d %d %lf %lf", &PA, &PB, &G1, &G2);

        int anos = 0;

        // Enquanto A for menor ou igual a B e ainda não passou de 100 anos
        while (PA <= PB && anos <= 100) {
            // Crescimento de A e B no ano (usando cast para forçar inteiro)
            PA = PA + (int)(PA * (G1 / 100));
            PB = PB + (int)(PB * (G2 / 100));
            anos++;
        }

        // Verifica se ultrapassou o limite de 100 anos
        if (anos > 100) {
            printf("Mais de 1 século.\n");
        } else {
            printf("%d anos.\n", anos);
        }
    }

    return 0;
}
