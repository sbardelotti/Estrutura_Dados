#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

int main()
{
    Fila* f;
    int n = 0;
    f = CriaFila();

    InsereFila(f, 1);
    InsereFila(f, 3);
    InsereFila(f, 5);
    InsereFila(f, 6);
    InsereFila(f, 9);
    printf("Imprimindo fila: ");
    ImprimirFila(f);
    printf("\nTamanho: %d", TamanhoFila(f));
    RemoveFila(f);
    RemoveFila(f);
    RemoveFila(f);
    printf("\nImprimindo fila: ");
    ImprimirFila(f);
    printf("\nTamanho: %d", TamanhoFila(f));
    ConsultaFila(f, &n);
    printf("\nConsulta: %d", n);
    InsereFila(f, 5);
    InsereFila(f, 7);
    InsereFila(f, 8);
    printf("\nImprimindo fila: ");
    ImprimirFila(f);
    printf("\nInvertendo fila: ");
    InverterFila(f);
    ImprimirFila(f);
    printf("\nTamanho: %d", TamanhoFila(f));
    ConsultaFila(f, &n);
    printf("\nConsulta: %d", n);
    return 0;
}
