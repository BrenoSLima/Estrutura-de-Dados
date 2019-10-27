#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

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
    preOrdem(&(*arvore)->esquerda);
    preOrdem(&(*arvore)->direita);
}

void posOrdem(ptrNoArvore *arvore) {
    if ((*arvore) == NULL)return;
    posOrdem(&(*arvore)->esquerda);
    posOrdem(&(*arvore)->direita);
    printf("%s ", (*arvore)->objArvore.palavra);
}

void ordem(ptrNoArvore *arvore) {
    if ((*arvore) == NULL)return;
    ordem(&(*arvore)->esquerda);
    printf("%s ", (*arvore)->objArvore.palavra);
    ordem(&(*arvore)->direita);

}

//=====================================================================================================================
//=====================================================================================================================
//=====================================================================================================================

void insereFila(fila *f, int x) {

    ptrNoFila novo;
    novo = (ptrNoFila) malloc(sizeof (fila));
    novo->objFila.nrmPagina = x;

    if (f->comeco == NULL) {
        f->comeco = novo;
        f->final = novo;
        novo->prox = NULL;
    } else {
        if(f->final->objFila.nrmPagina == x)return;
        f->final->prox = novo;
        f->final = f->final->prox;
        novo->prox = NULL;
    }
    printf("Número de página inserir: %i\n", x);
}

//=====================================================================================================================

void printFila(fila *f) {
    ptrNoFila aux;
    aux = f->comeco;

    while (aux != NULL) {
        printf("%i, ", aux->objFila.nrmPagina);
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

    //if(pagina == (*arvore)->objArvore.f.final->objFila.nrmPagina){
    //  printf("Repetido\n");
    //}

    if (strcmp(palavra, (*arvore)->objArvore.palavra) == 0 || (strcmp(palavra, (*arvore)->objArvore.palavra) == 0 || toupper(palavra[0] == toupper((*arvore)->objArvore.palavra[0])))) {
        //if(strcmp(palavra, "chave") == 0)printf("TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT\n");
        //if(strcmp(palavra, "arvore") == 0)printf("TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT\n");
        insereFila(&(*arvore)->objArvore.f, pagina);
        printf("Tentado inserir: %s\n", palavra);
        return true;
    }
    if (strcmp(palavra, (*arvore)->objArvore.palavra) < 0) {
        pesquisaPalavra(&(*arvore)->esquerda, palavra, pagina);
    }

    if (strcmp(palavra, (*arvore)->objArvore.palavra) > 0) {
        pesquisaPalavra(&(*arvore)->direita, palavra, pagina);
    }

}

//=====================================================================================================================
//=====================================================================================================================
//=====================================================================================================================

void printar(ptrNoArvore *arvore, FILE *arqSaida) {
    if ((*arvore) == NULL)return;
    printar(&(*arvore)->esquerda, arqSaida);

    ptrNoFila aux;
    aux = (*arvore)->objArvore.f.comeco;
    printf("\n");
    printf("%s: ", (*arvore)->objArvore.palavra);
    fprintf(arqSaida ,"%s: ", (*arvore)->objArvore.palavra);
    //fprintf(arqSaida, "%s: ", (*arvore)->objArvore.palavra);
    while (aux != NULL) {
        printf("%i ", aux->objFila.nrmPagina);
        fprintf(arqSaida ,"%i ", aux->objFila.nrmPagina);
        aux = aux->prox;
    }
    printf("\n");
    fprintf(arqSaida ,"\n");
    printar(&(*arvore)->direita, arqSaida);

}

int main(int argc, char** argv) {

    //=====================================================================================================================
    //=================================PEGANDO TERMOS PARA CRIAÇÃO DA ÁRVORE BINÁRIA=======================================
    //=====================================================================================================================

    if(argc != 3){
        exit(1);
    }
    
    FILE *arqEntrada = NULL;
    FILE *arqSaida = NULL;

    arqEntrada = fopen(argv[1], "r");
    arqSaida = fopen(argv[2], "w");

    if (arqEntrada == NULL || arqSaida == NULL) {
        printf("Erro ao abrir o arquivo.");
        exit(1);
    }

    ptrNoArvore raiz;
    iniciaArvore(&raiz);

    int pagina = 0;
    char str[181], *palavra;
    fgets(str, 181, arqEntrada);

    palavra = strtok(str, " <:,>\n");
    palavra = strtok(NULL, " <:,>\n");

    while (palavra != NULL) {
        printf("|%s| \n", palavra);
        insereArvore(&raiz, palavra);
        palavra = strtok(NULL, " <:,>\n");

    }

    //=====================================================================================================================
    //=====================================================================================================================
    //=====================================================================================================================

    printf("\n\npreOrdem:\n");
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

        palavra = strtok(str, " (),:.<>\n");
        while (palavra != NULL) {
            if (strcmp(palavra, "page") == 0) {
                pagina += 1;
            }
            printf("| %s |\n", palavra);
            pesquisaPalavra(&raiz, palavra, pagina);
            palavra = strtok(NULL, " (),:.<>\n");
        }

    }

    printar(&raiz, arqSaida);

    free(raiz);

    return (EXIT_SUCCESS);
}
