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
    int f;
    int pai;
    int linha;
} Grafo;

typedef struct NoLista *PtrNoLista;

typedef struct NoLista {
    Objeto obj;
    PtrNoLista prox;
    PtrNoLista ante;
} NoLista;

typedef struct {
    int tamanho;
    PtrNoLista inicio;
} Lista;

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

void bfsMatriz(int **matriz, Grafo mapaGrafo[], int tamMatriz, int contGrafos, int indiceInicial, FILE *saida) {

    filaDinamica fila;
    iniciaFila(&fila);
    int inteiro = 0;


    for (int i = 0; i < contGrafos; i++) {
        if (i != indiceInicial) {
            mapaGrafo[i].cor = 'b';
            mapaGrafo[i].d = 999;
            mapaGrafo[i].pai = -1;
        }
    }

    mapaGrafo[indiceInicial].cor = 'c';
    mapaGrafo[indiceInicial].d = 0;
    mapaGrafo[indiceInicial].pai = -1;

    inserirFila(&fila, indiceInicial);

    while (fila.contador != 0) {
        inteiro = removerFila(&fila);
        for (int i = 0; i < tamMatriz; i++) {
            if (matriz[inteiro][i] == 1 && mapaGrafo[i].cor == 'b') {
                mapaGrafo[i].cor = 'c';
                mapaGrafo[i].d = mapaGrafo[inteiro].d + 1;
                mapaGrafo[i].pai = inteiro + 1;
                inserirFila(&fila, i);
            }
        }
        mapaGrafo[inteiro].cor = 'p';
    }

    for (int i = 0; i < tamMatriz; i++) {
        fprintf(saida, "%i[d: %i]\n", i + 1, mapaGrafo[i].d);
    }

}

void dfs_visit(int **matriz, Grafo mapaGrafo[], int tamMatriz, int *tempo, int indice) {

    *tempo = *tempo + 1;
    mapaGrafo[indice].d = *tempo;
    mapaGrafo[indice].cor = 'c';

    for (int i = 0; i < tamMatriz; i++) {
        if (matriz[indice][i] == 1 && mapaGrafo[i].cor == 'b') {
            mapaGrafo[i].pai = indice;
            dfs_visit(matriz, mapaGrafo, tamMatriz, tempo, i);
        }
    }
    mapaGrafo[indice].cor = 'p';
    *tempo = *tempo + 1;
    mapaGrafo[indice].f = *tempo;

}

void dfsMatriz(int **matriz, Grafo mapaGrafo[], int tamMatriz, int contGrafos, int indiceInicial, FILE *saida) {

    for (int i = 0; i < contGrafos; i++) {
        mapaGrafo[i].cor = 'b';
        mapaGrafo[i].pai = -1;
    }

    int tempo = 0;

    for (int i = 0; i < tamMatriz; i++) {
        if (mapaGrafo[i].cor == 'b') {
            dfs_visit(matriz, mapaGrafo, tamMatriz, &tempo, i);
        }
    }

    for (int i = 0; i < tamMatriz; i++) {
        fprintf(saida, "%i[d: %i][f: %i]\n", i + 1, mapaGrafo[i].d, mapaGrafo[i].f);
    }
}

void iniciaLista(Lista *l) {
    l->inicio = NULL;
    l->tamanho = 0;
}

int insereElemento(Lista *l, int chave) {

    PtrNoLista novo;

    novo = (PtrNoLista) malloc(sizeof (NoLista));
    novo->obj.key = chave;

    if (l->inicio == NULL || chave < l->inicio->obj.key) {

        novo->prox = l->inicio;
        novo->ante = NULL;
        l->inicio = novo;
        l->tamanho += 1;
        return chave;

    }

    PtrNoLista aux;

    aux = l->inicio;

    while (aux->prox != NULL && chave > aux->prox->obj.key) {
        aux = aux->prox;
    }

    novo->prox = aux->prox;
    aux->prox = novo;
    novo->ante = aux;
    l->tamanho += 1;
}

void inserirListainFila(filaDinamica *fila, Lista *listVector) {

    PtrNoLista aux;
    aux = listVector->inicio;

    while (aux != NULL) {
        inserirFila(fila, aux->obj.key);
        aux = aux->prox;
    }
}

bool pesquisaElemento(Lista *l, int chave) {

    PtrNoLista aux;
    aux = l->inicio;

    if (l->tamanho == 0) {
        return false;
    }

    while (aux != NULL && chave > aux->obj.key) {
        aux = aux->prox;
    }

    if (aux == NULL || chave < aux->obj.key) {
        return false;
    } else {
        return true;
    }

}

