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
#include "funcoesArrays.h"
#include "funcoesBlocos.h"

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
    tabelaOp['G'] = varG;
    tabelaOp['H'] = varH;
    tabelaOp['I'] = varI;
    tabelaOp['J'] = varJ;
    tabelaOp['K'] = varK;
    tabelaOp['L'] = varL;
    tabelaOp['M'] = varM;
    tabelaOp['N'] = varN;
    tabelaOp['O'] = varO;
    tabelaOp['P'] = varP;
    tabelaOp['Q'] = varQ;
    tabelaOp['R'] = varR;
    tabelaOp['S'] = varS;
    tabelaOp['T'] = varT;
    tabelaOp['U'] = varU;
    tabelaOp['V'] = varV;
    tabelaOp['W'] = varW;
    tabelaOp['X'] = varX;
    tabelaOp['Y'] = varY;
    tabelaOp['Z'] = varZ;
    tabelaOp[','] = range_array;
    tabelaOp['t'] = lertudo;
    tabelaOp[130] = separa_por_espaco;
    tabelaOp[125] = separa_por_newlines;
    // N/ = 78 + 47 = 125
}

void iniciar_dispatchtableBlocos(dispatch_table *tabelaOp){
    tabelaOp['+'] = adicionar;
    tabelaOp['-'] = sub;
    tabelaOp['*'] = multiply;
    tabelaOp['/'] = divisao;
    tabelaOp['('] = dec_blocos;
    tabelaOp[')'] = inc_blocos;
    tabelaOp['#'] = expoente_blocos;
    tabelaOp['*'] = multiply_blocos;
    tabelaOp['l'] = lerLinha;
    tabelaOp['i'] = converteInt;
    tabelaOp['t'] = lertudo;
    tabelaOp[','] = range_AB;
    tabelaOp['S'] = varS;
    tabelaOp['V'] = varV;
    tabelaOp['\\'] = trocar_Blocos;
    tabelaOp['='] = igual_Blocos;
}




/**
 * @brief função responsável por tratar o conteúdo que está na linha, se for um número coloca na stack. Caso contrário procura se existe um função associdada ao caracter
 * @param s stack
 * @param token token da linha
 */ 
void handle(STACK *s,char *token){
    dispatch_table tabelaOp[1000];
    iniciar_dispatchtable(tabelaOp);
    char *resto;
    char *resto2;
    long num = strtol(token, &resto, 10);
    double num2 = strtod(token, &resto2);
    ////printf("TOKEN:%s\n", token);
    if(strlen(resto) == 0){
            push (s, (DATA){.type = LONG, .LONG = num});
    }
    else if(strlen(resto2) == 0){
            ////printf("NUM2:%lf\n", num2); //FLOAT
            push (s, (DATA){.type = DOUBLE, .DOUBLE = num2});
    }
    else{
        if(strlen(resto) >= 2) {
            if(resto[0] == ':'){
                if((has_type(top(s),BLOCKS) || has_type(top(s),STRING)) == 1){
                    if (has_type(top(s), STRING) == 1) 
                    {          
                            char *string = pop_STRING(s);
                            char *string2 = malloc(sizeof(char)*(sizeof(string)+1));
                            strcpy(string2,string);
                            s -> letras[resto[1] - 65] = (DATA){.type = STRING, .STRING = string2};
                            push_STRING(s, string2);
                    }
                    else 
                    {   
                        char *bloco = pop_BLOCKS(s);
                        char *string = malloc(sizeof(char)*(sizeof(bloco))+1);
                        strcpy(string,bloco);
                        s -> letras[resto[1] - 65] = (DATA){.type = BLOCKS, .BLOCKS = string};
                        push_BLOCKS(s, bloco);
                    }
                }
                else{
                    DATA x = pop(s);
                    double y = toDouble(x);
                    s->letras[resto[1]-65] = converte(y,1);
                    push(s, x);
                }
            
            }
            else{
                
                //printf("A:%s\n", resto);
                unsigned int unsigned_int = (unsigned int)resto[1] + (unsigned int)resto[0];
                //printf("B:%d\n", unsigned_int);
                tabelaOp[unsigned_int](s);
                }
        }
        else{
            unsigned char unsigned_resto = (unsigned char) resto[0];
            tabelaOp[unsigned_resto](s);
        }
    }
}


