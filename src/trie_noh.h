/*
 * alunos: joilnen leite, daniel morais, matheus silva
 * 
 * 
 */
#ifndef BM_NOH_
#define BM_NOH_

/** nome padrao do arquivo */
#define NOME_ARQ "bmais_arquivo"
/** sufixos utilizado no aqruivo de dados e de indices */
#define SUFIXO_BM ".bm"

typedef struct artigo
{
    int id;
    int ano;
    char autor[200];
    char titulo[200];
    char revista[200];
    char DOI[20];
    char palavraChave[200];
    char invalido;
} s_artigo;

typedef struct bm_noh
{
    int *chaves, nchaves;
    int mgrau;
    struct bm_noh **filhos;
    struct bm_noh *pai;
    long **dfilhos;
    char eh_folha;
} bm_noh;

bm_noh *bm_noh_inic(int i, char eh_folha);

void bm_noh_split(bm_noh *bmn, bm_noh *y, int i);
bm_noh *bm_noh_split_int(bm_noh *bmn, bm_noh *y, bm_noh *z);

void bm_noh_insere(bm_noh *bmn, int chave);

void padding(char ch, int n);
void bm_noh_escrutina(bm_noh *bmn, int nivel);

bm_noh *bm_noh_pesquisa(bm_noh *bmn, int k);
bm_noh *bm_noh_pesquisa_folha(bm_noh *bmn, int chave);
int bm_noh_contem(bm_noh *bmn, int chave);

void bm_noh_escrevedisc(bm_noh *bmn, s_artigo *art);
s_artigo *bm_noh_ledisc(bm_noh *bmn, int chave);

void bm_noh_populaart(int chave, s_artigo *art);



#define MAXFILHOS(m) 2 * m
#define MAXCHAVES(m) MAXFILHOS(m) - 1

#endif
