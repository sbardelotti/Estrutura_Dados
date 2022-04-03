#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    Lista *l, *outra, *cat, *pares, *copia, *quebra;
    l = criaLista();
    outra = criaLista();
    int t;

    printf("Lista l: ");
    insereListaFinal(l, 2);
    insereListaFinal(l, 3);
    insereListaInicio(l, 1);
    insereListaFinal(l, 5);
    insereListaOrdenada(l, 4);
    imprimeLista(l);
    printf("\n");
    removeListaInicio(l);
    removeListaFinal(l);
    removeLista(l, 3);
    printf("Removendo elementos da lista: ");
    imprimeLista(l);
    printf("\n\n");
    consultaListaPos(l, 1, &t);
    printf("Numero na posicao 1: %d\n", t);
    consultaListaX(l, 2, &t);
    printf("Posicao do numero 2: %d\n", t);

    insereListaFinal(outra, 9);
    insereListaFinal(outra, 8);
    insereListaFinal(outra, 7);
    insereListaFinal(outra, 6);
    printf("\n");

    printf("Primeira lista: ");
    imprimeLista(l);
    printf("\nSegunda lista: ");
    imprimeLista(outra);
    (printf("\nLista concatenada: "));
    cat = catLista(l, outra);
    imprimeLista(cat);
    printf("\n");

    int p = removeListaN(cat, 2);
    if(p){
        (printf("\nApos remocao: "));
        imprimeLista(cat);
    }else{
        printf("\nNao foi possivel remover");
    }
    printf("\n");

    printf("\nTrocando elemento na primeira posicao pela segunda: ");
    trocarPosPorPos(cat, 1, 2);
    imprimeLista(cat);
    printf("\n");

    printf("Substituindo 7 por 4: ");
    trocarValorPorValor(cat, 7, 4);
    imprimeLista(cat);
    printf("\n");

    printf("Trocando o numero na segunda posicao por 1: ");
    trocarValorNaPos(cat, 2, 1);
    imprimeLista(cat);
    printf("\n");

    int qtdePares;
    pares = listaPares(cat, &qtdePares);
    printf("Depois de todas as modificacoes a lista concatenada tem: %d numeros pares", qtdePares);
    printf("\nLista com apenas pares: ");
    imprimeLista(pares);
    printf("\n");

    float media = mediaLista(cat);
    printf("\nMedia da lista cat: %f", media);
    media = mediaLista(pares);
    printf("\nMedia da lista pares: %f", media);
    printf("\n");

    printf("\nCopiando cat: ");
    copia = copiaLista(cat);
    imprimeLista(copia);
    printf("\n");

    printf("\nInvertendo copia: ");
    inverterLista(copia);
    imprimeLista(copia);
    printf("\n");

    insereListaFinal(copia, 3);
    printf("\nAdicionando 3 a lista copia: ");
    imprimeLista(copia);
    printf("\n");

    printf("\nInvertendo copia novamente: ");
    inverterLista(copia);
    imprimeLista(copia);
    printf("\n");

    printf("\nQuebra lista da posicao 2 da copia: ");
    quebra = quebraLista(copia, 2);
    imprimeLista(quebra);
    printf("\n");

    if(listaIgual(copia,quebra)){
        printf("\nE igual");
    }else{
        printf("\nNao e igual");
    }

    printf("\nOrdenando cat: ");
    ordernarLista(cat);
    imprimeLista(cat);
    printf("\nOrdenando quebra: ");
    ordernarLista(quebra);
    imprimeLista(quebra);
    printf("\nOrdenando copia: ");
    ordernarLista(copia);
    imprimeLista(copia);
    printf("\nOrdenando outra: ");
    ordernarLista(outra);
    imprimeLista(outra);
    printf("\n");

    liberaLista(l);
    liberaLista(outra);
    liberaLista(cat);
    liberaLista(pares);
    liberaLista(copia);
    liberaLista(quebra);

    return 0;
}
