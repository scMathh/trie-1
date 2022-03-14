/*
 * alunos: joilnen leite, daniel morais, matheus silva
 * 
 * 
 */
#ifndef STRINGSET_H
#define STRINGSET_H

#include "trie.h"
#include "erro.h"

typedef struct stringset
{
    trie *raiz;

} stringset;

stringset *stringset_inic();

#endif
