#include <stdio.h>
#include <stdlib.h>
#include "ArvAVL.h"

//Um tipo de �rvore balanceado
//permitie rebalanceamento local: apenas a parte afetada pela inser��o/remo��o � rebalanceada
//usa rota��es simples ou duplas no rebalanceamento

//Fator de balanecamento da �rvore: � a diferen�a de altura entre as sub-�rvores
//se a sub-�rvore da direita tiver um n�vel a mais ent�o o fator � -1
//caso seja ada esquerda ent�o o fator � 1
//O fator sempre deve ser calculado de baixo para cima
//caso n�o exita uma das sub-�rvores ent�o sua altura � -1

//Numa AVL o fator de balanceamento deve ser sempre -1, 0 ou 1

int main()
{
    ArvAVL* raiz;
    return 0;
}
