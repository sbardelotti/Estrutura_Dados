#include <stdio.h>
#include <stdlib.h>
#include "ListaEncadeada.h"

struct no{
    int n;
    struct no *prox;
};

typedef struct no No;

Lista* CriaLista(){
    Lista* l = (Lista *) malloc(sizeof(Lista));
    if(l != NULL){
        // Se o ponteiro para ponteiro nao for nulo entao o ponteiro par que ele esta apontando e nulo
        *l = NULL;
    }
    return l;
}

void LiberaLista(Lista* l){
    if(l != NULL){
        No* no;
        while((*l) != NULL){
            no = *l;
            *l = (*l)->prox;
            free(no);
        }
        free(l);
    }
}

int TamanhoLista(Lista* l){
    if(l == NULL){
        return 0;
    }
    int i = 0;
    No* no = *l;
    while(no != NULL){
        i++;
        no = no->prox;
    }
    return i;
}

int ListaVazia(Lista* l){
    if((l == NULL)||(*l == NULL)){
        return 1;
    }
    return 0;
}

int InsereListaInicio(Lista* l, int n){
    if(l == NULL){
        return 0;
    }
    No* no = (No *) malloc(sizeof(No));
    if(no == NULL){
        return 0;
    }
    no->n = n;
    no->prox = (*l);
    *l = no;
    return 1;
}

