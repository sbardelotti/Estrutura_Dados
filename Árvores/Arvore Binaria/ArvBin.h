#ifndef ARVBIN_H_INCLUDED
#define ARVBIN_H_INCLUDED
typedef struct NO* ArvBin;
//  note que estou utilizadno um ponteiro para ponteiro porque está sendo usado um ponteiro especial para identificar a raiz
ArvBin* criaArvBin();
void excluiArvBin(ArvBin* raiz);
int vaziaArvBin(ArvBin* raiz);
int alturaArvBin(ArvBin* raiz);
int qtdeNoArvBin(ArvBin* raiz);

void preOrdemArvBin(ArvBin* raiz);
void emOrdemArvBin(ArvBin* raiz);
void posOrdemArvBin(ArvBin* raiz);

int insereArvBin(ArvBin* raiz, int valor);
int removeArvBin(ArvBin* raiz, int valor);

int consultaArvBin(ArvBin* raiz, int valor);

#endif // ARVBIN_H_INCLUDED
