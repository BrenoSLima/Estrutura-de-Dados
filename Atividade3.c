#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//=====================================================================================================================
//=====================================================================================================================
//=====================================================================================================================

typedef struct {
    int nrmPagina;
} objetoFila;

typedef struct noFila *ptrNoFila;

typedef struct noFila {
    objetoFila objFila;
    ptrNoFila prox;
} noFila;

typedef struct {
    ptrNoFila comeco;
    ptrNoFila final;
    int tamanho;
} fila;

//=====================================================================================================================

typedef struct {
    fila f;
    char palavra[47];
} objetoArvore;

typedef struct noArvore *ptrNoArvore;

typedef struct noArvore {
    ptrNoArvore esquerda;
    ptrNoArvore direita;
    objetoArvore objArvore;
} noArvore;

//=====================================================================================================================
//=====================================================================================================================
//=====================================================================================================================

void iniciaFila(fila *f) {
    f->comeco = NULL;
    f->final = NULL;
    f->tamanho = 0;
    printf("Fila iniciada\n");
}

void iniciaArvore(ptrNoArvore *arvore) {
    (*arvore) = NULL;
}

//=====================================================================================================================
//=====================================================================================================================
//=====================================================================================================================

bool estaVaziaFila(fila *f) {
    return (f->comeco == NULL);
}

bool estaVaziaArvore(ptrNoArvore *arvore) {
    return ((*arvore) == NULL);
}

//=====================================================================================================================
//=====================================================================================================================
//=====================================================================================================================

bool insereArvore(ptrNoArvore *arvore, char *palavra) {

    if ((*arvore) == NULL) {
        (*arvore) = malloc(sizeof (noArvore));
        (*arvore)->esquerda = NULL;
        (*arvore)->direita = NULL;
        iniciaFila(&(*arvore)->objArvore.f);
        strcpy((*arvore)->objArvore.palavra, palavra);
        return true;
    }

    if (strcmp(palavra, (*arvore)->objArvore.palavra) == 0) {
        return false;
    }

    if (strcmp(palavra, (*arvore)->objArvore.palavra) < 0) {
        return (insereArvore(&(*arvore)->esquerda, palavra));
    }

    if (strcmp(palavra, (*arvore)->objArvore.palavra) > 0) {
        return (insereArvore(&(*arvore)->direita, palavra));
    }
}

//=====================================================================================================================
//=====================================================================================================================
//=====================================================================================================================

void preOrdem(ptrNoArvore *arvore) {
    if ((*arvore) == NULL)return;
    printf("%s ", (*arvore)->objArvore.palavra);
    //printf(" 1 ");
    preOrdem(&(*arvore)->esquerda);
    preOrdem(&(*arvore)->direita);
}

void posOrdem(ptrNoArvore *arvore) {
    if ((*arvore) == NULL)return;
    posOrdem(&(*arvore)->esquerda);
    posOrdem(&(*arvore)->direita);
    printf("%s ", (*arvore)->objArvore.palavra);
    //printf(" 1 ");
}

void ordem(ptrNoArvore *arvore) {
    if ((*arvore) == NULL)return;
    ordem(&(*arvore)->esquerda);
    printf("%s ", (*arvore)->objArvore.palavra);
    //printf(" 1 ");
    ordem(&(*arvore)->direita);

}

//=====================================================================================================================
//=====================================================================================================================
//=====================================================================================================================

void insereFila(fila *f, int x) {

    ptrNoFila novo;
    novo = (ptrNoFila) malloc(sizeof (fila));

    if (f->comeco == NULL) {
        f->comeco = novo;
        f->final = novo;
        novo->prox = NULL;
    } else {
        f->final->prox = novo;
        f->final = f->final->prox;
        novo->prox = NULL;
    }

}

//=====================================================================================================================

void printFila(fila *f) {
    ptrNoFila aux;
    printf("CCCCCC");
    aux = f->comeco;

    while (aux->prox != NULL) {
        printf(" AAAAAAA ");
        printf("%i, ", aux->objFila.nrmPagina);
        printf(" BBBBBBB ");
        aux = aux->prox;
    }
}
//=====================================================================================================================
//=====================================================================================================================
//=====================================================================================================================

bool pesquisaPalavra(ptrNoArvore *arvore, char *palavra, int pagina) {


    if ((*arvore) == NULL) {
        return false;
    }

    if (strcmp(palavra, (*arvore)->objArvore.palavra) == 0) {
        insereFila(&(*arvore)->objArvore.f, pagina);
        return true;
    }
    if (strcmp(palavra, (*arvore)->objArvore.palavra) < 0) {
        pesquisaPalavra(&(*arvore)->esquerda, palavra, pagina);
    }

    if (strcmp(palavra, (*arvore)->objArvore.palavra) > 0) {
        pesquisaPalavra(&(*arvore)->esquerda, palavra, pagina);
    }

}

//=====================================================================================================================
//=====================================================================================================================
//=====================================================================================================================

void printar(ptrNoArvore *arvore) {

    if ((*arvore) == NULL)return;
    printar(&(*arvore)->esquerda);
    printf("%s ", (*arvore)->objArvore.palavra);
    printf("\n");
    printFila(&(*arvore)->objArvore.f);
    printar(&(*arvore)->direita);

}

int main(int argc, char** argv) {

    //=====================================================================================================================
    //=================================PEGANDO TERMOS PARA CRIAÇÃO DA ÁRVORE BINÁRIA=======================================
    //=====================================================================================================================

    FILE *arqEntrada = NULL;
    FILE *arqSaida = NULL;

    arqEntrada = fopen("entrada.txt", "r");
    arqSaida = fopen("saida.txt", "w");

    if (arqEntrada == NULL || arqSaida == NULL) {
        printf("Erro ao abrir o arquivo.");
        exit(1);
    }

    ptrNoArvore raiz;
    iniciaArvore(&raiz);

    int pagina = 0;
    char str[181], *palavra;
    fgets(str, 181, arqEntrada);

    palavra = strtok(str, " <:,>");
    palavra = strtok(NULL, " <:,>");

    while (palavra != NULL) {
        insereArvore(&raiz, palavra);
        printf("%s ", palavra);
        strtok(NULL, " <:,>");
    }

    //=====================================================================================================================
    //=====================================================================================================================
    //=====================================================================================================================

    printf("\npreOrdem:\n");
    preOrdem(&raiz);
    printf("\n\n==========\n");
    printf("\nposOrdem:\n");
    posOrdem(&raiz);
    printf("\n\n==========\n");
    printf("\nordem:\n");
    ordem(&raiz);
    printf("\n\n==========\n");

    //=====================================================================================================================
    //=====================================================================================================================
    //=====================================================================================================================


    while (fgets(str, 181, arqEntrada) != NULL) {
        
        if (str[strcspn(str, ">")] == '>' && str[strcspn(str, "<")] == '<') {
            pagina += 1;
            printf("\n\nPágina: %i\n\n", pagina);
            continue;
        }

        palavra = strtok(str, " (),:.<>\n");
        while (palavra != NULL) {
            pesquisaPalavra(&raiz, palavra, pagina);
            printf("| %s |\n", palavra);
            palavra = strtok(NULL, " (),:.<>\n");
        }

    }

    printar(&raiz);

    free(raiz);

    return (EXIT_SUCCESS);
}

