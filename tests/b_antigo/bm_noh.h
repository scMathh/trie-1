#ifndef BM_NOH_
#define BM_NOH_
 
typedef struct bm_noh {
    int *chaves, nchaves;
    int mgrau; 
    union {
        struct bm_noh **filhos;
        int **dfilhos;
    };
    char eh_folha;
} bm_noh;

bm_noh *bm_noh_inic(int i, char eh_folha);
void bm_noh_split(bm_noh *bmn, bm_noh *y, int i);
void bm_noh_insere(bm_noh *bmn, int k);
void bm_noh_escrutina(bm_noh *bmn);
bm_noh *bm_noh_pesquisa(bm_noh *bmn, int k);

#define NCHAVES(a) 2 * a
#define NFILHOS(a) NCHAVES(a) + 1

#endif


