#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"
#include "parser.h"
#include "funcoes.h"


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
 * \brief A função stringToInt recebe uma string e devolve um inteiro.
 * @param str token a ser convertido
 * @param endptr endereço do ponteiro para o endereço do primeiro caracter não convertido
 * @param base base da conversão
 * @return  int
 */
 int stringToInt(char *str, char **endptr, int base){
    char *p;
    long int ret;

    ret = strtol(str, &p, base);
    if(endptr != NULL){
        *endptr = p;
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
    while(token != NULL){
        char *resto;
         int num = stringToInt(token, &resto, 10);
        if(strlen(resto) == 0) {
            push(s,num);
        }
        else if(strcmp(token, "+") == 0){
            adicionar(s);
        }
        else if(strcmp(token, "-") == 0){
            sub(s);
        }
        else if(strcmp(token, "*") == 0){
            multiply(s);
        }
        else if(strcmp(token, "/") == 0){
            divisao(s);
        }
        else if(strcmp(token, "#") == 0){
           expoente(s);
        }
        else if(strcmp(token, "(") == 0){
            dec(s);
        }
        else if(strcmp(token, ")") == 0){
           inc(s);
        }
        else if(strcmp(token, "%") == 0){
            modulo(s);
        }
        else if(strcmp(token, "&") == 0){
            and(s);
        }
        else if(strcmp(token, "|") == 0){
            or(s);
        }
        else if(strcmp(token, "^") == 0){
            xor(s);
        }
        else if(strcmp(token, "~") == 0){
            not(s);
        }
        else{
            printf("ERROR\n");
        }
        token = splitStrings(NULL,limite);
    }
    printStack(s);
}