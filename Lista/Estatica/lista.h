#define MAX 20
typedef struct lista Lista;

Lista* criaLista();
void liberaLista(Lista* l);

// retorna o tamanho da lista
int tamanhoLista(Lista* l);

// retorna se a lista esta cheia
int listaCheia(Lista* l);
// retorna se a lista esta vazia
int listaVazia(Lista* l);

// insere elementos na lista
int insereListaFinal(Lista* l, int n);
int insereListaInicio(Lista* l, int n);
int insereListaOrdenada(Lista* l, int n);

// remove elementos da lista
int removeListaFinal(Lista* l);
int removeListaInicio(Lista* l);
int removeLista(Lista* l, int n);

// procurar o número na posicao
int consultaListaPos(Lista* l, int pos, int *n);
// procurar a posicao do numero
int consultaListaX(Lista* l, int x, int *n);

// imprime todos os elementos da lista
int imprimeLista(Lista* l);

// concatena 2 listas
Lista* catLista(Lista* l1, Lista* l2);
// remove os n primeiros elementos da lista
int removeListaN(Lista* l, int n);
// troca o elemento em uma posicao por outro em outra posicao
int trocarPosPorPos(Lista* l, int pos1, int pos2);
// procura determinado valor e o troca por outro
int trocarValorPorValor(Lista* l, int ant, int nov);
// troca valor em determinada posicao
int trocarValorNaPos(Lista* l, int pos, int n);
// retorna uma lista com apenas pares de uma outra lista, tambem retorna por referencia a quantidade de pares
Lista* listaPares(Lista* l, int *p);
// media de todos elementos da lista
float mediaLista(Lista* l);
// retorna uma copia da lista
Lista* copiaLista(Lista* l);
// inverte a lista
int inverterLista(Lista* l);
// quebra a lista em determinada posicao retornando uma nova com os elementos apos a posicao especificada
Lista* quebraLista(Lista* l, int n);
// retorna se a lista e igual ou nao
int listaIgual(Lista* l1, Lista* l2);
// ordena a lista em ordem crescente
int ordernarLista(Lista* l);
