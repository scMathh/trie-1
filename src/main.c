/* Grupo 11
 * alunos: joilnen leite, daniel morais, matheus silva
 * 
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "stringset.h"
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

/** programa que testa a b+ */
int main()
{
    int chave_teste = 6;
    int num = 50;
    stringset *sset = stringset_inic(3);

    LTELA;
    tela_checklist(0);
    LTELA;
    tela_checklist(I_1);
    LTELA;
    tela_checklist(I_2);
    LTELA;
    tela_checklist(I_3);
    
    printf("só teste");

    return 0;
}
