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

/** 
 * \brief função que inicializa o nosso array das Letras com os valores iniciais
 * @param s stack
 */
void iniciarArray(STACK *s){
    double num1 = 10;
    s->letras[0] = converte(num1,1); 
    s->letras[1] = converte(num1+1, 1);
    s->letras[2] = converte(num1+2, 1);
    s->letras[3] = converte(num1+3, 1);
    s->letras[4] = converte(num1+4, 1);
    s->letras[5] = converte(num1+5, 1);
    s->letras[13] = converte('\n', 4);
    s->letras[18] = converte(' ', 4);
    s->letras[23] = converte(0, 1);
    s->letras[24] = converte(1, 1);
    s->letras[25] = converte(2, 1);
}

/**
 * @brief função responsável por colocar o conteúdo da variável A na stack
 * @param s 
 */
void varA(STACK *s){
    push(s, s->letras[0]);
}

/**
 * @brief função responsável por colocar o conteúdo da variável B na stack
 * @param s 
 */
void varB(STACK *s){
    push(s, s->letras[1]);
}

/**
 * @brief função responsável por colocar o conteúdo da variável C na stack
 * @param s 
 */
void varC(STACK *s){
    push(s, s->letras[2]);
}

/**
 * @brief função responsável por colocar o conteúdo da variável D na stack
 * @param s 
 */
void varD(STACK *s){
    push(s, s->letras[3]);
}

/**
 * @brief função responsável por colocar o conteúdo da variável E na stack
 * @param s 
 */
void varE(STACK *s){
    push(s, s->letras[4]);
}

/**
 * @brief função responsável por colocar o conteúdo da variável F na stack
 * @param s 
 */
void varF(STACK *s){
    push(s, s->letras[5]);

}

void varG(STACK *s){
    push(s, s->letras[6]);

}

void varH(STACK *s){
    push(s, s->letras[7]);
}

void varI(STACK *s){
    push(s, s->letras[8]);
}

void varJ(STACK *s){
    push(s, s->letras[9]);
}

void varK(STACK *s){
    push(s, s->letras[10]);
}

void varL(STACK *s){
    push(s, s->letras[11]);
}

void varM(STACK *s){
    push(s, s->letras[12]);
}

/**
 * @brief função responsável por colocar o conteúdo da variável N na stack
 * @param s 
 */
void varN(STACK *s){
    push(s, s->letras[13]);
}

void varO(STACK *s){
    push(s, s->letras[14]);
}

void varP(STACK *s){
    push(s, s->letras[15]);
}

void varQ(STACK *s){
    push(s, s->letras[16]);
}

void varR(STACK *s){
    push(s, s->letras[17]);
}

/**
 * @brief função responsável por colocar o conteúdo da variável S na stack
 * @param s 
 */
void varS(STACK *s){
    if (has_type(top(s),ARRAYS)){
        struct stack *a = pop_ARRAYS(s);
        int i = 0;
        DATA x[1000];
        while(a->numeroelems > 0){
            x[i] = pop(a);
            i++;
        }
        for(int j = i; j > 0; j--){
            push(a, x[j-1]);
            push(a, s->letras[18]);
        }
        push_ARRAYS(s, a);
    }

    else push(s, s->letras[18]);
}

void varT(STACK *s){
    if (has_type(top(s),ARRAYS)){
        printf("entrei2\n");
        struct stack *a = pop_ARRAYS(s);
        int i = 0;
        DATA x[1000];
        while(a->numeroelems > 0){
            x[i] = pop(a);
            i++;
        }
        for(int j = i; j > 0; j--){
            push(a, x[j-1]);
            push(a, s->letras[18]);
        }
        push_ARRAYS(s, a);
    }
    else push(s, s->letras[19]);
}

void varU(STACK *s){
    push(s, s->letras[20]);
}

void varV(STACK *s){
    if (has_type(top(s),ARRAYS)){
        printf("entrei2\n");
        struct stack *a = pop_ARRAYS(s);
        int i = 0;
        DATA x[1000];
        while(a->numeroelems > 0){
            x[i] = pop(a);
            i++;
        }
        for(int j = i; j > 0; j--){
            push(a, x[j-1]);
            push(a, s->letras[21]);
        }
        printStack(a);
        printf("\n");
        push_ARRAYS(s, a);
    }
    else push(s, s->letras[21]);
}

void varW(STACK *s){
    push(s, s->letras[22]);
}

/**
 * @brief função responsável por colocar o conteúdo da variável X na stack
 * @param s 
 */
void varX(STACK *s){
    push(s, s->letras[23]);
}

/**
 * @brief função responsável por colocar o conteúdo da variável Y na stack
 * @param s 
 */
void varY(STACK *s){
    push(s, s->letras[24]);
}

/**
 * @brief função responsável por colocar o conteúdo da variável Z na stack
 * @param s 
 */
void varZ(STACK *s){
    push(s, s->letras[25]);
}

