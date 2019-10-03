#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int key;
} Objeto;

typedef struct NoLista* PtrNoLista;

typedef struct NoLista {
    Objeto obj;
    PtrNoLista prox;
    PtrNoLista ante;
} NoLista;

typedef struct {
    PtrNoLista inicio;
    int tamanho;
} Lista;

void iniciaLista(Lista *l) {
    l->inicio = NULL;
    l->tamanho = 0;
}

int tamanho(Lista *l) {
    return l->tamanho;
}

bool estaVazia(Lista *l) {
    if (l->inicio == NULL) {
        return true;
    } else {
        return false;
    }
}

int insereElemento(Lista *l, int chave) {


    PtrNoLista novo;

    novo = (PtrNoLista) malloc(sizeof (NoLista));
    novo->obj.key = chave;

    if (l->inicio == NULL) {
        
        novo->prox = NULL;
        novo->ante = NULL;
        l->inicio = novo;
        l->tamanho += 1;
        return chave;

    }

    else if (chave < l->inicio->obj.key) {

        novo->prox = l->inicio;
        l->inicio->ante = novo;
        novo->ante = NULL;
        l->inicio = novo;
        l->tamanho += 1;
        return chave;

    }

    else {

        PtrNoLista aux;

        aux = l->inicio;

        while (aux->prox != NULL && chave > aux->prox->obj.key) {
            aux = aux->prox;
        }

        novo->prox = aux->prox;
        novo->ante = aux;
        aux->prox->ante = novo;
        aux->prox = novo;
        l->tamanho += 1;
        return chave;
        
    }
}

void criaLista(Lista *l, FILE *arqEntrada, FILE *arqSaida) {

    char charAux;
    int numAux;
    PtrNoLista aux;

    iniciaLista(l);

    while (fscanf(arqEntrada, "%i%c", &numAux, &charAux) != EOF) {
        insereElemento(l, numAux);
        //printf("%i, ", numAux);
    }

}

int main(int argc, char** argv) {

    Lista l;
    Objeto objAux;
    PtrNoLista aux;

    FILE *arqEntrada = NULL;
    FILE *arqSaida = NULL;

    arqEntrada = fopen("input.txt", "r");
    arqSaida = fopen("output.txt", "w");

    if (arqEntrada == NULL || arqSaida == NULL) {
        printf("Erro ao abrir o arquivo.");
        exit(1);
    }

    char verificacao;

    verificacao = fgetc(arqEntrada);
    criaLista(&l, arqEntrada, arqSaida);

    if (verificacao == 'c') {

        aux = l.inicio;

        fprintf(arqSaida, "Tamanho = %i\n", l.tamanho);


        fprintf(arqSaida, "Lista = {");
        while (aux->prox != NULL) {
            fprintf(arqSaida, "%i,", aux->obj.key);
            aux = aux->prox;
        }
        fprintf(arqSaida, "%i}", aux->obj.key);


    } else if (verificacao == 'd') {

        aux = l.inicio;

        while (aux->prox != NULL) {
            aux = aux->prox;
        }

        fprintf(arqSaida, "Tamanho = %i\n", l.tamanho);

        fprintf(arqSaida, "Lista = {");

        while (aux->ante != NULL) {
            fprintf(arqSaida, "%i,", aux->obj.key);
            printf("%i ", aux->obj.key);
            aux = aux->ante;
        }
        fprintf(arqSaida, "%i}", aux->obj.key);

    } else {
        fprintf(arqSaida, "Erro!");
        printf("Arquivo não especifica tipo da lista.\n");
        exit(1);
    }


    return (EXIT_SUCCESS);
}
