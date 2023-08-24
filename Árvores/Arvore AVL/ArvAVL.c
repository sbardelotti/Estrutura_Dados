#include <stdio.h>
#include <stdlib.h>
#include "ArvAVL.h"

struct NO{
    int info;
    int alt;  //altura daquela sub-árvore
    struct NO *esq;
    struct NO *dir;
};

ArvAVL* criaArv()
{
    ArvAVL* raiz = (ArvAVL *) malloc(sizeof(ArvAVL));
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

void excluiArv(ArvAVL* raiz)
{
    if(raiz == NULL)
        return;
    liberaNO(*raiz);
    free(*raiz);
    raiz = NULL;
}

int vaziaArv(ArvAVL* raiz)
{
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 1;
    return 0;
}

int alturaArv(ArvAVL* raiz)
{
    if(raiz == NULL)
        return 0;
    if(*raiz == NULL)
        return 0;
    int altEsq = alturaArv(&((*raiz)->esq));
    int altDir = alturaArv(&((*raiz)->dir));
    if(altEsq > altDir)
        return (altEsq + 1);
    else
        return (altDir + 1);
}

int qtdeNoArv(ArvAVL* raiz)
{
    if(raiz == NULL)
        return 0;
    if(*raiz == NULL)
        return 0;
    int noEsq = qtdeNoArv(&((*raiz)->esq));
    int noDir = qtdeNoArv(&((*raiz)->dir));
    return(noEsq + noDir + 1);
}

void preOrdemArv(ArvAVL* raiz)
{
    if(raiz == NULL)
        return;
    if(*raiz != NULL)
    {
        printf("%d\n", (*raiz)->info);
        preOrdemArv(&((*raiz)->esq));
        preOrdemArv(&((*raiz)->dir));
    }
}

void emOrdemArv(ArvAVL* raiz)
{
    if(raiz == NULL)
        return;
    if(*raiz != NULL)
    {
        emOrdemArv(&((*raiz)->esq));
        printf("%d\n", (*raiz)->info);
        emOrdemArv(&((*raiz)->dir));
    }
}

void posOrdemArv(ArvAVL* raiz)
{
    if(raiz == NULL)
        return;
    if(*raiz != NULL)
    {
        posOrdemArv(&((*raiz)->esq));
        posOrdemArv(&((*raiz)->dir));
        printf("%d\n", (*raiz)->info);
    }
}

int altNO(struct NO* no)
{
    if(no==NULL)
        return -1;
    else
        return no->alt;
}

/*int labs(int x){
    if(x < 0)
        return -x;
    return x;
}
*/
int fatorBalanceamentoNO(struct NO* no)
{
    return labs(altNO(no->esq) - altNO(no->dir));
}

int maior(int x, int y)
{
    if(x > y)
        return x;
    else
        return y;
}

//rotação simples: nó desbalanceado e seu filho estão no mesmo sentido da inclinação
//o no e seu filho estão inclinado no sentido inverso ao pai
//ao todo exite 4 tipo de rotação: rotação simple a direita/esqeurda rotação dupla  a direita/esquerda
//quando usar cada rotação?
//A: +2 B: +1 -> LL
//A: -2 B: -1 -> RR
//A: +2 B: -1 -> LR
//A: -2 B: +1 -> RL

void rotacaoLL(ArvAVL* raiz)
{
    struct NO* no;
    no = (*raiz)->esq;
    (*raiz)->esq = no->dir;
    no->dir = (*raiz);

    (*raiz)->alt = maior(altNO((*raiz)->esq), altNO((*raiz)->dir)) + 1;
    no->alt = maior(altNO(no->esq), (*raiz)->alt) + 1;

    *raiz = no;
}

void rotacaoRR(ArvAVL* raiz)
{
    struct NO* no;
    no = (*raiz)->dir;
    (*raiz)->dir = no->esq;
    no->esq = (*raiz);

    (*raiz)->alt = maior(altNO((*raiz)->esq), altNO((*raiz)->dir)) + 1;
    no->alt = maior(altNO(no->dir), (*raiz)->alt) + 1;

    *raiz = no;
}

void rotacaoLR(ArvAVL* raiz)
{
    rotacaoRR(&(*raiz)->esq);
    rotacaoLL(raiz);
}

void rotacaoRL(ArvAVL* raiz)
{
    rotacaoLL(&(*raiz)->dir);
    rotacaoRR(raiz);
}

int insereAVL(ArvAVL* raiz, int valor)
{
    int res;
    if(*raiz == NULL)
    {
        struct NO *novo;
        novo = (struct NO*) malloc(sizeof(struct NO));
        if(novo == NULL)
            return 0;

        novo->info = valor;
        novo->alt = 0;
        novo->esq = NULL;
        novo->dir = NULL;
        *raiz = novo;
        return 1;
    }

    struct NO *atual = *raiz;
    if(valor < atual->info)
    {
        if((res = insereAVL(&(atual->esq), valor)) == 1)
        {
            if(fatorBalanceamentoNO(atual) >= 2)
            {
                if(valor < (*raiz)->esq->info)
                {
                    rotacaoLL(raiz);
                }
                else
                {
                    rotacaoLR(raiz);
                }

            }
        }
    }
    else
    {
        if(valor > atual->info)
        {
            if((res = insereAVL(&(atual->dir), valor)) == 1)
            {
                if(fatorBalanceamentoNO(atual) >= 2)
                {
                    if((*raiz)->dir->info < valor)
                    {
                        rotacaoRR(raiz);
                    }
                    else
                    {
                        rotacaoRL(raiz);
                    }
                }
            }
        }
        else
        {
            printf("Valor duplicado!!!\n");
            return 0;
        }
    }

    atual->alt = maior(altNO(atual->esq), altNO(atual->dir)) + 1;
    return res;
}

//responsavel por tratar a remoção de nó com 2 filhos
struct NO* procuraMenor(struct NO* atual)
{
    struct NO *no1 = atual;
    struct NO *no2 = atual->esq;
    while(no2 != NULL)
    {
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
}

//Remover um nó da sub-árvore da direita equivale a inserir um nó na sub-árvore da esquerda
//Então se remover um nó da diretia precisa verificar a árvore da esquerda
int removeAVL(ArvAVL* raiz, int valor)
{
    if(*raiz == NULL)
    {
        printf("Árvore vazia");
        return 0;
    }
    int res;
    if(valor < (*raiz)->info)
    {
        if((res = removeAVL(&(*raiz)->esq, valor)) == 1)
        {
            if(fatorBalanceamentoNO(*raiz) >= 2)
            {
                if(altNO((*raiz)->dir->esq) <= altNO((*raiz)->dir->dir))
                {
                    rotacaoRR(raiz);
                }
                else
                {
                    rotacaoRL(raiz);
                }
            }
        }
    }

    if((*raiz)->info < valor)
    {
        if((res = removeAVL(&(*raiz)->dir, valor)) == 1)
        {
            if(fatorBalanceamentoNO(*raiz) >= 2)
            {
                if(altNO((*raiz)->esq->dir) <= altNO((*raiz)->esq->esq))
                {
                    rotacaoLL(raiz);
                }
                else
                {
                    rotacaoLR(raiz);
                }
            }
        }
    }

    if((*raiz)->info == valor)
    {
        if((*raiz)->esq == NULL || (*raiz)->dir == NULL)
        {
            struct NO *oldNo = (*raiz);
            if((*raiz)->esq != NULL)
                *raiz = (*raiz)->esq;
            else
                *raiz = (*raiz)->dir;
            free(oldNo);
        }
        else    //Nó tem 2 filhos
        {
            struct NO* temp = procuraMenor((*raiz)->dir);
            (*raiz)->info = temp->info;
            removeAVL(&(*raiz)->dir, (*raiz)->info);
            if(fatorBalanceamentoNO(*raiz) >= 2)
            {
                if(altNO((*raiz)->esq->dir) <= altNO((*raiz)->esq->esq))
                {
                    rotacaoLL(raiz);
                }
                else
                {
                    rotacaoLR(raiz);
                }
            }
        }
        if(*raiz != NULL)
            (*raiz)->alt = maior(altNO((*raiz)->esq), altNO((*raiz)->dir)) +1;

        return 1;
    }
    if(*raiz != NULL)
        (*raiz)->alt = maior(altNO((*raiz)->esq), altNO((*raiz)->dir)) +1;

    return res;
}











