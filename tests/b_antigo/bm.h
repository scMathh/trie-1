#ifndef BM_
#define BM_

#include "bm_noh.h"
 
typedef struct bm {
    struct bm_noh *raiz;
    int mgrau, *felem;
} bm;

bm *bm_inic(int i);
void bm_escrutina(bm *b);
bm_noh *bm_pesquisa(bm *b, int chave);
void bm_insere(bm *b, int chave);

#endif


