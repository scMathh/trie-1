#ifndef JOILNEN_CURSES_H
#define JOILNEN_CURSES_H

/*
 * aluno: joilnen
 */

/**
 * marcros que criei baseado no que pesquisei
 * sobre formatacao e codifificacao de terminal vt100
 * que eh a base dos emuladores de terminal do linux
 * curses eh como chamam o tipo de software q faz isso
 * curses e ncurses sao exemplos, aqui eh soh uma tentativa
 * primaria que atende as necessidades apenas dessa avaliacao
 */

#define S_LTELA "\033[H\033[J"
#define S_CM "\033[24;62H"
#define S_CMR "\033[24;58H"
#define S_UNDERL "\033[1m"
#define S_PISCA "\033[5m"
#define S_PISCARAP "\033[6m"
#define S_MAGENTAB "\033[45m"
#define S_PRETO "\033[30m"
#define S_PRETOB "\033[40m"
#define S_BRANCO "\033[37m"
#define S_BRANCOB "\033[47m"
#define S_CINZA "\033[36m"
#define S_CINZAB "\033[46m"
#define S_AZUL "\033[34m"
#define S_AZULB "\033[44m"
#define S_VERM "\033[31m"
#define S_VERMB "\033[41m"
#define S_VERD "\033[32m"
#define S_VERDB "\033[42m"
#define S_INV  "\033[7m"
#define S_NORM "\033[0m"
#define S_INFO "\033[24;0H\033[7m"
#define S_INFO_ST "\033[1;65H"
#define S_INFO_ST_1 "\033[2;65H"
#define S_CARD "\033[0;60H"
#define S_CHKLST "\033[%d;%dH%s\033[0m"
#define S_CHKLST_DONE "\033[46m\033[30m\033[%d;%dH%s\033[0m"
#define S_INFO2 "\033[46m\033[30m\033[24;0H"
#define S_LIST "\033[%d;78H%d"
#define S_FILEN "\033[0;55H"
#define S_VENN S_CHKLST
#define S_TEST "\033[1m"
#define S_NADA ""

#define LTELA printf(S_LTELA)
#define TIPO_DE_TERMINAL TCOLOR
#define INFO(x) printf("%s%s%s", S_INFO, x, S_NORM)
#define INFO2(x) printf("%s%s%s", S_INFO2, x, S_NORM)
#define INFO_ST(x) printf("%s%s%s%s", S_INV, S_INFO_ST, x, S_NORM)
#define CM printf("%s", m); fflush(stdout); getc(stdin)
#define CMR(x) printf("%s", S_CMR"q + * tecle enter *"); fflush(stdout); x = getc(stdin)
#define CMR1 printf("%s", S_CMR"++ tecle enter *"); fflush(stdout); getc(stdin)
#define CKLSITEM(l,c,b,x) \
    if (b) printf(S_CHKLST_DONE, l, c, x); \
    else printf(S_CHKLST, l, c, x)
#define INFO_FILE printf("%s%s%sf:%s%s", S_INFO_ST, __FILE__, S_INFO_ST_1, __FUNCTION__, S_NORM); fflush(stdout);
#define INFO_CARD(x) printf("%scardinalidade: %d%s", S_CARD, x, S_NORM)
#define S_FORMAT "\033[%d;%dH%s%s%s\033[0m"
#define PNAPOS(l,c,a1,a2, m) printf(S_FORMAT, l, c, a1, a2, m)

#endif