int InsereListaFinal(Lista* l, int n){
    if(l == NULL){
        return 0;
    }
    No* no = (No *) malloc(sizeof(No));
    if(no == NULL){
        return 0;
    }
    no->n = n;
    no->prox = NULL;
    if((*l) == NULL){// lista vazia
        *l = no;
    }else{
        No *aux = *l;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}

int InsereListaOrdenada(Lista* l, int n){
    if(l == NULL){
        return 0;
    }
    No* no = (No *) malloc(sizeof(No));
    if(no == NULL){
        return 0;
    }
    no->n = n;
    if(ListaVazia(l)){
        no->prox = (*l);
        *l = no;
        return 1;
    }else{
        No *ant, *atual = *l;
        while((atual != NULL)&&(atual->n<n)){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *l){// insere no inicio
            no->prox = (*l);
            *l = no;
        }else{
            no->prox = ant->prox;
            ant->prox = no;
        }

        return 1;
    }
}

int RemoveListaInicio(Lista* l){
    if((l == NULL)||((*l) == NULL)){
        return 0;
    }
    No *no = *l;
    *l = no->prox;
    free(no);
    return 1;
}

int RemoveListaFinal(Lista* l){
    if((l == NULL)||((*l) == NULL)){
        return 0;
    }
    No *ant, *atual = *l;
    while(atual->prox != NULL){
        ant = atual;
        atual = atual->prox;
    }
    if(atual == (*l)){
        *l = atual->prox;
    }else{
        ant->prox = atual->prox;
    }
    free(atual);
    return 1;
}

int RemoveListaN(Lista* l, int n){
    if((l == NULL)||((*l) == NULL)){
        return 0;
    }
    No *ant, *atual = *l;
    while((atual != NULL)&&(atual->n != n)){
        ant = atual;
        atual = atual->prox;
    }
    if(atual == NULL){// nao encontrou
        return 0;
    }
    if(atual == *l){
        *l = atual->prox;
    }else{
        ant->prox = atual->prox;
    }
    free(atual);
    return 1;
}

int ConsultaListaPos(Lista* l, int pos, int *n){
    if((l == NULL)||(pos <= 0)){
        return 0;
    }
    No *no = *l;
    int i = 1;
    while((no != NULL)&&(i < pos)){
        no = no->prox;
        i++;
    }
    if(no == NULL){
        return 0;
    }else{
        *n = no->n;
        return 1;
    }
}

int ConsultaListaN(Lista* l, int proc, int *n){
    if((l == NULL)||((*l) == NULL)){
        return 0;
    }
    No *no = *l;
    int i = 1;
    while((no != NULL)&&(no->n != proc)){
        no = no->prox;
        i++;
    }
    if(no == NULL){
        return 0;
    }else{
        *n = i;
        return 1;
    }
}

void ImprimirLista(Lista* l){
    if((l == NULL)||((*l) == NULL)){
        return;
    }
    No *no = *l;
    while(no->prox != NULL){
        printf("%d - ", no->n);
        no = no->prox;
    }
    printf("%d", no->n);
}

int CopiaLista(Lista* l1, Lista* l2){
    if((l1 == NULL)||((*l1) == NULL)||(l2 == NULL)){
        return 0;
    }
    No *no = (*l1);
    InsereListaInicio(l2, no->n);
    while(no->prox != NULL){
        no = no->prox;
        InsereListaFinal(l2, no->n);
    }
    return 1;
}

Lista* CatLista(Lista* l1, Lista* l2){
    if((l1 == NULL)||((*l1) == NULL)||(l2 == NULL)||((*l2) == NULL)){
        return NULL;
    }
    Lista* cat = CriaLista();
    CopiaLista(l1, cat);
    No* no = (*l2);
    InsereListaFinal(cat, no->n);
    while(no->prox != NULL){
        no = no->prox;
        InsereListaFinal(cat, no->n);
    }
    return cat;
}

int ListaIgual(Lista* l1, Lista* l2){
    if((l1 == NULL)||(l2 == NULL)){
        return 0;
    }
    if(((*l1) == NULL)&&((*l2) == NULL)){
        return 1;
    }
    if(((*l1) == NULL)||((*l2) == NULL)){
        return 0;
    }
    No* no1 = (*l1);
    No* no2 = (*l2);
    while((no1->prox != NULL)||(no2->prox != NULL)){
        if(no1->n != no2->n){
            return 0;
        }
        no1 = no1->prox;
        no2 = no2->prox;
    }
    if(((no1->prox == NULL)&&(no2->prox != NULL))||((no1->prox != NULL)&&(no2->prox == NULL))){
        return 0;
    }
    return 1;
}

int TirarElementosRepetidos(Lista* l){
    if((l == NULL)||((*l) == NULL)){
        return 0;
    }
    No *aux, *ant, *no = (*l);
    while(no->prox != NULL){
        ant = no;
        aux = ant;
        no = no->prox;
        while(ant->prox != NULL){
            ant = ant->prox;
            if(aux->n == ant->n){
                RemoveListaN(l, aux->n);
            }
        }
    }
    return 1;
}

int OrdernarLista(Lista *l){
    if((l == NULL)||((*l) == NULL)){
        return 0;
    }
    // pense no aux como um anterior ao anterior
    No *aux, *ant, *no = (*l);
    int n;
    while(no->prox != NULL){
        ant = no;
        aux = ant;
        no = no->prox;
        while(ant->prox != NULL){
            ant = ant->prox;
            if(aux->n > ant->n){
                n = aux->n;
                aux->n = ant->n;
                ant->n = n;
            }
        }
    }
    return 1;
}

Lista* UniaoLista(Lista* l1, Lista* l2){
    Lista* uniao = CatLista(l1, l2);
    TirarElementosRepetidos(uniao);
    OrdernarLista(uniao);
    return uniao;
}

Lista* InterseccaoLista(Lista* l1, Lista* l2){
    if(((l1) == NULL)||((*l1) == NULL)||((l2) == NULL)||((*l2) == NULL)){
        return NULL;
    }
    Lista* inter = CriaLista();
    No *ant, *no = (*l1);
    No *ant2, *no2 = (*l2);
    while(no->prox != NULL){
        ant = no;
        no = no->prox;
        no2 = (*l2);
        while(no2->prox != NULL){
            ant2 = no2;
            no2 = no2->prox;
            if(ant->n == ant2->n){
                InsereListaOrdenada(inter, ant2->n);
            }
        }
        ant2 = ant2->prox;
        if(ant->n == ant2->n){
            InsereListaOrdenada(inter, ant2->n);
        }
    }
    ant = ant->prox;
    no2 = (*l2);
    while(no2->prox != NULL){
        ant2 = no2;
        no2 = no2->prox;
        if(ant->n == ant2->n){
            InsereListaOrdenada(inter, ant2->n);
        }
    }
    ant2 = ant2->prox;
    if(ant->n == ant2->n){
        InsereListaOrdenada(inter, ant2->n);
    }

    return inter;
}

int EliminarTodosNLista(Lista* l, int n){
    if((l == NULL)||((*l) == NULL)){
        return 0;
    }
    No* no = (*l);
    while(no->prox != NULL){
        if(no->n == n){
            RemoveListaN(l, n);
        }
        no = no->prox;
    }
    if(no->n == n){
        RemoveListaN(l, n);
    }
    return 1;
}

int InverteLista(Lista* l){
    if((l == NULL)||((*l) == NULL)){
        return 0;
    }
    No *ant, *atual, *proximo;
    ant = NULL;
    proximo = NULL;
    atual = (*l);
    while(atual != NULL){
        proximo = atual->prox;
        atual->prox = ant;
        ant = atual;
        atual = proximo;
    }
    (*l) = ant;
    return 1;
}

Lista* ListaPar(Lista* l){
    if((l == NULL)||((*l) == NULL)){
        return NULL;
    }
    Lista* par = CriaLista();
    No *no = (*l);
    while(no != NULL){
        if(no->n % 2 == 0){
            InsereListaOrdenada(par, no->n);
        }
        no = no->prox;
    }
    return par;
}

Lista* ListaImpar(Lista* l){
    if((l == NULL)||((*l) == NULL)){
        return NULL;
    }
    Lista* impar = CriaLista();
    No *no = (*l);
    while(no != NULL){
        if(no->n % 2 != 0){
            InsereListaOrdenada(impar, no->n);
        }
        no = no->prox;
    }
    return impar;
}

Lista* IntercalarLista(Lista* l1, Lista* l2){
    if((l1 == NULL)||((*l1) == NULL)||(l2 == NULL)||((*l2) == NULL)){
        return NULL;
    }
    Lista* interc = CriaLista();
    No *no1, *no2;
    no1 = (*l1);
    no2 = (*l2);
    while((no1 != NULL)&&(no2 != NULL)){
        if(no1 != NULL){
            InsereListaFinal(interc, no1->n);
            no1 = no1->prox;
        }
        if(no2 != NULL){
            InsereListaFinal(interc, no2->n);
            no2 = no2->prox;
        }
    }
    return interc;
}

int QTDMaiorQueN(Lista* l, int n){
    if((l == NULL)||((*l) == NULL)){
        return -1;
    }
    No *no;
    int cont;
    while(no != NULL){
        if(n > no->n){
            cont++;
        }
        no = no->prox;
    }
    return cont;
}

int SomaLista(Lista* l){
    if((l == NULL)||((*l) == NULL)){
        return -1;
    }
    No *no;
    int soma;
    while(no != NULL){
        soma += no->n;
        no = no->prox;
    }
    return soma;
}


