#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "stack.h"
#include "parser.h"
#include "funcoes.h"
#include "funcoesStack.h"
#include "logica.h"
#include "variaveis.h"

/** Tipo da Dispatch Table */
typedef void (*dispatch_table) (STACK *s);

/** 
 * \brief inicializa a tabela de funções
 * @param tabelaOp array declarado no parser
*/
void iniciar_dispatchtable(dispatch_table *tabelaOp){
    tabelaOp['+'] = adicionar;
    tabelaOp['-'] = sub;
    tabelaOp['*'] = multiply;
    tabelaOp['/'] = divisao;
    tabelaOp['#'] = expoente;
    tabelaOp['('] = dec;
    tabelaOp[')'] = inc;
    tabelaOp['%'] = modulo;
    tabelaOp['&'] = and;
    tabelaOp['|'] = or;
    tabelaOp['^'] = xor;
    tabelaOp['~'] = not;
    tabelaOp['\\'] = trocar;
    tabelaOp['_'] = duplicar;
    tabelaOp[';'] = popp;
    tabelaOp['@'] = rodar3;
    tabelaOp['$'] = copiarNTopo;
    tabelaOp['i'] = converteInt;
    tabelaOp['f'] = converterDouble;
    tabelaOp['l'] = lerLinha;
    tabelaOp['c'] = converteCHAR;
    tabelaOp['?'] = ifThenElse;
    tabelaOp['='] = igual;
    tabelaOp['>'] = maior;
    tabelaOp['<'] = menor;
    tabelaOp[161] = emenor;
    tabelaOp[163] = emaior;
    tabelaOp[139] = e;
    tabelaOp[225] = ou;
    tabelaOp['!'] = nao;
    tabelaOp['A'] = varA;
    tabelaOp['B'] = varB;
    tabelaOp['C'] = varC;
    tabelaOp['D'] = varD;
    tabelaOp['E'] = varE;
    tabelaOp['F'] = varF;
    tabelaOp['N'] = varN;
    tabelaOp['S'] = varS;
    tabelaOp['X'] = varX;
    tabelaOp['Y'] = varY;
    tabelaOp['Z'] = varZ;
}
/**
 * @brief função responsável por tratar o conteúdo que está na linha, se for um número coloca na stack. Caso contrário procura se existe um função associdada ao caracter
 * @param s stack
 * @param token token da linha
 */ 
void handle(STACK *s, char *token){
    dispatch_table tabelaOp[1000];
    iniciar_dispatchtable(tabelaOp);

    char *resto;
    char *resto2;
    long num = strtol(token, &resto, 10);
    double num2 = strtod(token, &resto2);
    ////printf("TOKEN:%s\n", token);
    if(strlen(resto) == 0){
            ////printf("NUM:%ld\n", num); //numero
            push (s, (DATA){.type = LONG, .LONG = num});
    }
    else if(strlen(resto2) == 0){
            ////printf("NUM2:%lf\n", num2); //FLOAT
            push (s, (DATA){.type = DOUBLE, .DOUBLE = num2});
    }
    else{
        if(strlen(resto) == 2) {
            if(resto[0] == ':'){
                DATA x = pop(s);
                double y = toDouble(x);
                s->letras[resto[1]-65] = converte(y,1);
                push(s, x);
            }
            else{
                //printf("A:%s\n", resto);
                unsigned int unsigned_int = (unsigned int)resto[1] + (unsigned int)resto[0];
                //printf("B:%d\n", unsigned_int);
                tabelaOp[unsigned_int](s);
                }
        }
        else{
            ////printf("%s\n", resto);
            unsigned char unsigned_resto = (unsigned char) resto[0];
            tabelaOp[unsigned_resto](s);
        }
    }
}


/**
 * \brief função responsável por fazer a leitura de uma linha e enviar o conteúdo para ser tratado no handle
 * @param s stack
 */
void parse_line(STACK *s) {
    char line[BUFSIZ];
    char token[BUFSIZ];
    if (fgets(line, BUFSIZ, stdin) != NULL) {
        while (sscanf(line, "%s%[^\n]", token, line) == 2) {
            handle(s, token);
        }
        handle(s,token);
    }
}
