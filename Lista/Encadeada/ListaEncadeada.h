typedef struct no* Lista;

Lista* CriaLista();
void LiberaLista(Lista* l);
int TamanhoLista(Lista* l);
int ListaVazia(Lista* l);
int InsereListaInicio(Lista* l, int n);
int InsereListaFinal(Lista* l, int n);
int InsereListaOrdenada(Lista* l, int n);
int RemoveListaInicio(Lista* l);
int RemoveListaFinal(Lista* l);
int RemoveListaN(Lista* l, int n);
int ConsultaListaPos(Lista* l, int pos, int *n);
int ConsultaListaN(Lista* l, int proc, int *n);
void ImprimirLista(Lista* l);
int CopiaLista(Lista* l1, Lista* l2);
Lista* CatLista(Lista* l1, Lista* l2);
int ListaIgual(Lista* l1, Lista* l2);
int OrdernarLista(Lista *l);
int TirarElementosRepetidos(Lista* l);
Lista* UniaoLista(Lista* l1, Lista* l2);
Lista* InterseccaoLista(Lista* l1, Lista* l2);
int EliminarTodosNLista(Lista* l, int n);

int InverteLista(Lista* l);
Lista* ListaPar(Lista* l);
Lista* ListaImpar(Lista* l);
Lista* IntercalarLista(Lista* l1, Lista* l2);
int QTDMaiorQueN(Lista* l, int n);
int SomaLista(Lista* l);



