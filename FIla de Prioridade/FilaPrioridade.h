#ifndef FILAPRIORIDADE_H_INCLUDED
#define FILAPRIORIDADE_H_INCLUDED
#define MAX 100
typedef struct fila_prioridade FilaPrio;

FilaPrio* criaFilaPrio();
void liberaFilaPrio(FilaPrio* fp);
int consultaFilaPrio(FilaPrio* fp, char* nome);
int insereFilaPrio(FilaPrio* fp, char* nome, int prio);
int removeFilaPrio(FilaPrio* fp);
int tamanhoFilaPrio(FilaPrio* fp);
int cheioFilaPrio(FilaPrio* fp);
int vazioFilaPrio(FilaPrio* fp);


#endif // FILAPRIORIDADE_H_INCLUDED
