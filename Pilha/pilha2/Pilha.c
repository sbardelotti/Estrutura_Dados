#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no{
    char letra;
    struct no *prox;
};

typedef struct no No;
typedef No* Pilha;

Pilha CriaPilha(){
    return NULL;
}

void LiberaPilha(Pilha p){
    No *no;
    while(p != NULL){
        no = p;
        p = p->prox;
        free(no);
    }
}

int TamanhoPilha(Pilha p){
    if(p == NULL) return 0;
    int count = 0;
    No *no = p;
    while(no != NULL){
        count++;
        no = no->prox;
    }
    return count;
}

int PilhaVazia(Pilha p){
    if(p == NULL) return 1;
    return 0;
}

int InserePilha(Pilha *p, char letra){
    No *no = (No *) malloc(sizeof(No));
    if(no == NULL) return 0;
    no->letra = letra;
    no->prox = (*p);
    *p = no;
    return 1;
}

void Desempilhar(Pilha *p, char *letra){
    *letra = (*p)->letra;
    No *no = (*p);
    *p = no->prox;
    free(no);
}

void ImprimirInvertido(char texto[]){
    Pilha p = CriaPilha();
    int tamanho = strlen(texto);
    for (int i = 0; i < tamanho; i++) {
        if (texto[i] == ' ' || texto[i] == '.') {
            while (!PilhaVazia(p)) {
                char letra;
                Desempilhar(&p, &letra);
                printf("%c", letra);
            }
            if (texto[i] == ' ') printf(" ");
        } else {
            InserePilha(&p, texto[i]);
        }
    }
}
