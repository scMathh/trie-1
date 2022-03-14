/* Grupo 11
 * Alunos: Daniel Morais, Joilnen Leite e Matheus Silva
 */

#include <stdio.h>
#include <stdlib.h>

#include "StringSet.h"


int main(){

    int x = -1;

    while (x != 0)
    {
        printf("------------------Menu------------------\n");
        printf("| 1 - Adicionar Palavra                 |\n");
        printf("| 2 - Remover Palavra                   |\n");
        printf("| 3 - Contem Palavra                    |\n");
        printf("| 4 - Verifica se arvore esta vazia     |\n");
        printf("| 5 - Informa o tamanho                 |\n");
        printf("| 6 - Imprime Palavras                  |\n");
        printf("| 7 - Contem Prefixo                    |\n");
        printf("| 0 - Sair                              |\n");
        printf("----------------------------------------\n");

        scanf("%d",&x);

        switch (x)
        {
        case 1:
            printf("Adicionar Palavra\n\n");
            break;
        
        case 2:
            printf("Remover Palavra\n\n");
            break;

        case 3:
            printf("Contem Palavra\n\n");
            break;

        case 4:
            printf("Verifica se arvore esta vazia\n\n");
            break;
        
        case 5:
            printf("Informa o tamanho \n\n");
            break;

        case 6:
            printf("Imprime Palavras\n\n");
            break;
        
        case 7:
            printf("Contem Prefixo\n\n");
            break;

        case 0:
            break;
        default:
            printf("Informe uma opcao valida\n");
            break;
        }
    }
    

    return 0;
}