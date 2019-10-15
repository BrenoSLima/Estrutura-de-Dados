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

bool insercao(PtrNoArvore *arvore, int x) {

    if ((*arvore) == NULL) {
        *arvore = malloc(sizeof(NoArvore));
        (*arvore)->esquerda = (*arvore)->direita = NULL;
        (*arvore)->obj.chave = x;
        return true;
    }

    if ((*arvore)->obj.chave == x) {
        printf("Chave duplicada, não inserindo...");
        return false;
    }

    if ((*arvore)->obj.chave > x) {
        return (insercao(&(*arvore)->esquerda, x));
    } else if ((*arvore)->obj.chave < x) {
        return (insercao(&(*arvore)->direita, x));
    }

}

bool pesquisa(PtrNoArvore *arvore, int x) {

    if ((*arvore) == NULL)return false;

    if ((*arvore)->obj.chave == x)return true;

    if ((*arvore)->obj.chave > x)pesquisa(&(*arvore)->esquerda, x);

    if ((*arvore)->obj.chave < x)pesquisa(&(*arvore)->direita, x);

}

void preOrdem(PtrNoArvore *arvore) {
    if((*arvore)==NULL)return;
    printf("%i ", (*arvore)->obj.chave);
    preOrdem(&(*arvore)->esquerda);
    preOrdem(&(*arvore)->direita);
}

void posOrdem(PtrNoArvore *arvore) {
    if((*arvore)==NULL)return;
    preOrdem(&(*arvore)->esquerda);
    preOrdem(&(*arvore)->direita);
    printf("%i ", (*arvore)->obj.chave);
}

void ordem(PtrNoArvore *arvore) {
    if((*arvore)==NULL)return;
    preOrdem(&(*arvore)->esquerda);
    printf("%i ", (*arvore)->obj.chave);
    preOrdem(&(*arvore)->direita);

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
    if ((*node)->esquerda == NULL) {
        ret = (*node);
        (*node) = (*node)->esquerda;
        return ret;
    }

    return (esqmax(&(*node)->esquerda));

}

bool remocao(PtrNoArvore *node, int x) {

    if ((*node) == NULL) {
        return false;
    }

    PtrNoArvore tmp = (*node);

    if ((*node)->obj.chave == x) {

        if ((*node)->esquerda == NULL) {
            (*node) = (*node)->direita;
        } else if ((*node)->direita == NULL) {
            (*node) = (*node)->esquerda;
        } else if ((*node)->esquerda != NULL && (*node)->direita != NULL) { //Verificação de nó interno
            tmp = esqmax(&((*node)->esquerda));
            //tmp = dirmin(&((*node)->esquerda));
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

    int escolha, elemento;
    PtrNoArvore raiz;
    Objeto obj;
    
    
    iniciaArvore(&raiz);
    insercao(&raiz, 10);
    insercao(&raiz, 5);
    insercao(&raiz, 15);
    insercao(&raiz, 3);
    insercao(&raiz, 7);
    insercao(&raiz, 13);
    insercao(&raiz, 18);
    
    do {
        printf( "\n[1] - Pré-ordem\n"
                "[2] - Pós-ordem\n"
                "[3] - Ordem\n"
                "[4] - Excluir\n");
        scanf("%i", &escolha);

        switch (escolha) {
            case 1:
                system("clear");
                preOrdem(&raiz);
                break;
            case 2:
                system("clear");
                posOrdem(&raiz);
                break;
            case 3:
                system("clear");
                ordem(&raiz);
                break;
            case 4:
                system("clear");
                printf("Elemento: ");
                scanf("%i", &elemento);
                remocao(&raiz, elemento);
        }
    } while (1);

    return (EXIT_SUCCESS);
}
