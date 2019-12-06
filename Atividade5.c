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
    char cor;
    int d;
    int pai;
    int linha;
    int coluna;
    int qualGrafo;
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

void bfsMatriz(int **matriz, Grafo mapaGrafo[], int tamMatriz, int contGrafos, int indiceInicial) {

  filaDinamica fila;
  iniciaFila(&fila);

    for(int i = 0; i < contGrafos; i++){
        if(i != indiceInicial){
          mapaGrafo[i].cor = 'b';
          mapaGrafo[i].d = 999;
          mapaGrafo[i].pai = -1;
        }
    }

    mapaGrafo[indiceInicial].cor = 'c';
    mapaGrafo[indiceInicial].d = '0';
    mapaGrafo[indiceInicial].pai = -1;

    for(int i = 0; i < tamMatriz; i++ ){
      for(int j = 0; j < tamMatriz; j++){
        
      }
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

    int **matriz;
    Grafo mapaGrafo[tamMatriz];

    matriz = (int **) malloc(tamMatriz * sizeof (int *));
    for (int i = 0; i < tamMatriz; i++) {
        matriz[i] = (int *) malloc(tamMatriz * sizeof (int));
    }

    for (int i = 0; i < tamMatriz; i++) {
        for (int j = 0; j < tamMatriz; j++) {
            matriz[i][j] = 0;
        }
    }

    int linha, coluna, contGrafos = 0;

    while (fila.contador != 0) {
        linha = removerFila(&fila);
        coluna = removerFila(&fila);
        mapaGrafo[contGrafos].qualGrafo = contGrafos;
        mapaGrafo[contGrafos].linha = linha;
        mapaGrafo[contGrafos].coluna = coluna;
        contGrafos++;
    }

    bfsMatriz(matriz, mapaGrafo, tamMatriz, contGrafos, indiceInicial);

    return (EXIT_SUCCESS);
}
