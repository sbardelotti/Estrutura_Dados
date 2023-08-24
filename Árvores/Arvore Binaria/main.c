#include <stdio.h>
#include <stdlib.h>
#include "ArvBin.h"

int main()
{
    ArvBin* raiz;  //  ponteiro para ponteiro para a raiz
    raiz = criaArvBin();



    excluiArvBin(raiz);
    return 0;
}
