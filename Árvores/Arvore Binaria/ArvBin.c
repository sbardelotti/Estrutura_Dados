#include <stdio.h>
#include <stdlib.h>
#include "ArvBin.h"

struct NO{
    int info;
    struct NO *esq;
    struct NO *dir;
};

ArvBin* criaArvBin()
{
    ArvBin* raiz = (ArvBin *) malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void liberaNO(struct NO* no)
{
    if(no == NULL)
        return;
    liberaNO(no->esq);
    liberaNO(no->dir);
    free(no);
    no = NULL;
}

void excluiArvBin(ArvBin* raiz)
{
    if(raiz == NULL)
        return;
    liberaNO(*raiz);
    free(*raiz);
    raiz = NULL;
}

int vaziaArvBin(ArvBin* raiz)
{
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 1;
    return 0;
}

int alturaArvBin(ArvBin* raiz)
{
    if(raiz == NULL)
        return 0;
    if(*raiz == NULL)
        return 0;
    int altEsq = alturaArvBin(&((*raiz)->esq));
    int altDir = alturaArvBin(&((*raiz)->dir));
    if(altEsq > altDir)
        return (altEsq + 1);
    else
        return (altDir + 1);
}

int qtdeNoArvBin(ArvBin* raiz)
{
    if(raiz == NULL)
        return 0;
    if(*raiz == NULL)
        return 0;
    int noEsq = qtdeNoArvBin(&((*raiz)->esq));
    int noDir = qtdeNoArvBin(&((*raiz)->dir));
    return(noEsq + noDir + 1);
}

void preOrdemArvBin(ArvBin* raiz)
{
    if(raiz == NULL)
        return;
    if(*raiz != NULL)
    {
        printf("%d\n", (*raiz)->info);
        preOrdemArvBin(&((*raiz)->esq));
        preOrdemArvBin(&((*raiz)->dir));
    }
}

void emOrdemArvBin(ArvBin* raiz)
{
    if(raiz == NULL)
        return;
    if(*raiz != NULL)
    {
        emOrdemArvBin(&((*raiz)->esq));
        printf("%d\n", (*raiz)->info);
        emOrdemArvBin(&((*raiz)->dir));
    }
}

void posOrdemArvBin(ArvBin* raiz)
{
    if(raiz == NULL)
        return;
    if(*raiz != NULL)
    {
        posOrdemArvBin(&((*raiz)->esq));
        posOrdemArvBin(&((*raiz)->dir));
        printf("%d\n", (*raiz)->info);
    }
}

// na arvore binaria de busca os filhos da esqeurda são sempre menores que o pai e os da direita são sempre maiores

int insereArvBin(ArvBin* raiz, int valor)
{
    if(raiz == NULL)
        return 0;
    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL)
        return 0;
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    if(*raiz == NULL)
        *raiz = novo;
    else{
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        while(atual != NULL)
        {
            ant = atual;
            if(valor == atual->info)
            {
                free(novo);
                return 0;
            }
            if(valor > atual->info)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
        if(valor > ant->info)
            ant->dir = novo;
        else
            ant->esq = novo;
    }
    return 1;
}

struct NO* removeAtual(struct NO* atual)
{
    struct NO *no1, *no2;
    if(atual->esq == NULL)
    {
        no2 = atual->dir;
        free(atual);
        return no2;
    }

    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL)
    {
        no1 = no2;
        no2 = no2->dir;
    }

    if(no1 != atual)
    {
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}

int removeArvBin(ArvBin* raiz, int valor)
{
    if(raiz == NULL)
        return 0;
    struct NO* ant = NULL;
    struct NO* atual = NULL;
    while(atual != NULL)
    {
        if(valor == atual->info)
        {
            if(atual == *raiz)
                *raiz = removeAtual(atual);
            else
            {
                if(ant->dir == atual)
                    ant->dir = removeAtual(atual);
                else
                    ant->esq = removeAtual(atual);
            }
            return 1;
        }

        ant = atual;
        if(valor > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

//Note que ao fazer a exclusão de um nó da árvore te´ra 3 ocasiões:
/*
Nó sem filhos: Este é o mais fácil. Você pode simplesmente excluir o nó, sem nenhuma ação adicional necessária.
com um filho): você deve garantir que, após a exclusão do nó, seu filho seja conectado ao pai do nó excluído.
Dois filhos: Você deve encontrar e substituir o nó que deseja excluir por seu sucessor inordem (o nó mais à esquerda na subárvore direita).
*/

int consultaArvBin(ArvBin* raiz, int valor)
{
    if(raiz == NULL)
        return 0;
    struct NO* atual = *raiz;
    while(atual != NULL)
    {
        if(valor == atual->info){
            return 1;
        }
        if(valor > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

