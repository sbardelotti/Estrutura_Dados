#ifndef ARVAVL_H_INCLUDED
#define ARVAVL_H_INCLUDED
//perceba que para guardar o primeiro n� da �rvore utilazamos um ponteiro para ponteiro
//asim facilita trocar a razi da arvore
typedef struct NO* ArvAVL;

ArvAVL* criaArv();
void excluiArv(ArvAVL* raiz);
int vaziaArv(ArvAVL* raiz);
int alturaArv(ArvAVL* raiz);
int qtdeNoArv(ArvAVL* raiz);
void preOrdemArv(ArvAVL* raiz);
void emOrdemArv(ArvAVL* raiz);
void posOrdemArv(ArvAVL* raiz);

//Fun��es Auxliares
int altNO(struct NO* no);
int fatorBalanceamentoNO(struct NO* no);
int maior(int x, int y);

//Fun��es AVL
void rotacaoLL(ArvAVL* raiz);
void rotacaoRR(ArvAVL* raiz);
void rotacaoLR(ArvAVL* raiz);
void rotacaoRL(ArvAVL* raiz);

int insereAVL(ArvAVL* raiz, int valor);
int removeAVL(ArvAVL* raiz, int valor);

#endif // ARVAVL_H_INCLUDED
