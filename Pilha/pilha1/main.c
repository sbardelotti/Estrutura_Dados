#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

int main()
{
    Pilha *p;
    p = CriaPilha();

    LiberaPilha(p);
    return 0;
}
