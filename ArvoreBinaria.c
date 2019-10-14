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

void iniciaArvore(PtrNoArvore *arvore) {
    *arvore = NULL;
}

bool estaVazia(PtrNoArvore *arvore) {
    return (*arvore == NULL);
}

bool insercao(PtrNoArvore *arvore, Objeto obj) {

    if ((*arvore) == NULL) {
        *arvore = malloc(sizeof (NoArvore));
        (*arvore)->esquerda = (*arvore)->esquerda = NULL;
        (*arvore)->obj = obj;
        return true;
    }

    if ((*arvore)->obj.chave == obj.chave) {
        printf("Chave duplicada, não inserindo...");
        return false;
    }

    if ((*arvore)->obj.chave > obj.chave) {
        return (insercao(&(*arvore)->esquerda, obj));
    } else if ((*arvore)->obj.chave < obj.chave) {
        return (insercao(&(*arvore)->direita, obj));
    }

}

bool pesquisa(PtrNoArvore *arvore, int x) {

    if ((*arvore) == NULL)return false;

    if ((*arvore)->obj.chave == x)return true;

    if ((*arvore)->obj.chave > x)pesquisa(&(*arvore)->esquerda, x);

    if ((*arvore)->obj.chave < x)pesquisa(&(*arvore)->direita, x);

}

void preOrdem(PtrNoArvore *arvore) {
    printf("%i", (*arvore)->obj.chave);
    preOrdem(&(*arvore)->esquerda);
    preOrdem(&(*arvore)->direita);
}

void proOrdem(PtrNoArvore *arvore) {
    preOrdem(&(*arvore)->esquerda);
    preOrdem(&(*arvore)->direita);
    printf("%i", (*arvore)->obj.chave);
}

void ordem(PtrNoArvore *arvore) {
    preOrdem(&(*arvore)->esquerda);
    preOrdem(&(*arvore)->direita);
    printf("%i", (*arvore)->obj.chave);
}

bool maiorRecursivo(PtrNoArvore *arvore) {
    if ((*arvore)->direita == NULL) {
        printf("%i", (*arvore)->obj.chave);
        return (true);
    }
    return (maiorRecursivo(&(*arvore)->direita));
}

PtrNoArvore esqmax(PtrNoArvore *node) {

    PtrNoArvore ret;
    if ((*node)->direita == NULL) {
        ret = (*node);
        (*node) = (*node)->esquerda;
        return (*node);
    }

    return (esqmax(&(*node)->direita));

}

PtrNoArvore dirmin(PtrNoArvore *node) {

    PtrNoArvore ret;
    if ((*node)->direita == NULL) {
        ret = (*node);
        (*node) = (*node)->direita;
        return ret;
    }

    return (esqmax(&(*node)->esquerda));

}

bool remocao(PtrNoArvore *node, int x) {

    if ((*node) == NULL) {
        return false;
    }
    
    PtrNoArvore tmp = (*node);
    
    if (x == (*node)->obj.chave) {
    
        if ((*node)->esquerda == NULL) {
            (*node) = (*node)->direita;
        }

        else if ((*node)->direita == NULL) {
            (*node) = (*node)->esquerda;
        }

        else if ((*node)->esquerda != NULL && (*node)->direita != NULL) {                            //Verificação de nó interno
            tmp = esqmax(&((*node)->esquerda));
            (*node)->obj = tmp->obj;
            
        }
        free(tmp);
        return true;

    }

    if (x > (*node)->obj.chave) {
        return (remocao(&(*node)->direita, x));
    } else if (x < (*node)->obj.chave) {
        return (remocao(&(*node)->esquerda, x));
    }
}

int main(int argc, char** argv) {


    PtrNoArvore raiz;


    return (EXIT_SUCCESS);
}
