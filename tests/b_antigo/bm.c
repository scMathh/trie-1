#include <stdio.h>
#include <stdlib.h>
#include "bm.h"

bm *bm_inic(int i)
{
    bm *b = (bm *) malloc(sizeof(bm));
    b->raiz = NULL;
    b->mgrau = i;

    return b;
}

void bm_escrutina(bm *b)
{
    if (b->raiz)
        bm_noh_escrutina(b->raiz);
}

bm_noh *bm_pesquisa(bm *b, int chave)
{
    return (b->raiz) ?
        bm_noh_pesquisa(b->raiz, chave) :
        NULL;
}

void bm_insere(bm *b, int chave)
{
    /** se arvore vazia */
    if (b->raiz)
    {
        /** se raiz estah cheia aumenta autrua da arvore */
        if (b->raiz->nchaves == NCHAVES(b->mgrau))
        {
            printf("\nb->raiz->nchaves[%d] == NCHAVES(b->mgrau)[%d]\n", b->raiz->nchaves, NCHAVES(b->mgrau));
            // Alloca memoria para a nova raiz
            bm_noh *s = bm_noh_inic(b->mgrau, 0);
 
            /** faz antiga raiz filho da nova raiz */
            s->filhos[0] = b->raiz;
 
            /** divide a antiga raiz e move a chave para o nova raiz */
            bm_noh_split(s, b->raiz, 0);
 
            /**
             * nova raiz tem dois filhos agora e decide qual dos filhos 
             * receberah a chave
             */
            int i = 0;
            if (s->chaves[0] < chave)
                i++;
            bm_noh_insere(s->filhos[i], chave);
 
            /** muda raiz */
            b->raiz = s;
        }
        else { 
            printf("\nso ta inserindo o [%d]\n", chave); /** se raiz nchaves cheia chama bm_noh_insere para raiz */
            bm_noh_insere(b->raiz, chave);}
    }
    else /** se arvore nchaves vazia */
    {
        /** aloca memoria para noh raiz */
        b->raiz = bm_noh_inic(b->mgrau, 1);
        b->raiz->nchaves = 1;  /** atualiza o numero de chaves */
        b->raiz->chaves[0] = chave;  /** insere chave */
    }
}



