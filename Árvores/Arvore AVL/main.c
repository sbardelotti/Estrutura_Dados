#include <stdio.h>
#include <stdlib.h>
#include "ArvAVL.h"

//Um tipo de árvore balanceado
//permitie rebalanceamento local: apenas a parte afetada pela inserção/remoção é rebalanceada
//usa rotações simples ou duplas no rebalanceamento

//Fator de balanecamento da árvore: é a diferença de altura entre as sub-árvores
//se a sub-árvore da direita tiver um nível a mais então o fator é -1
//caso seja ada esquerda então o fator é 1
//O fator sempre deve ser calculado de baixo para cima
//caso não exita uma das sub-árvores então sua altura é -1

//Numa AVL o fator de balanceamento deve ser sempre -1, 0 ou 1

int main()
{
    ArvAVL* raiz;
    return 0;
}
