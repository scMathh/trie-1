/* Grupo 11
 * Alunos: Daniel Morais, Joilnen Leite e Matheus Silva
 */

#ifndef stringSet

#include <stdio.h>
#include <stdlib.h>

typedef struct trie_no{

    No* *filhos;
    int eh_palavra;

}No;


typedef struct trie{

    No *raiz;

}Trie;

void buscaDigital(No* noh, char* palavra, int l, int a);

void insercao(No* raiz, char* palavra);


#endif