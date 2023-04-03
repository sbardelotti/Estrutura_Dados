#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

struct lista{
    int chave;
    int n[MAX];
};

Lista* criaLista(){
    Lista *l;
    l = (Lista *) malloc(sizeof(struct lista));
    if(l != NULL){
        l->chave = 0;
    }
    return l;
}

void liberaLista(Lista* l){
    free(l);
}

int tamanhoLista(Lista* l){
    if(l == NULL){
        return -1;
    }else{
        return l->chave;
    }
}

int listaCheia(Lista* l){
    if(l == NULL){
        return -1;
    }
    return (l->chave == MAX);
}

int listaVazia(Lista* l){
    if(l == NULL){
        return -1;
    }
    return (l->chave == 0);
}

int insereListaFinal(Lista* l, int n){
    if((l == NULL)||(listaCheia(l))){
        return 0;
    }
    l->n[l->chave] = n;
    l->chave++;
    return 1;
}

int insereListaInicio(Lista* l, int n){
    if((l == NULL)||(listaCheia(l))){
        return 0;
    }
    for(int i = l->chave-1; i >= 0; i--){
        l->n[i+1] = l->n[i];
    }
    l->n[0] = n;
    l->chave++;
    return 1;
}

int insereListaOrdenada(Lista* l, int n){
    if((l == NULL)||(listaCheia(l))){
        return 0;
    }
    int i = 0;
    while((i < l->chave)&&(l->n[i] < n)){
        i++;
    }
    for(int k = l->chave-1; k >= i; k--){
        l->n[k+1] = l->n[k];
    }
    l->n[i] = n;
    l->chave++;
    return 1;
}

int removeListaFinal(Lista* l){
    if((l == NULL)||(listaVazia(l))){
        return 0;
    }
    l->chave--;
    return 1;
}

int removeListaInicio(Lista* l){
    if((l == NULL)||(listaVazia(l))){
        return 0;
    }
    for(int i = 0; i < l->chave-1; i++){
        l->n[i] = l->n[i+1];
    }
    l->chave--;
    return 1;
}

int removeLista(Lista* l, int n){
    if((l == NULL)||(listaVazia(l))){
        return 0;
    }
    int k, i = 0;
    while((i < l->chave)&&(l->n[i] != n)){
        i++;
    }
    if(i == l->chave){
        return 0;
    }

    for(k = i; k < l->chave-1; k++){
        l->n[k] = l->n[k+1];
    }
    l->chave--;
    return 1;
}

int consultaListaPos(Lista* l, int pos, int *n){
    if((l == NULL)||(pos <= 0)||(pos > l->chave)){
        return 0;
    }
    *n = l->n[pos-1];
    return 1;
}

int consultaListaX(Lista* l, int x, int *n){
    if(l == NULL){
      return 0;
    }
    int i = 0;
    while((i < l->chave)&&(l->n[i] != x)){
        i++;
    }
    if(i == l->chave){
        return 0;
    }

    *n = i+1;
    return 1;
}

int imprimeLista(Lista* l){
    if((l == NULL)||(listaVazia(l))){
        return 0;
    }

    for(int i = 0; i < l->chave; i++){
        printf("%d ", l->n[i]);
    }
    return 1;
}

Lista* catLista(Lista* l1, Lista* l2){
    if((l1->chave+l2->chave>=20)||(l1 == NULL)||(l2 == NULL)){
        return 0;
    }
    Lista *cat;
    cat = (Lista *) malloc(sizeof(struct lista));
    if(cat != NULL){
        cat->chave = 0;
    }
    for(int i = 0; i < l1->chave; i++){
        cat->n[cat->chave] = l1->n[i];
        cat->chave++;
    }
    for(int i = 0; i < l2->chave; i++){
        cat->n[cat->chave] = l2->n[i];
        cat->chave++;
    }
    return cat;
}

int removeListaN(Lista* l, int n){
    if((l == NULL)||(n >= l->chave+1)||(n<0)){
        return 0;
    }
    n--;
    while(n >= 0){
        removeListaInicio(l);
        n--;
    }
    return 1;
}

int trocarPosPorPos(Lista* l, int pos1, int pos2){
    if((l == NULL)||(pos1<=0)||(pos2<=0)||(pos1>=l->chave)||(pos2>=l->chave)){
        return 0;
    }
    int aux;
    aux = l->n[pos1-1];
    l->n[pos1-1] = l->n[pos2-1];
    l->n[pos2-1] = aux;
    return 0;
}

int trocarValorPorValor(Lista* l, int ant, int nov){
    if(l == NULL){
      return 0;
    }
    int i = 0;
    while((i < l->chave)&&(l->n[i] != ant)){
        i++;
    }
    if(i == l->chave){
        return 0;
    }

    l->n[i] = nov;
    return 1;
}

int trocarValorNaPos(Lista* l, int pos, int n){
    if((l == NULL)||(pos <= 0)||(pos >= l->chave+1)){
        return 0;
    }
    l->n[pos-1] = n;
    return 1;
}

Lista* listaPares(Lista* l, int *p){
    if(l == NULL){
        return 0;
    }
    Lista *lp;
    lp = (Lista *) malloc(sizeof(struct lista));
    if(lp != NULL){
        lp->chave = 0;
    }
    for(int i = 0; i < l->chave; i++){
        if(l->n[i] % 2 == 0){
            lp->n[lp->chave] = l->n[i];
            lp->chave++;
        }
    }
    *p = lp->chave;
    return lp;
}

float mediaLista(Lista* l){
    if((l == NULL)||(listaVazia(l))){
        return 0;
    }
    float media;
    int i = 0;
    for(i = 0; i < l->chave; i++){
        media += l->n[i];
    }
    return media/i;
}

Lista* copiaLista(Lista* l){
    if(l == NULL){
        return 0;
    }
    Lista *nl;
    nl = (Lista *) malloc(sizeof(struct lista));
    if(nl != NULL){
        nl->chave = 0;
    }
    for(int i = 0; i < l->chave; i++){
        nl->n[nl->chave] = l->n[i];
        nl->chave++;
    }
    return nl;
}

int inverterLista(Lista* l){
    if(l == NULL){
        return 0;
    }
    int aux;
    for(int i = 1; i <= (l->chave)/2; i++){
        aux = l->n[l->chave-i];
        //printf("Aux: %d - ", aux);
        l->n[l->chave-i] = l->n[i-1];
        l->n[i-1] = aux;
    }
    return 1;
}

Lista* quebraLista(Lista* l, int n){
    if((l == NULL)||(n>=l->chave)||(n<0)){
        return 0;
    }
    Lista* nl;
    nl = (Lista *) malloc(sizeof(struct lista));
    if(nl != NULL){
        nl->chave = 0;
    }
    for(int i = n; i < l->chave; i++){
        nl->n[nl->chave] = l->n[i];
        nl->chave++;
    }
    return nl;
}

int listaIgual(Lista* l1, Lista* l2){
    if((l1 == NULL)||(l2 == NULL)||(l1->chave!=l2->chave)){
        return 0;
    }
    for(int i = 0; i < l1->chave; i++){
        if(l1->n[i]!= l2->n[i]){
            return 0;
        }
    }
    return 1;
}

int ordernarLista(Lista* l){
    if((l == NULL)||(listaVazia(l))){
        return 0;
    }
    int aux;
    for(int i = 0; i < l->chave; i++){
        for(int k = 0; k < l->chave-1; k++){
            if(l->n[k]>l->n[k+1]){
                aux = l->n[k];
                l->n[k] = l->n[k+1];
                l->n[k+1] = aux;
            }
        }
    }
    return 1;
}


