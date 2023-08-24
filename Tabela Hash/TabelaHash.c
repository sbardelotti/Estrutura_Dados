#include <stdlib.h>
#include <string.h>
#include "TabelaHash.h"

struct hash{
    int qtd, TABLE_SIZE;
    struct aluno **itens;
};

//Ao criar uma tabela hash � ideal escolher um n�mero primo e evitar valores que sejam pot�ncia de 2
//N�mero primo -> Reduz probabilidade de colis�es
//Pot�ncia de dois -> melhora a velocidade mas aumenta problemas com colis�o

Hash* criaHash(int TABLE_SIZE)
{
    Hash* h = (Hash*) malloc(sizeof(Hash));
    if(h != NULL)
    {
        int i;
        h->TABLE_SIZE = TABLE_SIZE;
        h->itens = (struct aluno**) malloc(TABLE_SIZE * sizeof(struct aluno*));

        if(h->itens == NULL)
        {
            free(h);
            return NULL;
        }

        h->qtd = 0;
        for(i = 0; i < h->TABLE_SIZE; i++)
            h->itens[i] = NULL;
    }
    return h;
}

void liberaHash(Hash* h)
{
    if(h != NULL)
    {
        int i;
        for(i = 0; i < h->TABLE_SIZE; i++)
            if(h->itens[i] != NULL)
                free(h->itens[i]);

        free(h->itens);
        free(h);
    }
}

//metodo de congru�ncia linear
int chaveDivisao(int chave, int TABLE_SIZE)
{
    return (chave & 0x7FFFFFFF) % TABLE_SIZE;
}

//metodo de congru�ncia linear multiplicativo
int chaveMultiplicacao(int chave, int TABLE_SIZE)
{
    float A = 0.6180339887;
    float val = chave * A;
    val = val - (int) val;
    return (int) (TABLE_SIZE * val);
}

//metodo de dobra
int chaveDobra(int chave, int TABLE_SIZE)
{
    int num_bits = 10;
    int parte1 = chave >> num_bits;
    int parte2 = chave & (TABLE_SIZE - 1);
    return (parte1 ^ parte2);
}

//string como chave
int valorString(char *str)
{
    int i, valor = 7;
    int tam = strlen(str);
    for(i = 0; i < tam; i++)
        valor = 31 * valor + (int) str[i];
    return valor;
}

/*
A escolha do n�mero 31 como multiplicador tem algumas propriedades ben�ficas:

31 � um n�mero primo, o que � desej�vel para evitar padr�es repetitivos e colis�es indesejadas. N�meros primos geralmente s�o usados em fun��es de hashing, pois ajudam a espalhar os valores de entrada de maneira mais uniforme.
Multiplicar um valor por 31 pode ser implementado de forma eficiente usando um deslocamento (shift) e uma subtra��o. Em muitos sistemas, essas opera��es s�o mais r�pidas do que uma multiplica��o geral.
O n�mero 31 tem a propriedade de que seu produto com qualquer n�mero inteiro � quase sempre diferente para entradas diferentes. Isso ajuda a espalhar os valores de hashing e reduzir a probabilidade de colis�es, aumentando a qualidade geral da fun��o de hashing.
*/

int insereHashSemColisao(Hash* h, struct aluno al)
{
    if(h == NULL || h->qtd == h->TABLE_SIZE)
        return 0;

    int chave = al.matricula;
    int pos = chaveDivisao(chave, h->TABLE_SIZE);
    struct aluno* novo;
    novo = (struct aluno*) malloc(sizeof(struct aluno));
    if(novo == NULL)
        return 0;

    *novo = al;
    h->itens[pos] = novo;
    h->qtd++;
    return 1;
}

int buscaHashSemColisao(Hash* h, int mat, struct aluno* al)
{
    if(h == NULL)
        return 0;

    int pos = chaveDivisao(mat, h->TABLE_SIZE);
    if(h->itens[pos] == NULL)
        return 0;

    *al = *(h->itens[pos]);
    return 1;
}







