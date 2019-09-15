#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 10

typedef struct {
    int key;
} objeto;

typedef struct {
    objeto vetor[N];
    int topo;
} pilhaEstatica;

void iniciaPilha(pilhaEstatica *pilha) {

    pilha->topo = 0;
    system("clear");
    printf("Pilha iniciada.\n");
}

bool estaCheia(pilhaEstatica *pilha) {

    if (pilha->topo == N) {
        return true;
    } else {
        return false;
    }

}

bool estaVazia(pilhaEstatica *pilha) {

    if (pilha->topo == 0) {
        return true;
    } else {
        return false;
    }

}

void push(pilhaEstatica *pilha, objeto objetoPilha) {


    if (estaCheia(pilha) == false) {
        printf("Qual elemento colocar: ");
        scanf("%i", &objetoPilha.key);

        pilha->vetor[pilha->topo].key = objetoPilha.key;
        pilha->topo += 1;
    } else {
        printf("Pilha cheia.\n");
    }


}

void pop(pilhaEstatica *pilha, objeto *objetoPilha) {

    if (estaVazia(pilha) == false) {
        objetoPilha->key = pilha->vetor[pilha->topo].key;
        pilha->topo -= 1;
    } else {
        printf("Pilha já vazia\n");
    }
}

int size(pilhaEstatica *pilha) {

    printf("Tamanho da pilha: %i\n", pilha->topo);

}

objeto top(pilhaEstatica *pilha) {
    objeto bisoiada;

    system("clear");
    if (estaVazia(pilha) == 1) {
        printf("Sem elementos para olhar");
    } else {


        bisoiada.key = pilha->vetor[pilha->topo - 1].key;
        pilha->topo -= 1;

        printf("Carta topo: %i\n", bisoiada.key);

        pilha->topo += 1;
        pilha->vetor[pilha->topo].key = bisoiada.key;

    }
    return bisoiada;
}

void imprimirPilha(pilhaEstatica *pilha) {
    printf("---\n");
    for (int i = pilha->topo - 1; i >= 0; i--) {
        printf("|%i|\n", pilha->vetor[i].key);
        printf("---\n");
    }
    printf("\n");
}

int main() {

    int escolha = 0;

    pilhaEstatica pilha;
    objeto objetoPilha;


    do {
        printf("[1] - Inicia pilha\n"
                "[2] - Está vazia\n"
                "[3] - Está Cheia\n"
                "[4] - Push\n"
                "[5] - Pop\n"
                "[6] - Size\n"
                "[7] - Top\n");
        scanf("%i", &escolha);

        switch (escolha) {
            case 1:
                iniciaPilha(&pilha);
                break;
            case 2:
                system("clear");
                if (estaVazia(&pilha) == 1) {
                    printf("Pilha vazia.\n");
                } else {
                    printf("Há conteúdo na pilha.\n");
                }
                break;
            case 3:
                system("clear");
                if (estaCheia(&pilha) == 1) {
                    printf("Pilha cheia.\n");
                } else {
                    printf("Pilha não cheia.\n");
                }

                break;
            case 4:
                push(&pilha, objetoPilha);
                system("clear");
                imprimirPilha(&pilha);

                break;
            case 5:
                pop(&pilha, &objetoPilha);
                system("clear");
                imprimirPilha(&pilha);

                break;
            case 6:
                system("clear");
                size(&pilha);
                imprimirPilha(&pilha);

                break;
            case 7:
                objetoPilha = top(&pilha);
                imprimirPilha(&pilha);
                break;
        }
    } while (1);


    return 0;
}
