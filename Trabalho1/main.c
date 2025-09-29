#include "lista.h"
#include <string.h>

int corParaConst(const char *cor) {
    if (strcmp(cor, "vermelha") == 0) return VERMELHO;
    if (strcmp(cor, "amarela")  == 0) return AMARELO;
    if (strcmp(cor, "verde")    == 0) return VERDE;
    return 0; 
}

int main(void) {
    Paciente *lista = NULL;
    char linha[50];
    int cor;
    int id;
    char op;
    char corStr[20];

    while (fgets(linha, sizeof(linha), stdin)) {

        linha[strcspn(linha, "\n")] = 0;

        if (sscanf(linha, "%c-%d-%19s", &op, &id, corStr) == 3) {
            cor = corParaConst(corStr);
            if (cor == 0) continue; 

            if (op == 'c') { 
                lista = inserirPaciente(lista, id, cor);
                printf("Pacientes chegando: %c-%d-%s\n", op, id, corStr);
                imprimirLista(lista);
                printf("---\n"); 
                
            } else {
            
                continue; 
            }
        } else if (sscanf(linha, "%c-%d", &op, &id) == 2) {

            if (op == 'a') { 
        
                Paciente *p = buscarPaciente(lista, id);
                if (p) {
                    printf("Paciente atendido: %c-%d-%s\n", op, id, nomeCor(p->cor));
                    lista = removerPaciente(lista, id);
                    imprimirLista(lista);
                    imprimirQuantidades(lista);
                    printf("---\n"); 
                }

            } else if (op == 'r') { 
                Paciente *p = buscarPaciente(lista, id);
                if (p) {
                    printf("Paciente desiste: %c-%d-%s\n", op, id, nomeCor(p->cor));
                    lista = removerPaciente(lista, id);
                    imprimirLista(lista);
                    imprimirQuantidades(lista);
                    printf("---\n"); 
                }
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