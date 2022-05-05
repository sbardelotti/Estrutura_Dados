typedef struct no* Pilha;

Pilha* CriaPilha();
void LiberaPilha(Pilha* p);
int TamanhoPilha(Pilha* p);
int PilhaVazia(Pilha* p);
int InserePilha(Pilha* p, int n);
int RemovePilha(Pilha* p);
int ConsultaPilha(Pilha* p, int *x);
int Desempilhar(Pilha* p);

