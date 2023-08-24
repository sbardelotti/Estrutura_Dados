#ifndef TABELAHASH_H_INCLUDED
#define TABELAHASH_H_INCLUDED
struct aluno{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct hash Hash;

Hash* criaHash(int TABLE_SIZE);
void liberaHash(Hash* h);
int valorString(char *str);
int insereHashSemColisao(Hash* h, struct aluno al);
int buscaHashSemColisao(Hash* h, int mat, struct aluno* al);
int insereHashEnderAberto(Hash* h, struct aluno al);    //endereçamento aberto
int buscaHashEnderAberto(Hash* h, int mat, struct aluno* al);


#endif // TABELAHASH_H_INCLUDED
