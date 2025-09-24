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

