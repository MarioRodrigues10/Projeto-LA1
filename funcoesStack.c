#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#include "stack.h"
#include "parser.h"
#include "funcoesStack.h"
#include "funcoes.h"

/**
 * @brief transforma qualquer elemento da stack em int e coloca na stack
 * @param s stack
 */
void converteInt(STACK *s) {             
    DATA x = pop(s);                         
    if(has_type(x,DOUBLE)) {  
        DATA res;  
        res.type= LONG;                                    
		res.LONG = x.DOUBLE;
		push(s,res); 
    } 
    else if(has_type(x,CHAR)) {              
      DATA res;
      res.type = LONG;
      res.LONG = x.CHAR;
      push(s,res);
    } 
    else if(has_type(x,LONG)){
        push(s,x);
    } 
}

/**
 * @brief transforma qualquer elemento da stack em double e coloca na stack
 * @param s stack
 */
void converterDouble(STACK *s) {             
   DATA x = pop(s);                               
        if(has_type(x,LONG)) {              
            DATA res;
            res.type = DOUBLE;
            res.DOUBLE = x.LONG;
            push(s,res);
        } 
        else if(has_type(x,DOUBLE)){
            push(s,x);
        } 
} 

/**
 * @brief transforma qualquer elemento da stack em char e coloca na stack
 * @param s stack
 */
void converteCHAR(STACK *s){
	DATA x = pop(s);
	if(has_type(x,LONG)){
        DATA y;
        y.type = CHAR;
        y.CHAR = x.LONG;
		push(s,y);
	}
	else if(has_type(x,CHAR)){
        push(s,x);
    }
}

/**
 * @brief lê uma nova linha e coloca o seu conteúdo na stack
 * @param s stack
 */
void lerLinha(STACK *s){
    char line[10240];
    assert(fgets(line, 10240, stdin) != NULL);

    if(isdigit(line[0])){ 
        parse_line(s,line);
    }
    else{
        char *input = malloc(sizeof(char)*(strlen(line)+1));
        strcpy(input, line);
        input[strlen(input)] = '\0';
        push_STRING(s, input);
    }
}
void lertudo(STACK *s){
    char *input = malloc(sizeof(char) * 10240);
    char c;
    int i = 0;
    while((c = getchar()) != EOF) {
        input[i] = c;
        i++;
    }
    input[i+1] = '\0';
    push_STRING(s, input);
}


/**
 * @brief troca os 2 elementos do topo da stack
 * @param s stack
 */
void trocar(STACK *s){
    if(has_type(top(s),CHAR) && has_type(penultimo(s),STRING)){
        char x = pop_CHAR(s);
        char *y = pop_STRING(s);
        push_CHAR(s,x);
        push_STRING(s,y);

    }

    else{
        DATA num1 = pop(s);
        DATA num2 = pop(s);
        push(s, num1);
        push(s, num2);
        printf("fiz isto\n");
    }
}

/**
 * @brief duplica o elemento que está no topo da stack
 * @param s stack
 */
void duplicar(STACK *s){
    if(has_type(top(s),STRING)){
        char* x = pop_STRING(s);
        char* linhas = malloc(sizeof(char)*BUFSIZ);
        strcpy(linhas,x);
        push_STRING(s,x);
        push_STRING(s,linhas);
    }
    else{
        DATA num1 = pop(s);
        push(s, num1);
        push(s, num1);
    }
}

/**
 * @brief roda os 3 elementos do topo da stack
 * @param s stack
 */
void rodar3(STACK *s){
    DATA num1 = pop(s); 
    DATA num2 = pop(s); 
    DATA num3 = pop(s); 
    push(s, num2);
    push(s, num1);
    push(s, num3);
}

/**
 * @brief copia um elemento numa 'n' posição da stack para o topo
 * @param s stack
 */
void copiarNTopo(STACK *s){
    DATA listaStack[1000];
    int i = 0;
    DATA pos = pop(s);
    int x = pos.LONG;
    while(x != i){
        listaStack[i] = pop(s);
        i++;
    }
    DATA especial = pop(s);
    push(s, especial);
    while(i != 0){
        push(s, listaStack[i-1]);
        i--;
    }
    push(s, especial);
}

/**
 * @brief retira um elemento da stack
 * @param s stack
 */
void popp(STACK *s){
   pop(s);
}
