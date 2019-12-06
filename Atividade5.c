#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int key;
} Objeto;

typedef struct noFila *ptrNoFila;

typedef struct noFila {
    ptrNoFila proximo;
    Objeto obj;
} noFila;

typedef struct {
    ptrNoFila inicio;
    ptrNoFila fim;
    int contador;
} filaDinamica;

typedef struct {
    int linha;
    int coluna;
    int numero;
    int qualGrafo;
} tipoMatriz;

typedef struct {
    int cor;
    int d;
} Grafo;

void iniciaFila(filaDinamica *fila) {

    fila->inicio = NULL;
    fila->fim = NULL;
    fila->contador = 0;

}

bool estaVazia(filaDinamica *fila) {
    return (fila->contador == 0);
}

void inserirFila(filaDinamica *fila, int x) {

    ptrNoFila aux;

    aux = (ptrNoFila) malloc(sizeof (noFila));

    aux->obj.key = x;

    if (fila->contador == 0) {

        fila->inicio = aux;
        fila->fim = aux;
        aux->proximo = NULL;

    } else {

        aux->proximo = NULL;
        fila->fim->proximo = aux;
        fila->fim = fila->fim->proximo;

    }

    fila->contador++;

}

int removerFila(filaDinamica *fila) {

    if (!estaVazia == 1) {
        int ret;
        ret = -1;
        return ret;

    } else {

        ptrNoFila aux;

        aux = fila->inicio;
        fila->inicio = fila->inicio->proximo;

        int ret = aux->obj.key;
        free(aux);

        fila->contador--;

        return (ret);

    }
}

void imprimeFila(filaDinamica *fila) {

    ptrNoFila aux;

    aux = fila->inicio;

    printf("[");
    while (aux->proximo != NULL) {
        printf("%i, ", aux->obj.key);
        aux = aux->proximo;
    }
    printf("%i]\n", aux->obj.key);
}

int maiorValorFila(filaDinamica *fila) {

    int maiorValor = 0;
    ptrNoFila aux;
    aux = fila->inicio;

    while (aux != NULL) {
        if (aux == fila->inicio) {
            maiorValor = aux->obj.key;
        } else {
            if (aux->obj.key > maiorValor) {
                maiorValor = aux->obj.key;
            }
        }
        aux = aux->proximo;
    }

    return maiorValor;
}

void bfsMatriz(tipoMatriz **matriz, Grafo mapaGrafo[], int indiceInicial, int tamMatriz) {

    int linhaInicial, colunaInicial;

    for (int i = 0; i < tamMatriz; i++) {
        for (int j = 0; j < tamMatriz; j++) {
            if (matriz[i][j].qualGrafo == indiceInicial) {
                linhaInicial = matriz[i][j].linha;
                colunaInicial = matriz[i][j].coluna;
            }
        }
    }

    printf("\n");
    printf("Linha inicial: %i\n", linhaInicial);
    printf("Coluna inicial: %i\n", colunaInicial);

    for (int i = 0; i < tamMatriz; i++) {
        for (int j = 0; j < tamMatriz; j++) {
            printf("%i\t", matriz[i][j].qualGrafo);
        }
        printf("\n");
    }

}

int main(int argc, char** argv) {

    FILE *entrada = fopen("input.txt", "r");
    FILE *saida = fopen("output.txt", "w");

    if (entrada == NULL || saida == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    char ver1, ver2, ver3, string[100];
    int inteiro = 0, tamMatriz = 0, indiceInicial = 0;
    filaDinamica fila;
    iniciaFila(&fila);

    ver1 = fgetc(entrada);
    fscanf(entrada, "%*[^\n]\n");

    ver2 = fgetc(entrada);
    fscanf(entrada, "%*[^\n]\n");

    fgets(string, 100, entrada);
    printf("%s\n", string);

    ver3 = fgetc(entrada);
    indiceInicial = atoi(&ver3);
    printf("VERTICE INICAL NÙEMRO:%i\n", indiceInicial);


    inteiro = atoi(strtok(string, "(,)\n "));
    while (inteiro != 0) {
        inserirFila(&fila, inteiro);
        inteiro = atoi(strtok(NULL, "(,)\n "));
    }

    tamMatriz = maiorValorFila(&fila);

    tipoMatriz **matriz;
    Grafo mapaGrafo[tamMatriz];

    matriz = (tipoMatriz **) malloc(tamMatriz * sizeof (tipoMatriz *));
    for (int i = 0; i < tamMatriz; i++) {
        matriz[i] = (tipoMatriz *) malloc(tamMatriz * sizeof (tipoMatriz));
    }

    for (int i = 0; i < tamMatriz; i++) {
        for (int j = 0; j < tamMatriz; j++) {
            matriz[i][j].linha = i;
            matriz[i][j].coluna = j;
            matriz[i][j].numero = 0;
            matriz[i][j].qualGrafo = -1;
        }
    }

    int linha, coluna, contGrafos = 1;

    while (fila.contador != 0) {
        linha = removerFila(&fila);
        coluna = removerFila(&fila);
        matriz[linha - 1][coluna - 1].numero = 1;
        matriz[linha - 1][coluna - 1].qualGrafo = contGrafos;
        contGrafos++;
    }


    bfsMatriz(matriz, mapaGrafo, indiceInicial, tamMatriz);

    return (EXIT_SUCCESS);
}

