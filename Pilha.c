#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 100

//=================================================================================

typedef struct {
    int key;
} Objeto;

//=================================================================================

typedef struct NoPilha *ptrNoPilha;

typedef struct {
    Objeto obj;
    ptrNoPilha proximo;
} noPilha;

typedef struct {
    ptrNoPilha topo;
    int tamanho;
} pilhaDinamica;

//=================================================================================

void iniciaDinamica(pilhaDinamica *pilhaDinamica) {
    pilhaDinamica->topo = NULL;
    pilhaDinamica->tamanho = 0;
}

bool vaziaDinamica(pilhaDinamica *pilhaDinamica) {
    return (pilhaDinamica->topo == NULL);
}

void pushDinamica(Objeto obj, pilhaDinamica *pilhaDinamica) {

    ptrNoPilha *aux = NULL;
    aux = (noPilha*) malloc(sizeof (noPilha));
  //  aux->obj = obj;
  //  aux->proximo = pilhaDinamica->topo;
    pilhaDinamica->topo = aux;
    pilhaDinamica->tamanho++;

}

void popDinamica(pilhaDinamica *pilhaDinamica) {

}

//=================================================================================

typedef struct {
    Objeto vetor[100];
    int topo;
} pilhaEstatica;

//=================================================================================

void iniciaEstatica(pilhaEstatica *pilhaEst) {
    pilhaEst->topo = 0;
}

bool cheiaEstatica(pilhaEstatica *pilhaEst) {
    
    if (pilhaEst->topo == N) {
        return true;
    } else {
        return false;
    }
}

bool vaziaEstatica(pilhaEstatica *pilhaEst) {

    if (pilhaEst->topo == 0) {
        return true;
    } else {
        return false;
    }
}
void pushEstatica(Objeto obj ,pilhaEstatica *pilhaEst){
    
    if(cheiaEstatica(pilhaEst) == false){
        pilhaEst->vetor[pilhaEst->topo].key = obj;
        pilhaEst->topo += 1;
    }else{
        printf("Pilha cheia seu otário");
    }
}

Objeto popEstatica(Objeto obj ,pilhaEstatica *pilhaEst){
    
    if(vaziaEstatica(pilhaEst) == false){
        obj.key = pilhaEst->vetor[pilhaEst->topo];
        pilhaEst->topo -= 1;
        
        return obj;
    }else{
        printf("Pilha já vazia seu otário");
    }
    
}



//=================================================================================

void escolhaDinamica(pilhaDinamica *pilhaValores) {

    int objetoAux;

    iniciaDinamica(&pilhaValores);
    while (feof(arqEntrada) == 0) {

        fscanf(arqEntrada, "%d", &objetoAux);
        //empilha(objetoAux, &pilhaValores);

    }
}

//=================================================================================

int binario(int num) {

    if (num == 0)
        return 0;
    else
        return (num % 2 + 10 * binario(num / 2));
    
}

void escolhaEstatica(pilhaDinamica *pilhaValores) {

    pilhaEstatica pilhaEst;
    Objeto auxiliar = 0;
    
    iniciaEstatica(&pilhaEst);
    
    
    for(int i = pilhaValores->topo; i>=0; i++){
        auxiliar.key = popDinamica(&pilhaValores);
        auxiliar.key = binario(auxiliar.key);
        pushEstatica(auxiliar, pilhaEst);
    }
    
}

//=================================================================================

void arqEntrada(pilhaDinamica *pilhaValores) {


    FILE *arqEntrada = NULL;
    arqEntrada = fopen("entrada.txt", "r");

    if (arqEntrada == NULL) {
        printf("Erro.");
        exit(1);
    }

    char verificacao;
    fscanf(arqEntrada, "%c", &verificacao);
    
    //Iniciação da pilhaValores

    if (verificacao == 'd') {
        escolhaDinamica(&pilhaValores);
    } else if (verificacao == 'e') {
        escolhaEstatica(&pilhaValores);
    } else {
        printf("Erro.");
        exit(1);
    }

}


//=================================================================================

int main(int argc, char** argv) {

    pilhaDinamica pilhaValores;

    arqEntrada(&pilhaValores);

    return (EXIT_SUCCESS);
}
