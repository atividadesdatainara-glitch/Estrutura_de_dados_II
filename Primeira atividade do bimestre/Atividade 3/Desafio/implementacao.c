#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado; 
    struct No* filho_esquerda; 
    struct No* filho_direita; 
} No;

No* criar_no(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->filho_esquerda = NULL; 
    novo->filho_direita = NULL;  
    return novo;
}

// 20. Implemente uma ABB sem utilizar recursão.
No* inserir_iterativo(No* raiz, int valor) {
    No* novo = criar_no(valor);
    if (raiz == NULL) return novo;

    No* atual = raiz;
    No* pai = NULL;

    while (atual != NULL) {
        pai = atual;
        if (valor < atual->dado) {
            atual = atual->filho_esquerda;
        } else if (valor > atual->dado) {
            atual = atual->filho_direita;
        } else {
            free(novo); 
            return raiz;
        }
    }

    if (valor < pai->dado) {
        pai->filho_esquerda = novo;
    } else {
        pai->filho_direita = novo;
    }

    return raiz;
}

// 21. Implemente uma árvore binária utilizando alocação dinâmica.
// Nota: A própria estrutura 'No' e a função 'criar_no' acima já realizam a alocação dinâmica com malloc.
No* inicializar_arvore_dinamica() {
    No* raiz = criar_no(10);
    raiz->filho_esquerda = criar_no(5);
    raiz->filho_direita = criar_no(15);
    return raiz;
}

// 22. Crie uma função que transforme uma árvore binária em espelho.
void espelhar_arvore(No* raiz) {
    if (raiz == NULL) return;

    No* aux = raiz->filho_esquerda;
    raiz->filho_esquerda = raiz->filho_direita;
    raiz->filho_direita = aux;

    espelhar_arvore(raiz->filho_esquerda);
    espelhar_arvore(raiz->filho_direita);
}

// Auxiliar para calcular a altura (usada na questão 23)
int altura(No* raiz) {
    if (raiz == NULL) return -1;
    int alt_esq = altura(raiz->filho_esquerda);
    int alt_dir = altura(raiz->filho_direita);
    return (alt_esq > alt_dir ? alt_esq : alt_dir) + 1;
}

// 23. Implemente uma função que verifique se uma árvore é balanceada.
int eh_balanceada(No* raiz) {
    if (raiz == NULL) return 1;

    int alt_esq = altura(raiz->filho_esquerda);
    int alt_dir = altura(raiz->filho_direita);

    int diferenca = alt_esq - alt_dir;
    if (diferenca < 0) diferenca = -diferenca; 

    if (diferenca <= 1 && eh_balanceada(raiz->filho_esquerda) && eh_balanceada(raiz->filho_direita)) {
        return 1;
    }

    return 0;
}

void em_ordem(No* raiz) {
    if (raiz == NULL) return;
    em_ordem(raiz->filho_esquerda);
    printf("%d ", raiz->dado);
    em_ordem(raiz->filho_direita);
}

int main() {
    No* raiz = NULL;

    // Testando inserção não recursiva (Questão 20)
    raiz = inserir_iterativo(raiz, 50);
    raiz = inserir_iterativo(raiz, 30);
    raiz = inserir_iterativo(raiz, 70);
    raiz = inserir_iterativo(raiz, 20);
    raiz = inserir_iterativo(raiz, 40);

    printf("--- Resultados dos Desafios ---\n");
    printf("Arvore original em ordem: ");
    em_ordem(raiz);
    printf("\n");

    // Testando se é balanceada (Questão 23)
    if (eh_balanceada(raiz)) {
        printf("A arvore estah balanceada!\n");
    } else {
        printf("A arvore nao estah balanceada!\n");
    }

    // Testando o espelhamento (Questão 22)
    espelhar_arvore(raiz);
    printf("Arvore espelhada em ordem: ");
    em_ordem(raiz);
    printf("\n");

    return 0;
}