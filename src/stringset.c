/*
 * Grupo 11
 * alunos: joilnen leite, daniel morais, matheus silva
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stringset.h"

/**
 * faz a inicialização da arvore trie 
 * @param int i ordem da arvore
 */
stringset *stringset_inic()
{
    stringset *s = (stringset *) malloc (sizeof(stringset));
    s->raiz = trie_inic();
    return s;
}

