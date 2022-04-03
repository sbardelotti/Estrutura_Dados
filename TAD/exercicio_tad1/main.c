#include <stdio.h>
#include <stdlib.h>
#include "Conjunto.h"

int main()
{
    int *conjunto1;
    int *conjunto2;
    int *uniao;
    int *diferenca;
    int *interseccao;
    int *vazio;
    int tamUniao;
    int tamDiferenca;
    int tamInterseccao;
    int tamVazio;

    conjunto1 = CriaConjunto(5,4,6,8,9,1);
    conjunto2 = CriaConjunto(3,1,3,4,7);

    printf("Imprimindo primeiro conjunto: ");
    for(int i = 0; i < Tamanho(conjunto1); i++)
    {
        printf("%d ", conjunto1[i]);
    }
    printf("\nImprimindo segundo conjunto: ");
    for(int i = 0; i < Tamanho(conjunto2); i++)
    {
        printf("%d ", conjunto2[i]);
    }

    printf("\n---------\n");

    uniao = Uniao(conjunto1, conjunto2, Tamanho(conjunto1), Tamanho(conjunto2), &tamUniao);

    Inserir(uniao, &tamUniao, 3);
    Remove(uniao, &tamUniao, 7);

    printf("Conjunto uniao: ");
    for(int i = 0; i < tamUniao; i++)
    {
        printf("%d ", uniao[i]);
    }
    printf("\nTamanho uniao: %d - Com func tamanho: %d", tamUniao, Tamanho(uniao));
    printf("\n---------\n");

    diferenca = Diferenca(conjunto1, conjunto2, Tamanho(conjunto1), Tamanho(conjunto2), &tamDiferenca);

    printf("Conjunto diferenca: ");
    for(int i = 0; i < tamDiferenca; i++)
    {
        printf("%d ", diferenca[i]);
    }
    printf("\nTamanho diferenca: %d - Com func tamanho: %d", tamDiferenca, Tamanho(diferenca));
    printf("\n---------\n");

    interseccao = Interseccao(conjunto1, conjunto2, Tamanho(conjunto1), Tamanho(conjunto2), &tamInterseccao);

    printf("Conjunto interseccao: ");
    for(int i = 0; i < tamInterseccao; i++)
    {
        printf("%d ", interseccao[i]);
    }
    printf("\nTamanho interseccao: %d - Com func tamanho: %d", tamInterseccao, Tamanho(interseccao));
    printf("\n---------\n");

    printf("Min conjunto1: %d", Min(conjunto1));
    printf("\nMin conjunto2: %d", Min(conjunto2));
    printf("\nMin conjunto diferenca: %d", Min(diferenca));
    printf("\nMin conjunto interseccao: %d", Min(interseccao));
    printf("\nMin conjunto uniao: %d", Min(uniao));

    printf("\n---------\n");

    printf("Max conjunto1: %d", Max(conjunto1));
    printf("\nMax conjunto2: %d", Max(conjunto2));
    printf("\nMax conjunto diferenca: %d", Max(diferenca));
    printf("\nMax conjunto interseccao: %d", Max(interseccao));
    printf("\nMax conjunto uniao: %d", Max(uniao));

    printf("\n---------\n");

    if(Igual(conjunto1, conjunto1))
    {
        printf("Igual");
    }
    else
    {
        printf("Diferente");
    }

    printf("\n---------\n");

    tamVazio = 1;
    vazio = CriaConjunto(tamVazio,1);
    Remove(vazio, &tamVazio, 1);

    if(Vazio(vazio))
    {
        printf("Vazio");
    }
    else
    {
        printf("Tamanho: %d", tamVazio);
    }
    return 0;
}
