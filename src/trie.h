/*
 * alunos: joilnen leite, daniel morais, matheus silva
 * 
 * 
 */
#ifndef TRIE_H
#define TRIE_H

typedef struct trie
{
    int *chaves, nchaves;
    int mgrau;
    struct bm_noh **filhos;
    struct bm_noh *pai;
    long **dfilhos;
    char eh_folha;
} trie;

trie *trie_inic();

#define MAXFILHOS(m) 2 * m
#define MAXCHAVES(m) MAXFILHOS(m) - 1

#endif
