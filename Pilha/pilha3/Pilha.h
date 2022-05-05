typedef struct no* Pilha;

Pilha* CriaPilha();
void LiberaPilha(Pilha* p);
int TamanhoPilha(Pilha* p);
int PilhaVazia(Pilha* p);
int InserePilha(Pilha* p, char n);
int RemovePilha(Pilha* p);
int ConsultaPilha(Pilha* p, char *x);
char Desempilhar(Pilha* p);

int Parentizacao(char s[]);
