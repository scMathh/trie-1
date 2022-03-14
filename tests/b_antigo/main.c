#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bm.h"

static void rb_pr(bm_noh *t, int s)
{
    const int dist = 5;
    int i, j;
    s += dist;  

    if (!t) return;
    for (i = 0; i < t->nchaves + 1; i++)
    {
        for (j = 0; j < t->nchaves; j++)
            printf("\033[44m\033[37m%d\033[0m ", t->chaves[j]);
        printf("\n");
        rb_pr(t->filhos[i], s);  
    }
}

void padding(char ch, int n){
    for(int i = 0; i < n; i++){ 
        putchar(ch);
    }
}

void print_function(int *t)
{
    int j;
    for (j = 0; j < 4; j++)
        printf("\033[44m\033[37m%d\033[0m ", t[j]);
}
 
void imprime_arvore(bm_noh *root, int nivel){

    int i;
    if (root == NULL){
        padding('\t', nivel); 
        puts("~");
    }
    else{
        for (i = 0; i <= root->nchaves; i+=2)
            imprime_arvore(root->filhos[i], nivel + 1);
        padding('\t', nivel);
        print_function(root->chaves);
        for (i = 1; i <= root->nchaves; i+=2)
            imprime_arvore(root->filhos[i], nivel + 1);

        /***
        imprime_arvore(root->filhos[1], nivel + 1);
        padding('\t', nivel);
        print_function(root->chaves);

        imprime_arvore(root->filhos[2], nivel + 1);
        padding('\t', nivel);
        print_function(root->chaves);

        imprime_arvore(root->filhos[3], nivel + 1);
        padding('\t', nivel);
        print_function(root->chaves);
        ***/
    }
}

static void atravessa(bm_noh *r)
{
    int i;
    if (!r) return;
    for (i = 0; i < r->nchaves; ++i)
        printf("%d ", r->chaves[i]);
    printf("\n");
    for (i = 0; i < r->nchaves + 1; ++i)
        atravessa(r->filhos[i]);
}

/** programa que testa a b+ */
int main()
{
    int chave_teste = 6;

    bm *bm = bm_inic(3);
    bm_insere(bm, 1);
    bm_insere(bm, 2);
    bm_insere(bm, 3);
    bm_insere(bm, 4);
    bm_insere(bm, 5);
    bm_insere(bm, 6);
    /****
    bm_insere(bm, 10);
    bm_insere(bm, 20);
    bm_insere(bm, 5);
    bm_insere(bm, 6);
    bm_insere(bm, 7);
    bm_insere(bm, 17);
    bm_insere(bm, 18);
    bm_insere(bm, 19);
    bm_insere(bm, 21);
    bm_insere(bm, 22);
    bm_insere(bm, 23);
    bm_insere(bm, 24);
    bm_insere(bm, 25);
    bm_insere(bm, 26);
    ****/
    bm_insere(bm, 8);
    bm_insere(bm, 9);
    bm_insere(bm, 10);
 
    printf("Atravessa a arvore construida:");
    bm_escrutina(bm);
 
    if (bm_pesquisa(bm, chave_teste))
        printf("\nPresente");
    else
        printf("\nN Presente");
    chave_teste = 15;

    if (bm_pesquisa(bm, chave_teste))
        printf("\nPresente");
    else
        printf("\nN Presente");
    printf("\n");
    int i;
    for (i = 0; i < bm->raiz->nchaves; i++)
        printf("raiz %d\n", bm->raiz->chaves[i]);
    // atravessa(bm->raiz);
    // rb_pr(bm->raiz, 3);
    imprime_arvore(bm->raiz, 0);

    free(bm);
 
    return 0;
}