/**
 * \brief função responsável por fazer a leitura de uma linha e enviar o conteúdo para ser tratado no handle
 * @param s stack
 */
void parse_line(STACK *s, char* line) {
    char token[BUFSIZ];
    while (sscanf(line, "%s%[^\n]", token, line) == 2) {
            if(token[0] == '['){	
                STACK *new = stack_new();
                line = parse_line3(s,new, line);  						
                push_ARRAYS(s, new); 
            }
            else if(token[0] == '{'){
                line = trata_blocos(s, line);
            }
            else if(token[0] == '\"'){
                line = strcat(token, line);
                line = scanForStrings(s, line);
            }
            else if(strlen(token) > 30){
                push(s, (DATA){.type = STRING, .STRING = token});
            }
            else{
                handle(s, token);	
            }
    }
    if(token[0] == '\"'){
        line = strcat(token, line);
        line = scanForStrings(s, line);
    }
    else if(strlen(token) > 30){
        push(s, (DATA){.type = STRING, .STRING = token});
    }
    else if(token[0] != ']' && token[0] != '{') {
        handle(s,token);
    }
}

char* scanForStrings(STACK *s, char *line){
   char *string = malloc(sizeof(char) * strlen(line));
   char *resto = malloc(sizeof(char) * strlen(line));

   divide_string_by_token(line, '\"', string, resto);
   push(s, (DATA){.type = STRING, .STRING = string});  
   return resto;
}

void divide_string_by_token(char *line, char token, char *before_token, char *after_token) {
    char *string = malloc(sizeof(char) * strlen(line));
    strcpy(string, line);

    char *rest_of_line = malloc(sizeof(char) * strlen(line));

    int rol = 0;

    if (string[0] == ' ') {
        char *copy = malloc(sizeof(char) * strlen(line));
        strcpy(copy, line);
        strcpy(string, copy + 1);
    }

    if (string[0] == token) {
        char *copy = malloc(sizeof(char) * strlen(line));
        strcpy(copy, line);
        strcpy(string, copy + 1);
    }

    int size = (int)strlen(line);

    for (int i = 0; i < size - 1; i++) {
        if (rol) {
            rest_of_line[strlen(rest_of_line)] = string[i + 1];
        } else if (string[i] == token) {
            string[i] = '\0';
            rol = 1;
        }
    }

    strcpy(before_token, string);
    strcpy(after_token, rest_of_line);
}

char *parse_line3(STACK *a, STACK *new, char *line) {
    char token[BUFSIZ];
    while (sscanf(line, "%s%[^\n]", token, line) == 2) {
            if (token[0] == ']'){
                return line;
            }
            else if (token[0] == '\"'){
                line = strcat(token, line);
                line = scanForStrings(new, line);
            }
            else{
                if(token[0] == ':'){
                    DATA z = pop(new);
                    new -> letras[token[1] - 65] = z;
                    a -> letras[token[1] - 65] = z;
                    push(new, z);
                }
                else{
                    if(token[0] == 'A' || token[0] == 'B' || token[0] == 'C' || token[0] == 'D' || token[0] == 'E' || token[0] == 'F' || token[0] == 'G' || token[0] == 'H' || token[0] == 'I' || token[0] == 'J' || token[0] == 'K' || token[0] == 'L' || token[0] == 'M' || token[0] == 'N' || token[0] == 'O' || token[0] == 'P' || token[0] == 'Q' || token[0] == 'R' || token[0] == 'S' || token[0] == 'T' || token[0] == 'U' || token[0] == 'V' || token[0] == 'W' || token[0] == 'X' || token[0] == 'Y' || token[0] == 'Z'){
                        push(new, a->letras[token[0] - 65]);
                    }
                    else{
                        handle(new, token);
                    }
                }
            }
        }
        if (token[0] == ']'){
            return line;
        }
        else if(token[0] == '\"'){
            line = strcat(token, line);
            line = scanForStrings(new, line);
            return line;
        }
        else{
            if(token[0] == ':'){
                DATA z = pop(new);
                new -> letras[token[1] - 65] = z;
                a -> letras[token[1] - 65] = z;
                push(new, z);
            }
            else if(token[0] == 'A' || token[0] == 'B' || token[0] == 'C' || token[0] == 'D' || token[0] == 'E' || token[0] == 'F' || token[0] == 'G' || token[0] == 'H' || token[0] == 'I' || token[0] == 'J' || token[0] == 'K' || token[0] == 'L' || token[0] == 'M' || token[0] == 'N' || token[0] == 'O' || token[0] == 'P' || token[0] == 'Q' || token[0] == 'R' || token[0] == 'S' || token[0] == 'T' || token[0] == 'U' || token[0] == 'V' || token[0] == 'W' || token[0] == 'X' || token[0] == 'Y' || token[0] == 'Z'){
                push(new, a->letras[token[0] - 65]);
            }
            else{
                handle(new, token);
            }
            return line;
        }
    return line;
}


