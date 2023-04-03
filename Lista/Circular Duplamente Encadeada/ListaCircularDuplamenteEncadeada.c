#include <stdio.h>
#include <stdlib.h>
#include "ListaCircularDuplamenteEncadeada.h"

struct no{
    int n;
    struct no *prox;
    struct no *ant;
};

typedef struct no No;

Lista* CriaLista(){
    Lista* l = (Lista *) malloc(sizeof(Lista));
    if(l != NULL){
        *l = NULL;
    }
    return l;
}

void LiberaLista(Lista* l){
    if((l != NULL)&&((*l) != NULL)){
        No *aux, *no = *l;
        while((*l) != no->prox){
            aux = no;
            no = no->prox;
            free(aux);
        }
        free(no);
        free(aux);
    }
}

int TamanhoLista(Lista* l){
    if((l == NULL)||((*l) == NULL)){
        return 0;
    }
    int cont = 0;
    No *no = *l;
    do{
        cont++;
        no = no->prox;
    }while(no != (*l));
    return cont;
}

int ListaVazia(Lista* l){
    if((l == NULL)||((*l) == NULL)){
        return 1;
    }else{
        return 0;
    }
}

int InsereInicio(Lista* l, int n){
    if(l == NULL){
        return 0;
    }
    No *no = (No *) malloc(sizeof(No));
    if(no == NULL){
        return 0;
    }
    no->n = n;
    no->ant = NULL;
    if((*l) == NULL){// lista vazia
        *l = no;
        no->prox = no;
        no->ant = no;
    }else{
        No *aux = *l;
        while(aux->prox != (*l)){
            aux = aux->prox;
        }
        aux->prox = no;
        (*l)->ant = no;
        no->prox = *l;
        no->ant = aux;
        *l = no;
    }
    return 1;
}

int InsereFinal(Lista* l, int n){
    if(l == NULL){
        return 0;
    }
    No* no = (No *) malloc(sizeof(No));
    if(no == NULL){
        return 0;
    }
    no->n = n;
    if((*l) == NULL){
        *l = no;
        no->prox = no;
        no->ant = no;
    }else{
        No *aux = *l;
        while(aux->prox != (*l)){
            aux = aux->prox;
        }
        aux->prox = no;
        no->ant = aux;
        no->prox = *l;
        (*l)->ant = no;
    }
    return 1;
}

int InsereOrdenado(Lista* l, int n){
    if(l == NULL){
        return 0;
    }
    No *no = (No *) malloc(sizeof(No));
    if(no == NULL){
        return 0;
    }
    no->n = n;
    if((*l) == NULL){
        *l = no;
        no->prox = no;
        no->ant = no;
    }else{
        if((*l)->n > n){ // insere inicio
            No *aux = *l;
            while(aux->prox != (*l)){
                aux = aux->prox;
            }
                no->ant = aux;
                no->prox = *l;
                (*l)->ant = no;
                aux->prox = no;
                *l = no;
        }else{
            No *atual = (*l)->prox;
            while((atual != (*l))&&(atual->n < n)){
                atual = atual->prox;
            }
            atual->ant->prox = no;
            no->ant = atual->ant;
            no->prox = atual;
            atual->ant = no;
        }
    }
    return 1;
}

int RemoveInicio(Lista* l){
    if((l == NULL)||((*l) == NULL)){
        return 0;
    }
    if((*l) == (*l)->prox){
        free(*l);
        *l = NULL;
        return 1;
    }
    No *aux = *l;
    while(aux->prox != (*l)){
        aux = aux->prox;
    }
    No *no = *l;
    aux->prox = no->prox;
    *l = no->prox;
    no->prox->ant = aux;
    free(no);

    return 1;
}

int RemoveFinal(Lista* l){
    if((l == NULL)||((*l) == NULL)){
        return 0;
    }
    if((*l) == (*l)->prox){
        free(*l);
        *l = NULL;
        return 1;
    }
    No *no = *l;
    while(no->prox != (*l)){
        no = no->prox;
    }
    no->ant->prox = *l;
    (*l)->ant = no->ant;
    free(no);
    return 1;
}

int RemoveN(Lista* l, int n){
    if((l == NULL)||((*l) == NULL)){
        return 0;
    }
    No *no = *l;
    if(no->n == n){ //remover o primeiro
        if(no == no->prox){ //so tem 1
            free(no);
            *l = NULL;
            return 1;
        }else{
            No *ult = *l;
            while(ult->prox != (*l)){
                ult = ult->prox;
            }
            ult->prox = (*l)->prox;
            (*l)->prox->ant = ult;
            *l = (*l)->prox;
            free(no);
            return 1;
        }
    }

    no = no->prox;
    while((no != (*l))&&(no->n != n)){
        no = no->prox;
    }
    if(no == (*l)){ //nao encontrado
        return 0;
    }
    no->ant->prox = no->prox;
    no->prox->ant = no->ant;
    free(no);
    return 1;
}

int ConsultaPos(Lista* l, int pos, int *n){
    if((l == NULL)||((*l) == NULL)||(pos <= 0)){
        return 0;
    }
    No *no = *l;
    int i = 1;
    while((no->prox != (*l))&&(i < pos)){
        no = no->prox;
        i++;
    }
    if(i != pos){
        return 0;
    }else{
        *n = no->n;
        return 1;
    }
}

int ConsultaN(Lista* l, int n, int *pos){
    if((l == NULL)||((*l) == NULL)){
        return 0;
    }
    No *no = *l;
    int i = 1;
    while((no->prox != (*l))&&(no->n != n)){
        no = no->prox;
        i++;
    }
    if(no->n != n){
        return 0;
    }else{
        *pos = i;
        return 1;
    }
}

void ImprimirLista(Lista* l){
    if((l == NULL)||((*l) == NULL)){
        return;
    }
    No *no = *l;
    if(no == no->prox){
        printf("%d, ", no->n);
    }else{
        while(no->prox != (*l)){
            printf("%d, ", no->n);
            no = no->prox;
        }
        printf("%d", no->n);
    }
    return;
}

void ImprimirListaInverso(Lista* l){
    if((l == NULL)||((*l) == NULL)){
        return;
    }
    No *no = (*l);
    if(no == no->prox){
        printf("%d, ", no->n);
    }else{
        while(no->ant != (*l)){
            printf("%d, ", no->n);
            no = no->ant;
        }
        printf("%d", no->n);
    }
    return;
}



