#define LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
const char* nomeCor(int cor);
void imprimirLista(Paciente *lista);
void imprimirQuantidades(Paciente *lista);
