#include "lista.h"

int main(void) {
    Paciente *lista = NULL;
    char op;
    int id, cor;

    while (scanf(" %c", &op) == 1) {
        if (op == 'c') {          
            if (scanf("%d %d", &id, &cor) != 2) break;
            lista = inserirPaciente(lista, id, cor);
            printf("c-%d-%s\n", id, nomeCor(cor));
        } else if (op == 'a') {    
            if (scanf("%d", &id) != 1) break;
            Paciente *p = buscarPaciente(lista, id);
            if (p) {
                printf("a-%d-%s\n", id, nomeCor(p->cor));
                lista = removerPaciente(lista, id);
            } else {
                printf("a-%d-nao-encontrado\n", id);
            }
        } else if (op == 'r') {   
            if (scanf("%d", &id) != 1) break;
            Paciente *p = buscarPaciente(lista, id);
            if (p) {
                printf("r-%d-%s\n", id, nomeCor(p->cor));
                lista = removerPaciente(lista, id);
            } else {
                printf("r-%d-nao-encontrado\n", id);
            }
        } else if (op == 'f') {   
            break;
        } else {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) ;
        }
    }

    while (lista) {
        Paciente *tmp = lista;
        lista = lista->prox;
        free(tmp);
    }
    return 0;
}
