typedef struct no* Lista;

Lista* CriaLista();
void LiberaLista(Lista* l);
int TamanhoLista(Lista* l);
int ListaVazia(Lista* l);
int InsereInicio(Lista* l, int n);
int InsereFinal(Lista* l, int n);
int InsereOrdenado(Lista* l, int n);
int RemoveInicio(Lista* l);
int RemoveFinal(Lista* l);
int RemoveN(Lista* l, int n);
int ConsultaPos(Lista* l, int pos, int *n);
int ConsultaN(Lista* l, int n, int *pos);  //retorna pos de n
void ImprimirLista(Lista* l);
void ImprimirListaInverso(Lista* l);
