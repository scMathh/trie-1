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

Trie* cria_trie(){

    Trie* novo = malloc(sizeof(Trie));
    novo->raiz = NULL;

    return novo;
}

No* cria_no(char* v){

    No* novo = malloc(sizeof(No));
    novo->filhos = NULL;
    novo->eh_palavra = 0;

    return novo;
}


/**
 * @brief Percorre a árvore buscando a palavra
 * 
 * @param noh raiz da árvore
 * @param palavra a ser buscada
 * @param l var indicando o indice em que a palavra esta, valor = 0
 * @param a var indicando se a palavra ja existe, valor = 0
 */
void buscaDigital(No* noh, char* palavra, int l, int a){
    
    if(l < strlen(palavra)){
        int j = l + 1;
        if(noh->filhos[j] != NULL){
            noh = noh->filhos[j];
            l++;
            buscaDigital(noh, palavra, l, a);
        }
    }
    else{
        if(noh->eh_palavra == 1){
            a = 1;
        }
    }
}

/**
 * @brief Insere uma palavra na trie
 * 
 * @param raiz da arvore
 * @param palavra a ser inserida
 */
void insercao(No* raiz, char* palavra){
    
    No *atual, *aux;
    int l, a, j;

    aux = raiz;
    l = a = 0;
    buscaDigital(aux, palavra, l, a);

    if(a == 0){
        /*PARA h <- l + 1, ... , comprimento(x), FACA:
            seja j a posicao de d(h) na ordenacao do alfabeto;
            ocupar(atual);
            PARA i <- 1, ... , m, FACA:
                aux->filhos[i] <- lambda (????) (lambda significa q é null?)
            FIM - PARA*/
            aux->filhos[j] = atual;
            atual->eh_palavra = 0;
            aux = atual;
        /*FIM - PARA*/
       aux->eh_palavra = 1;
    }
    else{
        printf("Insercao invalida\nPalavra ja existe na arvore\n\n");
    }
}


