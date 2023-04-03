#include <stdio.h>
#include <stdlib.h>
#include "ListaCircularDuplamenteEncadeada.h"

int main()
{
    Lista *l;
    int n = 0;
    l = CriaLista();
    InsereFinal(l, 5);
    InsereFinal(l, 6);
    InsereFinal(l, 7);
    InsereInicio(l, 3);
    InsereInicio(l, 2);
    InsereInicio(l, 1);
    InsereOrdenado(l, 4);
    printf("Imprimindo normal: ");
    ImprimirLista(l);
    printf("\nImprimindo invertido: ");
    ImprimirListaInverso(l);
    RemoveInicio(l);
    RemoveFinal(l);
    RemoveInicio(l);
    printf("\nImprimindo apos remocao: ");
    ImprimirLista(l);
    printf("\nImprimindo invertido: ");
    ImprimirListaInverso(l);
    printf("\nAdicionando 1: ");
    InsereInicio(l, 1);
    ImprimirLista(l);
    printf("\nRemovendo o 4: ");
    RemoveN(l, 4);
    ImprimirLista(l);
    printf("\nNumero na segunda posicao: ");
    ConsultaPos(l, 2, &n);
    printf("%d", n);
    printf("\nPosicao do numero 6: ");
    ConsultaN(l, 6, &n);
    printf("%d\n", n);
    return 0;
}
