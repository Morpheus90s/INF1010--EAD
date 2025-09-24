#include <stdio.h>
#include <stdlib.h>

#define VERMELHO 1
#define AMARELO  2
#define VERDE    3

typedef struct paciente {
    int id;
    int cor;
    struct paciente *prox;
} Paciente;

Paciente* inserirPaciente(Paciente *lista, int id, int cor);
Paciente* removerPaciente(Paciente *lista, int id);
Paciente* buscarPaciente(Paciente *lista, int id);

char* nomeCor(int cor);

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

    // liberar lista
    while (lista) {
        Paciente *tmp = lista;
        lista = lista->prox;
        free(tmp);
    }
    return 0;
}

Paciente* inserirPaciente(Paciente *lista, int id, int cor) {
    Paciente *novo = malloc(sizeof(Paciente));
    if (!novo) { perror("malloc"); exit(1); }
    novo->id = id; novo->cor = cor; novo->prox = NULL;

    if (!lista || cor < lista->cor || (cor == lista->cor && id < lista->id)) {
        novo->prox = lista;
        return novo;
    }

    Paciente *p = lista;
    while (p->prox && (p->prox->cor < cor || (p->prox->cor == cor && p->prox->id < id)))
        p = p->prox;

    novo->prox = p->prox;
    p->prox = novo;
    return lista;
}

Paciente* buscarPaciente(Paciente *lista, int id) {
    for (Paciente *p = lista; p; p = p->prox)
        if (p->id == id) return p;
    return NULL;
}

Paciente* removerPaciente(Paciente *lista, int id) {
    Paciente *p = lista, *ant = NULL;
    while (p && p->id != id) {
        ant = p;
        p = p->prox;
    }
    if (!p) return lista; 
    if (!ant) lista = p->prox;
    else ant->prox = p->prox;
    free(p);
    return lista;
}

char* nomeCor(int cor) {
    if (cor == VERMELHO) return "vermelha";
    if (cor == AMARELO)  return "amarela";
    return "verde";
}
