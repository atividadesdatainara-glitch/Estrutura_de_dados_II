//Etapa 1 — Cada nó da árvore precisa armazenar:
//um valor;
//ponteiro para filho da esquerda; 
//ponteiro para filho da direita.

//Em linguagem C:

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esq;
    struct No *dir;
} No;


//Etapa 1 — Cada nó da árvore precisa armazenar:
//um valor;
//ponteiro para filho da esquerda; 
//ponteiro para filho da direita.

//Em linguagem C:

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esq;
    struct No *dir;
} No;


//Etapa 2 — Criando um novo nó
//Agora criamos uma função para alocar memória para um nó.
No* criarNo(int valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}