#include "erro.h"

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
