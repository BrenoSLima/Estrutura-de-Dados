#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int key;
} Objeto;

typedef struct NoArvAVL *PtrNoArvAVL;

typedef struct NoArvAVL {
    PtrNoArvAVL esquerda;
    PtrNoArvAVL direita;
    Objeto obj;
    int altura;
} NoArvAVL;

int alturaArv(PtrNoArvAVL *arvore) {
    int altura = 0;
    int alturaE;
    int alturaD;
    if ((*arvore) == NULL)return 0;
    else {

         alturaE = alturaArv(&(*arvore)->esquerda);
         alturaD = alturaArv(&(*arvore)->direita);

    }

    if(alturaE > alturaD){
        return (alturaE + 1);
    }else{
        return(alturaD +1);
    }


}

void rotSingDir(PtrNoArvAVL *P) {

}

void rotSingEsq(PtrNoArvAVL *p) {

}

void rotacao(PtrNoArvAVL *P) {

    PtrNoArvAVL U, V;
    U = (*P)->esquerda->altura;
    V = (*P)->direita->altura;

    if (V->altura - U->altura == -2) {



    }

    if (V->altura - U->altura == 2) {




    }


}

bool insercaoAVL(PtrNoArvAVL *arvoreAVL, int x) {

    if ((*arvoreAVL) == NULL) {
        arvoreAVL = malloc(sizeof (NoArvAVL));
        arvoreAVL->obj.key = x;
        arvoreAVL->altura = 1;
        arvoreAVL->direita = NULL;
        arvoreAVL->esquerda = NULL;
        return true;
    }

    if ((*arvoreAVL)->obj.key == x) {
        return false;
    }

    bool check;
    if (x < (*arvoreAVL)->obj.key) {
        check = insercaoAVL(&(*arvoreAVL)->esquerda, x);
    } else {
        check = insercaoAVL(&(*arvoreAVL)->direita, x);
    }

    if (check == false)return false;

    int alturaE, alturaD;

    alturaE = (*arvoreAVL)->esquerda->altura;
    alturaD = (*arvoreAVL)->direita->altura;

    if (alturaD - alturaE == -2 || alturaD - alturaE == 2) {
        rotacao(&(*arvoreAVL));
    }

    //(*arvoreAVL)->altura = attAltura()

}

int main(int argc, char** argv) {

    PtrNoArvAVL raiz;

    return (EXIT_SUCCESS);
}

