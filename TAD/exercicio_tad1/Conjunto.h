// Quantidade de parâmetros, Parâmetros
int *CriaConjunto(int qtd, ...);
// Primeiro Conjunto, Segundo Conjunto, Quantidade de elementos do primeiro conjunto, Quantidade de elementos do segundo conjunto, Variável para receber o tamanho do novo conjunto
int *Uniao(int *c1, int *c2, int qtd1, int qtd2, int *tam);
int *Interseccao(int *c1, int *c2, int qtd1, int qtd2, int *tam);
int *Diferenca(int *c1, int *c2, int qtd1, int qtd2, int *tam);
// Conjunto, Tamanho do conjunto, Número a ser adicionado ou removido
void Inserir(int *c, int *qtd, int n);
void Remove(int *c, int *qtd, int n);
//Conjunto
int Min(int *c);
int Max(int *c);
int Tamanho(int *c);
_Bool Vazio(int *c);
//Conjunto 1, Conjunto 2
_Bool Igual(int *c1, int *c2);


