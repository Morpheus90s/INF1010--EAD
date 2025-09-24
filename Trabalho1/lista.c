#include "lista.h"

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
