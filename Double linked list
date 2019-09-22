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

bool pesquisaElemento(Lista *l, int chave) {

    PtrNoLista aux;
    aux = l->inicio;

    if (estaVazia(l) == true) {
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

Objeto removeChave(Lista *l, Objeto *obj) {

    printf("Elemento remover: ");
    scanf("%i", &obj->key);

    Objeto ret;

    if (estaVazia(l) == true) {
        return ret;
    }

    PtrNoLista aux;
    aux = l->inicio;

    if (l->inicio->obj.key == obj->key) {
        ret = aux->obj;
        l->inicio = l->inicio->prox;
        l->tamanho = 1;
        aux->prox->ante = NULL;
        free(aux);
        return ret;
    }

    if (pesquisaElemento(l, obj->key) == true) {

        while (aux != NULL && obj->key > aux->obj.key) {
            aux = aux->prox;
        }

        if (aux->prox == NULL) {
            ret = aux->obj;
            aux->ante->prox = NULL;
            l->tamanho -= 1;
            free(aux);

        } else {

            ret = aux->obj;
            aux->ante->prox = aux->prox;
            aux->prox->ante = aux->ante;
            free(aux);
            l->tamanho -= 1;
            return ret;
        }
    } else {
        printf("Não tem na lista seu otário\n");
        return ret;
    }


}

Objeto removePrimeiro(Lista *l) {

    PtrNoLista aux;
    aux = l->inicio;

    Objeto ret;

    if (estaVazia(l) == true) {
        return ret;
    }

    ret = aux->obj;
    l->inicio = l->inicio->prox;
    aux->prox->ante = NULL;
    free(aux);
    return ret;

}

Objeto removeUltimo(Lista *l) {

    PtrNoLista aux;
    aux = l->inicio;

    Objeto ret;

    if (estaVazia(l) == true) {
        return ret;
    }

    while (aux->prox != NULL) {
        aux = aux->prox;
    }


    ret = aux->obj;
    aux->ante->prox = NULL;
    free(aux);
    return ret;

}

void imprimeLista(Lista *l) {

    PtrNoLista aux;
    aux = l->inicio;

    while (aux != NULL) {
        printf("%i ", aux->obj.key);
        aux = aux->prox;
    }


    printf("\n");
}

void imprimeContrario(Lista *l) {
    PtrNoLista aux;
    aux = l->inicio;

    while (aux->prox
            != NULL) {
        aux = aux->prox;
    }

    while (aux != NULL) {
        printf("%i ", aux->obj.key);
        aux = aux->ante;
    }

    printf("\n");

}

void destroy(Lista *l) {

    while (l->inicio != NULL) {
        PtrNoLista aux;
        
        aux = l->inicio;
        free(aux);
        l->inicio = l->inicio->prox;
    }
    
    free(l->inicio);

}

int main(int argc, char** argv) {

    int escolha = 0, item = 0;
    Lista l;
    Objeto obj;

    do {

        printf("[0] - Inicia Lista.\n"
                "[1] - Tamanho\n"
                "[2] - Esta Vazia?\n"
                "[3] - Insere Elemento\n"
                "[4] - Pesquisa Elemento\n"
                "[5] - Remove Chave\n"
                "[6] - Remove Primeiro\n"
                "[7] - Remove Ultimo\n"
                "[8] - Imprime Lista\n"
                "[9] - Imprime Lista ao Contrário\n"
                "[10] - Primeiro Elemento\n"
                "[11] - Ultimo Elemento\n"
                "[12] - Destruir\n");
        scanf("%i", &escolha);

        switch (escolha) {

            case 0:
                iniciaLista(&l);
                system("clear");
                printf("Lista iniciada.\n");
                break;
            case 1:
                printf("Tamanho: %i\n", l.tamanho);
                break;
            case 2:
                system("clear");
                if (estaVazia(&l) == true)printf("Vazia\n");
                else printf("Não vazia\n");
                break;
            case 3:
                printf("Item: ");
                scanf("%i", &item);
                system("clear");
                insereElemento(&l, item);
                imprimeLista(&l);
                break;
            case 4:
                system("clear");
                printf("Elemtento: ");
                scanf("%i", &item);

                if (pesquisaElemento(&l, item) == true)printf("Achado\n");
                else printf("Não achado\n");
                break;
            case 5:
                system("clear");
                removeChave(&l, &obj);
                imprimeLista(&l);
                break;
            case 6:
                system("clear");
                removePrimeiro(&l);
                imprimeLista(&l);
                break;
            case 7:
                system("clear");
                removeUltimo(&l);
                imprimeLista(&l);
            case 8:
                system("clear");
                imprimeLista(&l);
                break;
            case 9:
                system("clear");
                imprimeContrario(&l);
                break;
            case 12:
                system("clear");
                destroy(&l);
        }
        

        //printf("\n\t%i\t\n", l.inicio->prox->prox->ante->obj.key);

    } while (escolha != 12);


    printf("Acabou, você acabou com tudo.");


    return (EXIT_SUCCESS);
}

