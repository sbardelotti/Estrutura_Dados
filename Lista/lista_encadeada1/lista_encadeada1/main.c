#include <stdio.h>
#include <stdlib.h>
#include "ListaEncadeada.h"

int main()
{
    // lista é um ponteiro para a estrutura elemento, então l é um ponteiro para ponteiro
    Lista *l, *copia, *cat, *outra, *uniao, *inter;
    int a;
    l = CriaLista();
    copia = CriaLista();
    outra = CriaLista();

    InsereListaFinal(l, 4);
    InsereListaFinal(l, 3);
    InsereListaFinal(l, 2);
    InsereListaFinal(l, 9);
    InsereListaFinal(l, 6);
    InsereListaInicio(l, 1);
    InsereListaOrdenada(l, 5);
    printf("Iniciando a lista: ");
    ImprimirLista(l);

    RemoveListaN(l, 2);
    RemoveListaFinal(l);
    RemoveListaInicio(l);
    printf("\nApagando elementos da lista: ");
    ImprimirLista(l);

    printf("\n");

    ConsultaListaPos(l, 3, &a);
    printf("\nNumero na terceira posicao: %d", a);
    ConsultaListaN(l, 9, &a);
    printf("\nPosicao do numero 9: %d", a);

    printf("\n");

    printf("\nLista l: ");
    ImprimirLista(l);
    CopiaLista(l, copia);
    printf("\nCopiando lista l para lista copia: ");
    ImprimirLista(copia);
    RemoveListaInicio(l);
    printf("\nRemovendo inicio da lista l");
    printf("\nImprimindo novamente lista l: ");
    ImprimirLista(l);
    printf("\nImprimindo novamente lista copia: ");
    ImprimirLista(copia);

    printf("\n");

    printf("\nConcatenando l e copia: ");
    cat = CatLista(l, copia);
    ImprimirLista(cat);

    printf("\n");
    if(ListaIgual(l, l)){
        printf("\nE igual");
    }else{
        printf("\nNao e igual");
    }
    printf("\n");

    printf("\nRemovendo elementos iguais da lista cat: ");
    TirarElementosRepetidos(cat);
    ImprimirLista(cat);
    printf("\nOrdenando cat: ");
    OrdernarLista(cat);
    ImprimirLista(cat);
    printf("\n");

    InsereListaInicio(outra, 1);
    InsereListaInicio(outra, 2);
    InsereListaInicio(outra, 3);
    InsereListaInicio(outra, 4);
    InsereListaInicio(outra, 6);
    InsereListaInicio(outra, 7);
    printf("\nLista l: ");
    ImprimirLista(l);
    printf("\nLista Outra: ");
    ImprimirLista(outra);
    printf("\nLista uniao de l com outra: ");
    uniao = UniaoLista(l, outra);
    ImprimirLista(uniao);

    printf("\n");

    printf("\nLista cat: ");
    ImprimirLista(cat);
    printf("\nLista outra: ");
    ImprimirLista(outra);
    printf("\nLista interseccao de cat com outra: ");
    inter = InterseccaoLista(cat, outra);
    ImprimirLista(inter);

    printf("\n");

    InsereListaFinal(inter, 3);
    InsereListaFinal(inter, 3);
    InsereListaFinal(inter, 4);
    InsereListaFinal(inter, 3);
    printf("\nInserindo novos elementos na lista inter: ");
    ImprimirLista(inter);
    printf("\nRetirando todos os 3 da lista inter: ");
    EliminarTodosNLista(inter, 3);
    ImprimirLista(inter);

    printf("\n");

    LiberaLista(l);
    LiberaLista(copia);
    LiberaLista(cat);
    LiberaLista(outra);
    LiberaLista(uniao);
    LiberaLista(inter);
    return 0;
}









