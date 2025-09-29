#include "lista.h"
#include <string.h>

int corParaConst(const char *cor) {
    if (strcmp(cor, "vermelha") == 0) return VERMELHO;
    if (strcmp(cor, "amarela")  == 0) return AMARELO;
    if (strcmp(cor, "verde")    == 0) return VERDE;
    return 0; 

int main(void) {
    Paciente *lista = NULL;
    char linha[50];

    while (fgets(linha, sizeof(linha), stdin)) {
        char op;
        int id;
        char corStr[20];

        if (sscanf(linha, " %c-%d-%19s", &op, &id, corStr) >= 2) {
            
            corStr[strcspn(corStr, "\n")] = 0;

            if (op == 'c') {
                int cor = corParaConst(corStr);
                if (cor == 0) continue;
                lista = inserirPaciente(lista, id, cor);
                imprimirLista(lista);

            } else if (op == 'a') { 
                Paciente *p = buscarPaciente(lista, id);
                if (p) lista = removerPaciente(lista, id);
                imprimirLista(lista);
                imprimirQuantidades(lista);

            } else if (op == 'r') { 
                Paciente *p = buscarPaciente(lista, id);
                if (p) lista = removerPaciente(lista, id);
                imprimirLista(lista);

            }
        }
    }

    while (lista) {
        Paciente *tmp = lista;
        lista = lista->prox;
        free(tmp);
    }
    return 0;
}
