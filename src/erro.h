#ifndef ERRO_H
#define ERRO_H
#include <stdlib.h>

void erro(const char *f, const char *m)
{

    /****
    fprintf(stderr, "\n=== * erro\nfuncao: ");
    fprintf(stderr, f);
    fprintf(stderr, "\nmensagem: ");
    fprintf(stderr, m);
    fprintf(stderr, "\n=== * ====\n\n");
    ****/
    exit(-1);
}

#endif