char *trata_blocos(STACK *s, char *line) {
    char* block = malloc(sizeof(char) * 10240);
    int number_of_left_brackets = 1, number_of_right_brackets = 0, i;
    block[0] = '{';
    block[1] = ' ';
    line++;
    for (i = 2; number_of_left_brackets != number_of_right_brackets; line++, i++) {
        if (*line == '{') number_of_left_brackets++;
        else if (*line == '}') number_of_right_brackets++;
        block[i] = *line;
    }
    block[i] = '\0';
    push_BLOCKS(s, block);
    return line;
}

void parse_lineB(STACK *s, char *line) {
    char token[BUFSIZ];
    if (*line == '{') line++;
    while (sscanf(line, "%s%[^\n]", token, line) == 2) {
        if(token[0] == '['){	
            STACK *new = stack_new();
            line = parse_line3(s,new, line);  						
            push_ARRAYS(s, new); 
            }
        else if(token[0] == '\"'){
            line = strcat(token, line);
            line = scanForStrings(s, line);
            }
        else if(strlen(token) > 30){
            push(s, (DATA){.type = STRING, .STRING = token});
        }
        else{
            if(token[0] == ':'){
                DATA z = pop(s);
                s -> letras[token[1] - 65] = z;
                push(s, z);
            }
            else handle_B(s, token);	
        }
    }
    if(token[0] == '\"'){
        line = strcat(token, line);
        line = scanForStrings(s, line);
    }
    else if(strlen(token) > 30){
        push(s, (DATA){.type = STRING, .STRING = token});
    }
    else if(token[0] != ']' && token[0] != '{' && token[0] != '}'){
        if(token[0] == ':'){
            DATA z = pop(s);
            s -> letras[token[1] - 65] = z;
            push(s, z);
        }
        else handle_B(s,token);
    }
}

void handle_B(STACK *s, char *token){

    dispatch_table tabelaOp[1000];
    iniciar_dispatchtableBlocos(tabelaOp);
    char *resto;
    char *resto2;
    long num = strtol(token, &resto, 10);
    double num2 = strtod(token, &resto2);
    if(strlen(resto) == 0){
        push_LONG(s, num);
    }
    else if(strlen(resto2) == 0){
        push_DOUBLE(s, num2);
    }
    else{
        if(strlen(resto) >= 2) {
            if(resto[0] == ':'){
                if(has_type(top(s), STRING)){
                    DATA z = pop(s);
                    s -> letras[resto[1] - 65] = z;
                    push(s, z);
                }
                else{
                      DATA x = pop(s);
                      double y = toDouble(x);
                      s->letras[resto[1]-65] = converte(y,1);
                      push(s, x);
                }
            
            }
            else{
                unsigned int unsigned_int = (unsigned int)resto[1] + (unsigned int)resto[0];
                tabelaOp[unsigned_int](s);
                }
        }
        else{
            unsigned char unsigned_resto = (unsigned char) resto[0];
            tabelaOp[unsigned_resto](s);
        }
    }
}

