#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int chave;
}Objeto;

typedef struct NoArvore *PtrNoArvore;

typedef struct NoArvore{
    PtrNoArvore direita;
    PtrNoArvore esquerda;
    Objeto obj;
}NoArvore;

iniciaArvore(PtrNoArvore *arvore){
    *arvore  = NULL;
}

estaVazia(PtrNoArvore *arvore){
    return(*arvore == NULL);
}

bool insercao(PtrNoArvore *arvore, Objeto obj){
    
    if((*arvore) == NULL){
        *arvore = malloc(sizeof(NoArvore));
        (*arvore)->esquerda = (*arvore)->esquerda = NULL;
        (*arvore).obj = obj;
        return true;
    }
  
    if((*arvore)->obj.chave == obj.chave){
        printf("Chave duplicada, não inserindo...");
        return false;
    }
    
    if((*arvore).obj.chave > obj.chave){
        return(insercao(&(*arvore)->esquerda, obj));
    }
    
    else if((*arvore).obj.chave < obj.chave){
        return(insercao(&(*arvore)->direita, obj));
    }
    
}

int main(int argc, char** argv) {

    
    PtrNoArvore raiz;
    
    
    return (EXIT_SUCCESS);
}

