#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

struct no{
    char n;
    struct no *prox;
};

typedef struct no No;

Pilha* CriaPilha(){
    Pilha* p = (Pilha *) malloc(sizeof(Pilha));
    if(p != NULL) *p = NULL;
    return p;
}

void LiberaPilha(Pilha* p){
    if(p != NULL){
        No *no;
        while((*p) != NULL){
            no = *p;
            *p = (*p)->prox;
            free(no);
        }
        free(p);
    }
}

int TamanhoPilha(Pilha* p){
    if(p == NULL) return 0;
    int count = 0;
    No *no = *p;
    while(no != NULL){
        count++;
        no = no->prox;
    }
    return count;
}

int PilhaVazia(Pilha* p){
    if(p == NULL) return 1;
    if((*p) == NULL) return 1;
    return 0;
}

int InserePilha(Pilha* p, char n){
    if(p == NULL) return 0;
    No *no = (No *) malloc(sizeof(No));
    if(no == NULL) return 0;
    no->n = n;
    no->prox = (*p);
    *p = no;
    return 1;
}

int RemovePilha(Pilha* p){
    if(p == NULL) return 0;
    if((*p) == NULL) return 0;
    No *no = (*p);
    *p = no->prox;
    free(no);
    return 1;
}

int ConsultaPilha(Pilha* p, char *x){
    if(p == NULL) return 0;
    if((*p) == NULL) return 0;
    *x = (*p)->n;
    return 1;
}

char Desempilhar(Pilha* p){
    if(p == NULL) return -1;
    if((*p) == NULL) return -1;
    char n = (*p)->n;
    No *no = (*p);
    *p = no->prox;
    free(no);
    return n;
}

int Parentizacao(char s[]){
    Pilha *p  = CriaPilha();
    int i = 0;
    while(s[i] != '\0'){
        if(s[i] == '('){
            InserePilha(p, '(');
        }
        if(s[i] == ')'){
            if(!RemovePilha(p)){
                printf("Parentizacao errada");
                return 0;
            }
        }
        i++;
    }
    if(!PilhaVazia(p)){
        printf("Parentizacao errada");
        return 0;
    }
    printf("Parentizacao correta");
    LiberaPilha(p);
    return 1;
}















