/* Grupo 11
 * alunos: joilnen leite, daniel morais, matheus silva
 * 
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "bm.h"
#include "checklist.h"
#include "jcurses.h"

/****
static void atravessa(bm_noh *r) {
  int i;
  if (!r)
    return;
  for (i = 0; i < r->nchaves; ++i)
    printf("%d ", r->chaves[i]);
  printf("\n");
  for (i = 0; i < r->nchaves + 1; ++i)
    atravessa(r->filhos[i]);
}
****/

static void popula_art(s_artigo *art)
{
    int chave, ano;
    srand(time(NULL));
    chave = rand() % 99 + 1;
    ano = rand() % 2000 + 1;

    art->id = chave;
    art->ano = ano;
    strcpy(art->autor, "batman");
    strcpy(art->titulo, "a vida batman");
    strcpy(art->revista, "revista batman");
    strcpy(art->DOI, "DOI-DOI-MUITO-0000");
    strcpy(art->palavraChave, "batman");
    art->invalido = 0;
}

/** programa que testa a b+ */
int main()
{
    int chave_teste = 6;
    int num = 50;
    bm *bm = bm_inic(3);

    LTELA;
    tela_checklist(0);
    tela_checklist(I_1);
    tela_checklist(I_2);
    tela_checklist(I_3);

    s_artigo *a = (s_artigo *) malloc(sizeof(s_artigo));

    // bm_geraarvore(bm);


    popula_art(a);
    bm_insere(bm, 1 , a);
    CMR1;
    LTELA;
    popula_art(a);
    bm_insere(bm, 72, a);
    CMR1;
    LTELA;
    popula_art(a);
    bm_insere(bm, 3 , a);
    CMR1;
    LTELA;
    popula_art(a);
    bm_insere(bm, 4 , a);
    CMR1;
    LTELA;
    popula_art(a);
    bm_insere(bm, 40, a);
    CMR1;
    LTELA;
    popula_art(a);
    bm_insere(bm, 5 , a);
    popula_art(a);
    bm_insere(bm, 6 , a);
    popula_art(a);
    bm_insere(bm, 7 , a);
    popula_art(a);
    bm_insere(bm, 84, a);
    popula_art(a);
    bm_insere(bm, 8 , a);
    popula_art(a);
    bm_insere(bm, 99, a);
    popula_art(a);
    bm_insere(bm, 10, a);
    popula_art(a);
    bm_insere(bm, 11, a);
    popula_art(a);
    bm_insere(bm, 12, a);
    popula_art(a);
    bm_insere(bm, 173, a);
    popula_art(a);
    bm_insere(bm, 14, a);
    popula_art(a);
    bm_insere(bm, 199, a);
    popula_art(a);
    bm_insere(bm, 110, a);
    popula_art(a);
    bm_insere(bm, 111, a);
    popula_art(a);
    bm_insere(bm, 112, a);
    free(a);
    
    printf("Atravessa a arvore construida:");
    bm_escrutina(bm);
    /*
    if (bm_pesquisa(bm, chave_teste))
        printf("\nPresente");
    else
        printf("\nN Presente");
    chave_teste = 15;
    
    if (bm_pesquisa(bm, chave_teste))
        printf("\nPresente");
    else
        printf("\nN Presente");
    printf("\n");*/
    
    /*int i;
    for (i = 0; i < bm->raiz->nchaves; i++)
        printf("raiz %d\n", bm->raiz->chaves[i]);*/
    
    printf("\nA partir de qual numero devo percorrer? ");
    int x = 0;
    scanf("%d", &x);
    bm_lista(bm->raiz, x);

    free(bm);
    printf("\nfim\n");
    
    return 0;
}
