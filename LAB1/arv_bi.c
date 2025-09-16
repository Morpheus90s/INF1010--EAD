#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

struct nodo {
    int chave;
    int altura;
    struct nodo *esq;
    struct nodo *dir;
};
typedef struct nodo Nodo;

Nodo* cria_nodo(int chave);

int main(void) {
    char *nome = "entrada.txt";
    FILE *f = fopen(nome, "r");

    if (f == NULL) {
        printf("Erro ao abrir arquivo %s\n", nome);
        return TRUE;  
    }

    Nodo *root = NULL;
    int x;

    fclose(f);

    return FALSE; 
}

Nodo* cria_nodo(int chave) {
    Nodo *n = (Nodo*) malloc(sizeof(Nodo));
    if (n == NULL) {
        printf("Erro de alocacao de memoria\n");
        exit(TRUE);
    }
    n->chave = chave;
    n->altura = 0;
    n->esq = NULL;
    n->dir = NULL;
    return n;
}

