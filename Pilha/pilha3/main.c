#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

int main()
{
    char s[100] = "( ( ) ) – ( ( )( ) ) – ( ) ( )";
    Parentizacao(s);
    return 0;
}
