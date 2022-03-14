/* Grupo 11
 * alunos: joilnen leite, daniel morais, matheus silva
 * 
 * 
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


