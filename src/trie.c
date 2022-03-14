/* 
 * Grupo 11
 * alunos: joilnen leite, daniel morais, matheus silva
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trie.h"
#include "erro.h"

/**
 * faz a inicialização de um nó
 * @param int i grau da página
 * @param char eh_folha flag para saber se a página é interna ou externa
 *
 */
trie *trie_inic()
{
    return (trie *) malloc (sizeof(trie));
}

static trie *trie_busca_profundidade(trie *raiz, trie *t, char *str)
{
    int j;
    static int ic = 0;

    for (j = 0; j < t->mprox; j++)
    {
        if (t->prox && t->prox[j]->letra == *str)
        {
            ic++;
            trie_busca_profundidade(raiz, *(t->prox[j])->prox, ++str);
        }
    }

    if (raiz != t)
    {
        t->letra = *str;
        t->indice_letra = ic;
    }

    return t;
}

void trie_preenche(trie *raiz, char *str)
{
    trie *t = trie_busca_profundidade(raiz, raiz, str);

}


