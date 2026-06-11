#include <stdio.h>
#include <stdlib.h>

// 36. Implemente a estrutura de um nó de árvore binária em C.
typedef struct No {
    int dado; 
    struct No* filho_esquerda; 
    struct No* filho_direita; 
} No;

// 37. Crie uma função para inserir nós manualmente em uma árvore binária.
No* criar_no(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->filho_esquerda = NULL; 
    novo->filho_direita = NULL;  
    return novo;
}

// 38. Implemente o percurso em pré-ordem.
void pre_ordem(No* raiz) {
    if (raiz == NULL) return; 
    printf("%d ", raiz->dado);
    pre_ordem(raiz->filho_esquerda);
    pre_ordem(raiz->filho_direita);
}

// 39. Implemente o percurso em ordem.
void em_ordem(No* raiz) {
    if (raiz == NULL) return; 
    em_ordem(raiz->filho_esquerda);
    printf("%d ", raiz->dado);
    em_ordem(raiz->filho_direita);
}

// 40. Implemente o percurso em pós-ordem.
void pos_ordem(No* raiz) {
    if (raiz == NULL) return; 
    pos_ordem(raiz->filho_esquerda);
    pos_ordem(raiz->filho_direita);
    printf("%d ", raiz->dado);
}

// 41. Crie uma função que conte o número de nós da árvore binária.
int contar_nos(No* raiz) {
    if (raiz == NULL) return 0; 
    return 1 + contar_nos(raiz->filho_esquerda) + contar_nos(raiz->filho_direita);
}

// 42. Implemente uma função que calcule a altura da árvore binária.
int calcular_altura(No* raiz) {
    if (raiz == NULL) return -1; 

    int alt_esquerda = calcular_altura(raiz->filho_esquerda);
    int alt_direita = calcular_altura(raiz->filho_direita);

    if (alt_esquerda > alt_direita) {
        return alt_esquerda + 1;
    } else {
        return alt_direita + 1;
    }
}

// 43. Implemente uma função que conte quantos nós folhas existem.
int contar_folhas(No* raiz) {
    if (raiz == NULL) return 0; 

    if (raiz->filho_esquerda == NULL && raiz->filho_direita == NULL) {
        return 1;
    }

    return contar_folhas(raiz->filho_esquerda) + contar_folhas(raiz->filho_direita);
}

// 44. Crie uma função que espelhe uma árvore binária.
void espelhar_arvore(No* raiz) {
    if (raiz == NULL) return; 

    No* aux = raiz->filho_esquerda;
    raiz->filho_esquerda = raiz->filho_direita;
    raiz->filho_direita = aux;

    espelhar_arvore(raiz->filho_esquerda);
    espelhar_arvore(raiz->filho_direita);
}

// 45. Implemente uma função que verifique se duas árvores binárias são iguais.
int arvores_iguais(No* a, No* b) {
    if (a == NULL && b == NULL) return 1; 
    if (a == NULL || b == NULL) return 0; 

    return (a->dado == b->dado) && 
           arvores_iguais(a->filho_esquerda, b->filho_esquerda) && 
           arvores_iguais(a->filho_direita, b->filho_direita);
}

int main() {
    // Criação manual da árvore 1
    No* raiz1 = criar_no(50);
    raiz1->filho_esquerda = criar_no(40);
    raiz1->filho_direita = criar_no(60);
    
    // Criação manual da árvore 2
    No* raiz2 = criar_no(50);
    raiz2->filho_esquerda = criar_no(40);
    raiz2->filho_direita = criar_no(60);

    // Execução dos testes
    printf("--- Resultados da Arvore 1 ---\n");
    printf("Quantidade de nos: %d\n", contar_nos(raiz1));
    printf("Altura da arvore: %d\n", calcular_altura(raiz1));
    printf("Quantidade de folhas: %d\n", contar_folhas(raiz1));
    
    printf("\nPercurso em Ordem original: ");
    em_ordem(raiz1);
    printf("\n");

    if(arvores_iguais(raiz1, raiz2)) {
        printf("As arvores sao iguais!\n");
    } else {
        printf("As arvores sao diferentes!\n");
    }

    espelhar_arvore(raiz1);
    printf("\nPercurso em Ordem apos espelhar: ");
    em_ordem(raiz1);
    printf("\n");

    return 0;
}