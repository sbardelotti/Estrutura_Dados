#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

int main()
{
    Pilha *par, *impar, *res;
    par = CriaPilha();
    impar = CriaPilha();
    res = CriaPilha();
    int n = -1;
    printf("Digite numeros - 0 finaliza a entrada de dados\n");
    while(1){
        scanf("%d", &n);
        if(n == 0){
            break;
        }
        if(n%2 == 0){
            InserePilha(par, n);
        }else{
            InserePilha(impar, n);
        }
    }

    while(!(PilhaVazia(par)&&(PilhaVazia(impar)))){
        if(!(PilhaVazia(impar))){
            n = Desempilhar(impar);
            if(n > 0){
                InserePilha(res, n);
            }else{
                if(!(PilhaVazia(res))){
                    RemovePilha(res);
                }
            }
        }
        if(!(PilhaVazia(par))){
            n = Desempilhar(par);
            if(n > 0){
                InserePilha(res, n);
            }else{
                if(!(PilhaVazia(res))){
                    RemovePilha(res);
                }
            }
        }
    }

    printf("\n----------------------------------");
    printf("\nResultado: ");
    while(!(PilhaVazia(res))){
        n = Desempilhar(res);
        printf("%d ", n);
    }
    return 0;
}
