#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 10

typedef struct {
    int key;
} Objeto;

typedef struct {
    int comeco;
    int fim;
    Objeto array[N];
    int contador;
} filaEstatica;

void iniciar(filaEstatica *fila) {
    fila->comeco = 0;
    fila->fim = -1;
    fila->contador = 0;
}

bool estaVazia(filaEstatica *fila) {
    return (fila->contador == 0);
}

bool estaCheia(filaEstatica *fila) {
    return (fila->contador == N);
}

int incrementar(int indice) {

    indice++;
    if (indice % N == 0) {
        indice = 0;
    }
    return indice;

}

void inserir(filaEstatica *fila) {

    int item = 0;
    if (estaCheia(fila) == 0) {
        printf("item: ");
        scanf("%i", &item);

        fila->fim = incrementar(fila->fim);

        fila->array[fila->fim].key = item;
        fila->contador++;
    } else {
        printf("Está cheia seu otário\n");
    }

}

Objeto remover(filaEstatica *fila) {

    Objeto devolver;

    if (estaVazia(fila) == 0) {
        devolver = fila->array[fila->comeco];
        fila->comeco = incrementar(fila->comeco);
        fila->contador--;
        return devolver;
    }else{
        printf("Já tá vazia seu otário\n");
        return devolver;
    }

}

void imprimeFila(filaEstatica *fila){
    
    for(int i = fila->comeco; i != fila->fim + 1; i++){
        if(i % N == 0){
            i = 0;
        }
        printf("|%i", fila->array[i].key);
    }
    printf("\n");
    
}

int main(int argc, char** argv) {

    int escolha = 0;

    filaEstatica fila;
    Objeto objetofila;


    do {
        printf("[1] - Inicia fila\n"
                "[2] - Está vazia\n"
                "[3] - Está Cheia\n"
                "[4] - Inserir\n"
                "[5] - Pop\n"
                "[6] - Size\n"
                "[7] - Primeiro\n"
                "[8] - Último\n");
        scanf("%i", &escolha);

        switch (escolha) {
            case 1:
                iniciar(&fila);
                system("clear");
                printf("Fila iniciada\n");
                break;
                
            case 2:
               
                system("clear");
                if(estaVazia(&fila) == 1){
                    printf("Vazia.\n");
                }else{
                    printf("Não vazia.\n");
                }
                break;
                
            case 3:
                
                system("clear");
                if(estaCheia(&fila) == 1){
                    printf("Cheia.\n");
                }else{
                    printf("Não cheia.\n");
                }
                
                break;
            case 4:
                inserir(&fila);
                system("clear");
                imprimeFila(&fila);
                break;
            case 5:
                system("clear");
                objetofila = remover(&fila);
                imprimeFila(&fila);
                break;
            case 6:
                system("clear");
                printf("Tamanho: %i\n", fila.contador);
                imprimeFila(&fila);
                break;
            case 7:
                system("clear");
                printf("Começo: %i\n", fila.array[fila.comeco].key);
                imprimeFila(&fila);
                break;
            case 8:
                system("clear");
                printf("Final: %i\n", fila.array[fila.fim].key);
                imprimeFila(&fila);
                break;
        }
    } while (1);

    return (EXIT_SUCCESS);
}

