#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"
#include "parser.h"
#include "funcoes.h"
typedef void (*dispatch_table) (STACK *s);

/**
 * \brief A função splitStrings recebe uma string e um delimitador, e devolve um array de strings.
 * @param str string a ser dividida
 * @param delim delimitador da string
 * @return devolve um array de strings
 */
char* splitStrings(char *str, const char *delim){
    static char *src = NULL;
    char *p, *ret;

    if(str != NULL){
        src = str;
    }
    if(src == NULL){
        return NULL;
    }
    if((p = strpbrk(src, delim)) != NULL){
        *p = '\0';
        ret = src;
        src = ++p;
    }else{
        ret = src;
        src = NULL;
    }
    return ret;
}
/**
* \brief A função parse recebe uma stack e uma linha (vindas da main), percorre essa linha separa em tokens e compara se existe um caracter específico para que possa ser executada uma operação.
* \brief Saindo do ciclo for, a função print_stack imprime a stack.
* @param s Passagem da stack como parâmetro
* @param line Linha a ser lida.
*/
void parser(STACK *s, char *linha){
    char *limite = " \t\n";
    char* token = splitStrings(linha,limite);
    dispatch_table tabelaOp[1000];
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
    while(token != NULL){
        char *resto;
         int num = strtol(token, &resto, 10);
        if(strlen(resto) == 0) {
            push(s,num);
        }
        else{
            unsigned char unsigned_resto = (unsigned char) resto[0];
            tabelaOp[unsigned_resto](s);
        }
        
        token = splitStrings(NULL,limite);
    }
    printStack(s);
}