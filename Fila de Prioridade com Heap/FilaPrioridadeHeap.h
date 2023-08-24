#ifndef FILAPRIORIDADEHEAP_H_INCLUDED
#define FILAPRIORIDADEHEAP_H_INCLUDED
#define MAX 100

typedef struct fila_prioridade FilaPrio;

FilaPrio* criaFilaPrio();
void liberaFilaPrio(FilaPrio* fp);
int consultaFilaPrio(FilaPrio* fp, char* nome);
int insereFilaPrio(FilaPrio* fp, char *nome, int  prioridade);
int removeFilaPrio(FilaPrio* fp);
int tamanhoFilaPrio(FilaPrio* fp);
int cheiaFilaPrio(FilaPrio* fp);
int vaziaFilaPrio(FilaPrio* fp);
void imprimeFilaPrio(FilaPrio* fp);



#endif // FILAPRIORIDADEHEAP_H_INCLUDED