void bfsLista(Lista listVector[], Grafo mapaGrafo[], int contGrafos, int indiceInicial, FILE *saida) {

    filaDinamica fila;
    iniciaFila(&fila);
    int inteiro = 0;

    for (int i = 0; i < contGrafos; i++) {
        if (i != indiceInicial) {
            mapaGrafo[i].cor = 'b';
            mapaGrafo[i].d = 999;
            mapaGrafo[i].pai = -1;
        }
    }

    mapaGrafo[indiceInicial].cor = 'c';
    mapaGrafo[indiceInicial].d = 0;
    mapaGrafo[indiceInicial].pai = -1;

    inserirListainFila(&fila, &listVector[indiceInicial]);

    while (fila.contador != 0) {
        inteiro = removerFila(&fila);
        for (int i = 0; i < contGrafos; i++) {
            if (pesquisaElemento(&listVector[indiceInicial], i) == true && mapaGrafo[i].cor == 'b') {
                mapaGrafo[i].cor = 'c';
                mapaGrafo[i].d = mapaGrafo[indiceInicial].d + 1;
                mapaGrafo[i].pai = indiceInicial + 1;
                inserirListainFila(&fila, &listVector[i]);
                indiceInicial = inteiro;
            }
        }
        mapaGrafo[inteiro].cor = 'p';
    }

    for (int i = 0; i < contGrafos; i++) {
        fprintf(saida, "%i[d: %i]\n", i, mapaGrafo[i].d);
    }

}

void dfs_visitLista(Lista listVector[], Grafo mapaGrafo[], int contGrafos, int indiceInicial, int *tempo, int indice) {

    *tempo = *tempo + 1;
    mapaGrafo[indice].d = *tempo;
    mapaGrafo[indice].cor = 'c';

    for (int i = 0; i < contGrafos; i++) {
        if (pesquisaElemento(&listVector[indice], i) == true && mapaGrafo[i].cor == 'b') {
            mapaGrafo[i].pai = indice;
            dfs_visitLista(listVector, mapaGrafo, contGrafos, indiceInicial, tempo, i);
        }
    }
    mapaGrafo[indice].cor = 'p';
    *tempo = *tempo + 1;
    mapaGrafo[indice].f = *tempo;

}

void dfsLista(Lista listVector[], Grafo mapaGrafo[], int contGrafos, int indiceInicial, FILE *saida) {

    for (int i = 0; i < contGrafos; i++) {
        mapaGrafo[i].cor = 'b';
        mapaGrafo[i].pai = -1;
    }

    int tempo = 0;

    for (int i = 0; i < contGrafos; i++) {
        if (mapaGrafo[i].cor == 'b') {
            dfs_visitLista(listVector, mapaGrafo, contGrafos, indiceInicial, &tempo, i);
        }
    }

    for (int i = 0; i < contGrafos; i++) {
        fprintf(saida, "%i[d: %i][f: %i]\n", i + 1, mapaGrafo[i].d, mapaGrafo[i].f);
    }

}

int main(int argc, char** argv) {

    if (argc != 3) {
        printf("Muito ou poucos arquivos para o programa");
        exit(1);
    }

    FILE *entrada = fopen(argv[1], "r");
    FILE *saida = fopen(argv[2], "w");

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

    ver3 = fgetc(entrada);
    indiceInicial = atoi(&ver3) - 1;

    inteiro = atoi(strtok(string, "(,)\n "));
    while (inteiro != 0) {
        inserirFila(&fila, inteiro);
        inteiro = atoi(strtok(NULL, "(,)\n "));
    }

    tamMatriz = maiorValorFila(&fila);
    Grafo mapaGrafo[tamMatriz - 1];

    if (ver1 == 'M' || ver1 == 'm') {

        int **matriz;

        matriz = (int **) malloc(tamMatriz * sizeof (int *));
        for (int i = 0; i < tamMatriz; i++) {
            matriz[i] = (int *) malloc(tamMatriz * sizeof (int));
        }

        for (int i = 0; i < tamMatriz; i++) {
            for (int j = 0; j < tamMatriz; j++) {
                matriz[i][j] = 0;
            }
        }

        int linha, coluna, contGrafos = tamMatriz;

        while (fila.contador != 0) {
            linha = removerFila(&fila);
            coluna = removerFila(&fila);
            matriz[linha - 1][coluna - 1] = 1;
        }

        if (ver2 == 'B' || ver2 == 'b') {
            bfsMatriz(matriz, mapaGrafo, tamMatriz, contGrafos, indiceInicial, saida);
        } else if (ver2 == 'D' || ver2 == 'd') {
            dfsMatriz(matriz, mapaGrafo, tamMatriz, contGrafos, indiceInicial, saida);
        } else {
            printf("Letra não prevista");
        }

        for (int i = 0; i < tamMatriz; i++) {
            free(matriz[i]);
        }
        free(matriz);

    } else if (ver1 = 'L' || ver1 == 'l') {

        int linha;
        int coluna;

        Lista listVector[tamMatriz - 1];
        for (int i = 0; i < tamMatriz; i++) {
            iniciaLista(&listVector[i]);
        }


        while (fila.contador != 0) {
            linha = removerFila(&fila);
            coluna = removerFila(&fila);
            insereElemento(&listVector[linha - 1], coluna - 1);
        }


        if (ver2 == 'B' || ver2 == 'b') {
            bfsLista(listVector, mapaGrafo, tamMatriz, indiceInicial, saida);
        } else if (ver2 == 'D' || ver2 == 'd') {
            dfsLista(listVector, mapaGrafo, tamMatriz, indiceInicial, saida);
        } else {
            printf("Letra não prevista");
        }

    } else {
        printf("Letra não prevista");
        exit(1);
    }
    return (EXIT_SUCCESS);
}
