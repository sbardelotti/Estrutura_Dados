#include "Conjunto.h"
#include <stdarg.h>
#include <stdlib.h>

int *CriaConjunto(int qtd, ...)
{
    int *conjunto = (int *) calloc(qtd+1, sizeof(int));
    va_list lista;
    va_start(lista, qtd);
    for(int i = 0; i < qtd; i++)
    {
        conjunto[i] = va_arg(lista, int);
    }
    va_end(lista);
    // Último elemento para calcular o tamanho
    conjunto[qtd] = -1;
    return conjunto;
}

int *Uniao(int *c1, int *c2, int qtd1, int qtd2, int *tam)
{
    int tamanho, tamanhoUniao;
    tamanho = qtd1 + qtd2;
    tamanhoUniao = -1;
    int *conjunto = (int *) calloc(tamanho+1 , sizeof(int));
    // Adicionando primeiro conjunto a união
    for(int i = 0; i < qtd1; i++)
    {
        tamanhoUniao++;
        conjunto[tamanhoUniao] = c1[i];
    }
    // Adicionando somente elementos não repetidos do segundo conjunto a união
    for(int i = 0; i < qtd2; i++)
    {
        int tem;
        tem = 0;
        for(int j = 0; j < tamanhoUniao+1; j++)
        {
            if(c2[i] == conjunto[j])
            {
                tem = 1;
                break;
            }
        }
        if(!tem)
        {
            tamanhoUniao++;
            conjunto[tamanhoUniao] = c2[i];
        }
    }
    *tam = tamanhoUniao;
    // Caso tenha elementos repetidos retorne apenas o ponteiro com a memória necessaria
    if(tamanhoUniao<tamanho)
    {
        int *cUniao = (int *) calloc(tamanhoUniao+1 , sizeof(int));
        for(int i = 0; i < tamanhoUniao; i++)
        {
            cUniao[i] = conjunto[i];
        }
        free(conjunto);
        // Último elemento para calcular o tamanho
        cUniao[tamanhoUniao] = -1;
        return cUniao;
    }
    conjunto[tamanho] = -1;
    return conjunto;
}

void Inserir(int *c, int *qtd, int n)
{
    *qtd+=1;
    c = (int *) realloc(c,((*qtd)*sizeof(int)+1));
    c[*qtd-1] = n;
    c[*qtd] = -1;
}

void Remove(int *c, int *qtd, int n)
{
    int achou;
    achou = 0;
    for(int i = 0; i < *qtd; i++)
    {
        if(c[i] == n)
        {
            achou = 1;
            // Se o número não estiver na última posição reordene o conjunto
            if(!(i+1 == *qtd))
            {
                for(int j = i; j < (*qtd-1); j++)
                {
                    c[j] = c[j+1];
                }
            }
            break;
        }
    }
    if(!achou)
    {
        *qtd += 1;
    }
    *qtd -= 1;
    c = (int *) realloc(c,((*qtd)*sizeof(int)+1));
    c[*qtd] = -1;
}

int *Interseccao(int *c1, int *c2, int qtd1, int qtd2, int *tam)
{
    int *conjunto = (int *) calloc(qtd1+1, sizeof(int));
    int tamanhoInterseccao = -1;
    for(int i = 0; i < qtd1; i++)
    {
        for(int j = 0; j < qtd2; j++)
        {
            if(c1[i] == c2[j])
            {
                tamanhoInterseccao ++;
                conjunto[tamanhoInterseccao] = c1[i];
                break;
            }
        }
    }
    // Transformando posição em tamanho
    tamanhoInterseccao ++;
    *tam = tamanhoInterseccao;
    if(tamanhoInterseccao<qtd1)
    {
        int *cInterseccao = (int *) calloc(tamanhoInterseccao+1, sizeof(int));
        for(int i = 0; i < tamanhoInterseccao; i++)
        {
            cInterseccao[i] = conjunto[i];
        }
        free(conjunto);
        // Último elemento para calcular o tamanho
        cInterseccao[tamanhoInterseccao] = -1;
        return cInterseccao;
    }
    conjunto[qtd1] = -1;
    return conjunto;
}

int *Diferenca(int *c1, int *c2, int qtd1, int qtd2, int *tam)
{
    int *conjunto = (int *) calloc(qtd1+1, sizeof(int));
    int tamanhoDiferenca = -1;
    for(int i = 0; i < qtd1; i++)
    {
        int igual;
        igual = 0;
        for(int j = 0; j < qtd2; j++)
        {
            if(c1[i] == c2[j])
            {
                igual = 1;
                break;
            }
        }
        if(!igual)
        {
            tamanhoDiferenca ++;
            conjunto[tamanhoDiferenca] = c1[i];
        }
    }
    // Transformando posição em tamanho
    tamanhoDiferenca ++;
    *tam = tamanhoDiferenca;
    if(tamanhoDiferenca<qtd1)
    {
        int *cDiferenca = (int *) calloc(tamanhoDiferenca+1, sizeof(int));
        for(int i = 0; i < tamanhoDiferenca; i++)
        {
            cDiferenca[i] = conjunto[i];
        }
        free(conjunto);
        // Último elemento para calcular o tamanho
        cDiferenca[tamanhoDiferenca] = -1;
        return cDiferenca;
    }
    conjunto[qtd1] = -1;
    return conjunto;
}

int Min(int *c)
{
    int tam = Tamanho(c);
    int min = c[0];
    for(int i = 0; i < tam; i++)
    {
        if(min > c[i])
        {
            min = c[i];
        }
    }
    return min;
}

int Max(int *c)
{
    int tam = Tamanho(c);
    int max = c[0];
    for(int i = 0; i < tam; i++)
    {
        if(max < c[i])
        {
            max = c[i];
        }
    }
    return max;
}

_Bool Igual(int *c1, int *c2)
{
    int tam1 = Tamanho(c1);
    int tam2 = Tamanho(c2);
    for(int i = 0; i < tam1; i++)
    {
        int igual;
        igual = 0;
        for(int j = 0; j < tam2; j++)
        {
            if(c1[i] == c2[j])
            {
                igual = 1;
                break;
            }
        }
        if(!igual)
        {
            return 0;
        }
    }

    return 1;
}

int Tamanho(int *c)
{
    int tam = 0;
    while(c[tam] != -1)
    {
        tam++;
    }
    return tam;
}

_Bool Vazio(int *c)
{
    if(c[0 == -1])
    {
        return 1;
    }
    return 0;
}











