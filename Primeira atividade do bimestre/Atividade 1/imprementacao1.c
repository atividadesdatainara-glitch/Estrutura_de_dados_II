#include <stdio.h>
#include <stdlib.h>

//16. Implemente em linguagem C uma estrutura de nó para uma árvore genérica.
typedef struct No {
    int dado; //--> Valor que guardarar o nó
    struct No* filho_esquerda; // Ponteiro que aponta para a esqueda do pai que vai receber os valore menores.
    struct No* filho_direita; // O ponteiro que vai pontar para direita do pai que vai receber os valores maiores.
} No;

//17. Crie uma função que inicializa uma árvore vazia.
No* inicializar() {
    return NULL; // Quando iniciamos uma árvore seu valor começa vasio, por isso o null. Pois, por agora ela estar apontando para o nada.
}

//18. Implemente uma função para inserir filhos em um nó.
void inserir_filho(No* pai, int valor) { 
    if (pai == NULL) return;

    //Criando o novoo nó filho 
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->filho_esquerda = NULL;

    // Fazendo a ligação onde o novo nó vai para a esquerda do pai e o antigo vai para a direita
    novo->filho_direita = pai->filho_esquerda;
    pai->filho_esquerda = novo;
}

//19. Implemente uma função que conte quantos nós existem em uma árvore.
int contar_nos(No* raiz) {
    if (raiz == NULL) return 0; // Se a raiz for nula o valor vai ser 0 pois não tem nenhum nó para contar.
    
    // Esse processo soma 1 que é o nó atual mais a quantidade de nós que tiver na esquerda e na direita.
    return 1 + contar_nos(raiz->filho_esquerda) + contar_nos(raiz->filho_direita);
}

//20. Implemente uma função recursiva para calcular a altura de uma árvore.
int calcular_altura(No* raiz) {
    if (raiz == NULL) return -1; // Se a árvore estar vazia a altura dela vai ser dada como -1.

    // Guarda a altura de cada lado fazendo a verificação pela esquerda e pela direita
    int alt_esquerda = calcular_altura(raiz->filho_esquerda);
    int alt_direita = calcular_altura(raiz->filho_direita);

    // Passa por uma verificação se a esquerda for maior que a direita ele pega a esquerda e soma 1, caso contrário pega a direita.
    if (alt_esquerda > alt_direita) {
        return alt_esquerda + 1;
    } else {
        return alt_direita + 1;
    }
}

//21. Faça uma função que conte quantas folhas existem em uma árvore.
int contar_folhas(No* raiz) {
    if (raiz == NULL) return 0; // Caso o nó atual for nulo ele apenas retorna 0.

    // Passa por uma verificação se o nó não tem filhos na esquerda e nem na direita, se não tiver ele é uma folha e retorna 1.
    if (raiz->filho_esquerda == NULL && raiz->filho_direita == NULL) {
        return 1;
    }

    // Se tiver filhos ele continua buscando e somando as folhas que encontrar na subárvore esquerda e direita.
    return contar_folhas(raiz->filho_esquerda) + contar_folhas(raiz->filho_direita);
}

// Para textar a implementação
int main() {
    // Valores para teste
    No* raiz = (No*)malloc(sizeof(No));
    raiz->dado = 50;
    raiz->filho_esquerda = NULL;
    raiz->filho_direita = NULL;

    // Inserindo filhos na raiz usando a sua função
    inserir_filho(raiz, 40);
    inserir_filho(raiz, 30);

    // Printando os resultados para ver se estar tudo ok
    printf("Quantidade de nos: %d\n", contar_nos(raiz));
    printf("Altura da arvore: %d\n", calcular_altura(raiz));
    printf("Quantidade de folhas: %d\n", contar_folhas(raiz));

    return 0;
}