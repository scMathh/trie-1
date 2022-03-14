/*
 * alunos: joilnen leite, daniel morais, matheus silva
 * 
 * 
 */
#ifndef STRINGSET_H
#define STRINGSET_H

#include "trie.h"
#include "erro.h"

typedef struct trie_no{

    struct trie_no **filhos;
    int eh_palavra;

}No;


typedef struct Trie{

    No *raiz;

}Trie;

void buscaDigital(No* noh, char* palavra, int l, int a);

void insercao(No* raiz, char* palavra);


typedef struct stringset
{
    trie *raiz;

} stringset;

stringset *stringset_inic();

#endif
