#include <stdio.h>
#include <stdlib.h>
#include "bm_noh.h"

void bm_noh_split(bm_noh *bmn, bm_noh *b, int i);

bm_noh *bm_noh_inic(int i, char eh_folha)
{
    bm_noh *n = (bm_noh *) malloc(sizeof(bm_noh));
    n->mgrau = i;
    n->chaves = (int *) malloc(sizeof(int) * NCHAVES(n->mgrau));
    n->filhos = (bm_noh **) malloc(sizeof(bm_noh) * NFILHOS(n->mgrau));
    n->nchaves = 0;
    n->eh_folha = eh_folha;
    return n;
}

void bm_noh_split(bm_noh *bmn, bm_noh *y,  int i)
{
    printf("\ncomecou split\n");
    
    int j;
    bm_noh *z = bm_noh_inic(y->mgrau, y->eh_folha);

    /**
     *           [4,         7]
     *  [1, 2, 3]   [4, 5, 6]  [7, 8, 9, 10]
     */
    printf("\ny->nchaves %d\n", y->nchaves);
    for (j = 0; j < y->nchaves; j++)
        printf("y %d\n", y->chaves[j]);

    for (j = 0; j < bmn->mgrau; j++){ 
        z->chaves[j] = y->chaves[j + bmn->mgrau];
        z->nchaves++;
    } // y[1, 2, 3, 4, 5, 6] z[4, 5, 6]
    for (j = 0; j < z->nchaves; j++)
        printf("z %d\n", z->chaves[j]);
 
    y->nchaves -= z->nchaves;
    for (j = bmn->nchaves; j >= i + 1; j--){
        bmn->filhos[j + 1] = bmn->filhos[j];
    }
    bmn->filhos[i + 1] = z;
 
    for (j = bmn->nchaves - 1; j >= i; j--)
        bmn->chaves[j + 1] = bmn->chaves[j];
 
    bmn->chaves[i] = y->chaves[bmn->mgrau];
    bmn->nchaves++;

    for (j = 0; j < bmn->nchaves; j++)
        printf("\nbmn %d\n", bmn->chaves[j]);
    printf("\n");

    for (j = 0; j < y->nchaves; j++)
        printf("y %d\n", y->chaves[j]);
    printf("\n");

    for (j = 0; j < z->nchaves; j++)
        printf("z %d\n", z->chaves[j]);

}

void bm_noh_insere(bm_noh *bmn, int chave)
{
    int i = bmn->nchaves - 1, j;
    printf("\nbmn: ");
    for (j = 0; j < bmn->nchaves; j++)
        printf("%d ", bmn->chaves[j]);
    printf("\n");

    if (bmn->eh_folha)
    {
        while (i >= 0 && bmn->chaves[i] > chave)
        {
            bmn->chaves[i + 1] = bmn->chaves[i];
            --i;
        }
        bmn->chaves[i + 1] = chave;
        bmn->nchaves++;
    }
    else
    {

        while (i >= 0 && bmn->chaves[i] > chave)
            --i;
        if (bmn->filhos[i+1]->nchaves == NCHAVES(bmn->mgrau)){
            bm_noh_split(bmn, bmn->filhos[i + 1], i + 1);
            i = bmn->nchaves - 1;
        }
        bm_noh_insere(bmn->filhos[i + 1], chave); 
        
    }
}

void bm_noh_escrutina(bm_noh *bmn)
{
    int i;
    for (i = 0; i < bmn->nchaves; i++)
    {
        if (!(bmn->eh_folha))
            bm_noh_escrutina(bmn->filhos[i]);
        
        if (bmn->eh_folha) 
            printf("%d ", bmn->chaves[i]); 
        else 
            printf("\033[44m\033[37m%d\033[0m ", bmn->chaves[i]);
    }
 
    if (!(bmn->eh_folha)) bm_noh_escrutina(bmn->filhos[i]);
}

bm_noh *bm_noh_pesquisa(bm_noh *bmn, int chave)
{
    int i = 0;
    while (i < bmn->nchaves && chave > bmn->chaves[i]) i++;
    if (bmn->chaves[i] == chave) return bmn;
    if (bmn->eh_folha) return NULL;
    return bm_noh_pesquisa(bmn->filhos[i], chave);
}

// Function to print the
// N-ary tree graphically
/****
void printNTree(bm_noh *x, int *flag, int depth, int isLast)
{
    // Condition when node is None
    if (x == NULL)
        return;
     
    // Loop to print the depths of the
    // current node
    int i;
    for (i = 1; i < depth; ++i) {
         
        // Condition when the depth
        // is exploring
        if (flag[i]) {
            printf("| ");
            printf(" ");
            printf(" ");
            printf(" ");
        }
         
        // Otherwise print
        // the blank spaces
        else {
            printf(" ");
            printf(" ");
            printf(" ");
            printf(" ");
        }
    }
     
    // Condition when the current
    // node is the root node
    if (depth == 0)
        printf("%d\n", x->nchaves);
     
    // Condition when the node is
    // the last node of
    // the exploring depth
    else if (isLast) {
        printf("+--- %d\n", x->nchaves);
         
        // No more childrens turn it
        // to the non-exploring depth
        flag[depth] = 0;
    }
    else {
        printf("+--- %d\n", x->nchaves);
    }
 
    for (i = 0; i < x->nchaves; ++i)
        // Recursive call for the
        // children nodes
        printNTree(x, flag, depth + 1, x->chaves[x->nchaves - 1]);
    flag[depth] = 1;
}
****/



