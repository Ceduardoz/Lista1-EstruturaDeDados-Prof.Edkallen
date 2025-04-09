#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct{
    char nomes[MAX][50];
    int quantidade;
} cadastro;

void adicionar(cadastro *c, const char *nome){
    if (c-> quantidade < MAX){
        strcpy(c->nomes[c->quantidade++], nome);
        c->quantidade++;
    }
}

void listar(cadastro *c){
    printf("Listar de nomes:\n");
    for (int i = 0; i < c-> quantidade; i++){
        printf("- %s\n", c-> nomes[i]);
    }
}

int main(){
    cadastro c = {.quantidade = 0};
    adicionar(&c, "Ana");
    adicionar(&c, "Carlos");
    adicionar(&c, "Beatriz");
    listar(&c);

    return 0;
}