#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int chave;
} Objeto;

typedef struct NoArvore *PtrNoArvore;

typedef struct NoArvore {
    PtrNoArvore direita;
    PtrNoArvore esquerda;
    Objeto obj;
} NoArvore;

iniciaArvore(PtrNoArvore *arvore) {
    *arvore = NULL;
}

estaVazia(PtrNoArvore *arvore) {
    return (*arvore == NULL);
}

bool insercao(PtrNoArvore *arvore, Objeto obj) {

    if ((*arvore) == NULL) {
        *arvore = malloc(sizeof (NoArvore));
        (*arvore)->esquerda = (*arvore)->esquerda = NULL;
        (*arvore).obj = obj;
        return true;
    }

    if ((*arvore)->obj.chave == obj.chave) {
        printf("Chave duplicada, não inserindo...");
        return false;
    }

    if ((*arvore).obj.chave > obj.chave) {
        return (insercao(&(*arvore)->esquerda, obj));
    } else if ((*arvore).obj.chave < obj.chave) {
        return (insercao(&(*arvore)->direita, obj));
    }

}

bool pesquisa(PtrNoArvore *arvore, int x) {

    if ((*arvore) == NULL)return false;

    if ((*arvore)->obj.chave == x)return true;

    if ((*arvore)->obj.chave > x)pesquisa((*arvore)->esquerda, x);

    if ((*arvore)->obj.chave < x)pesquisa((*arvore)->direita, x);

}

void preOrdem(PtrNoArvore *arvore) {
    printf("%i", (*arvore)->obj.chave);
    preOrdem((*arvore)->esquerda);
    preOrdem((*arvore)->direita);
}

void proOrdem(PtrNoArvore *arvore) {
    preOrdem((*arvore)->esquerda);
    preOrdem((*arvore)->direita);
    printf("%i", (*arvore)->obj.chave);
}

void ordem(PtrNoArvore *arvore) {
    preOrdem((*arvore)->esquerda);
    preOrdem((*arvore)->direita);
    printf("%i", (*arvore)->obj.chave);
}

bool maiorRecursivo(PtrNoArvore *arvore) {
    if ((*arvore)->direita == NULL) {
        printf("%i", (*arvore)->obj.chave);
        return (true);
    }
    maiorRecursivo((*arvore).direita);
}

bool maiorInterativo(PtrNoArvore *arvore) {
    PtrNoArvore *aux;
    *aux = *arvore;
    
    while(aux->direita != NULL){
        aux = aux->direita;
    }

    printf("%i", aux->obj.chave);
}

int main(int argc, char** argv) {


    PtrNoArvore raiz;


    return (EXIT_SUCCESS);
}
