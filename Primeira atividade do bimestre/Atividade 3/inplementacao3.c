#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

// 10. Implemente la función de inserción en una ABB usando recursión.
No* inserir(No* raiz, int valor) {
    if (raiz == NULL) return criar_no(valor);

    if (valor < raiz->dado) {
        raiz->filho_esquerda = inserir(raiz->filho_esquerda, valor);
    } else if (valor > raiz->dado) {
        raiz->filho_direita = inserir(raiz->filho_direita, valor);
    }
    return raiz;
}

// 11. Implemente la función de busca em uma ABB.
No* buscar(No* raiz, int valor) {
    if (raiz == NULL || raiz->dado == valor) return raiz;

    if (valor < raiz->dado) {
        return buscar(raiz->filho_esquerda, valor);
    }
    return buscar(raiz->filho_direita, valor);
}

// 12. Implemente o percurso em ordem em uma ABB.
void em_ordem(No* raiz) {
    if (raiz == NULL) return;
    em_ordem(raiz->filho_esquerda);
    printf("%d ", raiz->dado);
    em_ordem(raiz->filho_direita);
}

// 16. Implemente uma função que encontre o menor valor em uma ABB.
No* encontrar_minimo(No* raiz) {
    No* atual = raiz;
    while (atual && atual->filho_esquerda != NULL) {
        atual = atual->filho_esquerda;
    }
    return atual;
}

// 16. Implemente uma função que encontre o maior valor em uma ABB.
No* encontrar_maximo(No* raiz) {
    No* atual = raiz;
    while (atual && atual->filho_direita != NULL) {
        atual = atual->filho_direita;
    }
    return atual;
}

// 13. Implemente la remoção de um nó folha em uma ABB.
// 14. Implemente la remoção de um nó com apenas um filho.
// 15. Implemente la remoção de um nó com dois filhos utilizando sucessor em ordem.
No* remover(No* raiz, int valor) {
    if (raiz == NULL) return raiz;

    if (valor < raiz->dado) {
        raiz->filho_esquerda = remover(raiz->filho_esquerda, valor);
    } else if (valor > raiz->dado) {
        raiz->filho_direita = remover(raiz->filho_direita, valor);
    } else {
        if (raiz->filho_esquerda == NULL) {
            No* temp = raiz->filho_direita;
            free(raiz);
            return temp;
        } else if (raiz->filho_direita == NULL) {
            No* temp = raiz->filho_esquerda;
            free(raiz);
            return temp;
        }

        No* temp = encontrar_minimo(raiz->filho_direita);
        raiz->dado = temp->dado;
        raiz->filho_direita = remover(raiz->filho_direita, temp->dado);
    }
    return raiz;
}

// 17. Crie uma função que verifique se uma árvore é realmente uma ABB válida.
int eh_abb_util(No* raiz, int min, int max) {
    if (raiz == NULL) return 1;

    if (raiz->dado <= min || raiz->dado >= max) return 0;

    return eh_abb_util(raiz->filho_esquerda, min, raiz->dado) &&
           eh_abb_util(raiz->filho_direita, raiz->dado, max);
}

int eh_abb(No* raiz) {
    return eh_abb_util(raiz, INT_MIN, INT_MAX);
}

// 18. Implemente uma função que conte quantos níveis existem na ABB.
int contar_niveis(No* raiz) {
    if (raiz == NULL) return 0;

    int alt_esquerda = contar_niveis(raiz->filho_esquerda);
    int alt_direita = contar_niveis(raiz->filho_direita);

    if (alt_esquerda > alt_direita) {
        return alt_esquerda + 1;
    } else {
        return alt_direita + 1;
    }
}

// 19. Crie um programa completo de ABB com menu contendo: Inserir, Buscar, Remover, Imprimir em ordem, Mostrar altura, Encerrar
int main() {
    No* raiz = NULL;
    int opcao, valor;
    No* busca_resultado;

    do {
        printf("\n--- MENU ABB ---\n");
        printf("1. Inserir\n");
        printf("2. Buscar\n");
        printf("3. Remover\n");
        printf("4. Imprimir em ordem\n");
        printf("5. Mostrar altura / niveis\n");
        printf("6. Mostrar Menor e Maior valor\n");
        printf("7. Encerrar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor para inserir: ");
                scanf("%d", &valor);
                raiz = inserir(raiz, valor);
                printf("Valor inserido.\n");
                break;
            case 2:
                printf("Digite o valor para buscar: ");
                scanf("%d", &valor);
                busca_resultado = buscar(raiz, valor);
                if (busca_resultado != NULL) {
                    printf("Valor %d encontrado na arvore.\n", valor);
                } else {
                    printf("Valor %d nao encontrado.\n", valor);
                }
                break;
            case 3:
                printf("Digite o valor para remover: ");
                scanf("%d", &valor);
                raiz = remover(raiz, valor);
                printf("Operacao de remocao concluida.\n");
                break;
            case 4:
                printf("Arvore em ordem: ");
                em_ordem(raiz);
                printf("\n");
                break;
            case 5:
                printf("Quantidade de niveis (altura): %d\n", contar_niveis(raiz));
                break;
            case 6:
                if (raiz != NULL) {
                    printf("Menor valor: %d\n", encontrar_minimo(raiz)->dado);
                    printf("Maior valor: %d\n", encontrar_maximo(raiz)->dado);
                } else {
                    printf("Arvore vazia.\n");
                }
                break;
            case 7:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 7);

    return 0;
}