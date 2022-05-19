#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <string.h>

#include "stack.h"
#include "parser.h"
#include "funcoesStack.h"
#include "funcoes.h"
/**Macro usada para calcular o tipo do elemento que vai ser colocado na stack. */
#define MAX(a,b) (((a)>(b)) ? (a):(b))

/** 
 * @brief faz uma operação if then else entre 2 elementos
 * @param s stack
 */
void ifThenElse(STACK *s) {
    DATA x = pop(s);
    DATA y = pop(s);
    DATA z = pop(s);
    if((has_type(z, ARRAYS) && z.ARRAYS -> numeroelems > 1) || (has_type(z, STRING) && strlen(z.STRING) > 1)){
        z.DOUBLE = 1 ;
        (z.DOUBLE == 0) ? push(s, x) : push(s, y);
    }
    else if((has_type(z, ARRAYS) && z.ARRAYS -> numeroelems == 0) || (has_type(z, STRING) && strlen(z.STRING) == 0)){
        z.DOUBLE = 0 ;
        (z.DOUBLE == 0) ? push(s, x) : push(s, y);
    }
    else{
        double tz = toDouble(z);
        (tz == 0) ? push(s,x) : push(s,y);
    }
}

/** 
 * @brief faz uma operação igual then else entre 2 elementos caso forem iguais coloca 1 na stack, caso não sejam coloca 0
 * @param s stack
 */
void igual(STACK *s) {
    if(has_type(top(s), STRING) && has_type(penultimo(s), STRING)){
        char* x = pop_STRING(s);
        char* y = pop_STRING(s);
        (strcmp(x,y) == 0) ? push_LONG(s,1) : push_LONG(s,0);
    }
    else if(has_type(top(s), LONG) && has_type(penultimo(s), STRING)){
        long x = pop_LONG(s);
        char* y = pop_STRING(s);
        push_CHAR(s, y[x]);
    }
    else if(has_type(top(s), LONG) && has_type(penultimo(s), ARRAYS)){
        int x = pop_LONG(s);
        struct stack* y = pop_ARRAYS(s);
        int i = y->numeroelems -1;
        while (i != x){
            pop(y);
            i--;
        } 
        DATA p = pop(y);
        push(s,p);
    }
    else{
        DATA x = pop(s);
        DATA y = pop(s);
        double tx = toDouble(x);
        double ty = toDouble(y);
        (tx == ty) ? converte_Puxa(s, 1, LONG) : converte_Puxa(s, 0, LONG);
    }
}


/** 
 * @brief faz uma operação menor entre 2 elementos caso forem diferentes coloca 1 na stack, caso não sejam coloca 0
 * @param s stack
 */
void menor(STACK *s){
    if(has_type(top(s), STRING) && has_type(penultimo(s), STRING)){
        char* x = pop_STRING(s);
        char* y = pop_STRING(s);
        (strcmp(y,x) < 0) ? push_LONG(s,1) : push_LONG(s,0);
    }
    else if(has_type(top(s), LONG) && has_type(penultimo(s), ARRAYS)){
        int x = pop_LONG(s);
        struct stack* y = pop_ARRAYS(s);
        int j=0;
        while (j < x){
            push(s, y->stack[j]);
            j++;
        }
    }
    else if(has_type(top(s), LONG) &&(has_type(penultimo(s), STRING))){
        long x = pop_LONG(s);
        char* y = pop_STRING(s);
        char* z = malloc(sizeof(char) * (strlen(y) + 1));
        for(int i = 0; i < x; i++){
            z[i] = y[i];
        }
        push_STRING(s, z);
    }
    else{
        DATA x = pop(s);
        DATA y = pop(s);
        double tx = toDouble(x);
        double ty = toDouble(y);
        (tx < ty) ? converte_Puxa(s, 1, LONG) : converte_Puxa(s, 0, LONG);
    }
}

/** 
 * @brief faz uma operação maior entre 2 elementos caso o 1º seja menor coloca 1 na stack, caso não sejam coloca 0
 * @param s stack
 */
void maior(STACK *s){
    if(has_type(top(s), LONG) && has_type(penultimo(s), ARRAYS)){
        long x = pop_LONG(s);
        struct stack* y = pop_ARRAYS(s);
        int i = 0;
        DATA p [BUFSIZ];
        while (i < x){
            p[i] = pop(y);
            i++;
        }
        while (i >= 0){
            push(s, p[i]);
            i--;
        }

    }
    else if(has_type(top(s), LONG) &&(has_type(penultimo(s), STRING))){
        long x = pop_LONG(s);
        char* y = pop_STRING(s);
        char* z = malloc(sizeof(char) * (strlen(y) + 1));
        int j = strlen(y);
        for(int i = j-x, h = 0; i < j; i++,h++){
            z[h] = y[i];
        }
        push_STRING(s, z);
    }
    else{
        DATA x = pop(s);
        DATA y = pop(s);
        double tx = toDouble(x);
        double ty = toDouble(y);
        (tx <= ty) ? converte_Puxa(s, 1, LONG) : converte_Puxa(s, 0, LONG);
    }
}

/** 
 * @brief faz uma operação menor entre 2 elementos coloca o menor na stack
 * @param s stack
 */
void emenor(STACK *s) {
    if(has_type(top(s), STRING) && has_type(penultimo(s), STRING)){
        char* x = pop_STRING(s);
        char* y = pop_STRING(s);
        push_STRING(s, (strcmp(y,x) < 0) ? y : x);
    }
    else{
        DATA x = pop(s);
        DATA y = pop(s);
        double tx = toDouble(x);
        double ty = toDouble(y);
        (tx >= ty) ? converte_Puxa(s, ty, MAX(x.type, y.type)) : converte_Puxa(s, tx, MAX(x.type, y.type));
    }
}

/** 
 * @brief faz uma operação maior entre 2 elementos coloca o maior na stack
 * @param s stack
 */
void emaior(STACK *s) {
    if(has_type(top(s), STRING) && has_type(penultimo(s), STRING)){
        char* x = pop_STRING(s);
        char* y = pop_STRING(s);
        push_STRING(s, (strcmp(y,x) > 0) ? y : x);
    }
    else{
        DATA x = pop(s);
        DATA y = pop(s);
        double tx = toDouble(x);
        double ty = toDouble(y);
        (tx >= ty) ? converte_Puxa(s, tx, MAX(x.type, y.type)) : converte_Puxa(s, ty, MAX(x.type, y.type));
    }
}
/** 
 * @brief faz uma operação not em 1 elemento caso seja igual a 0 coloca 1 na stack, caso não seja coloca 0
 * @param s stack
 */
void nao(STACK *s) {
    DATA x = pop(s);
    double tx = toDouble(x);
    (tx == 0) ? converte_Puxa(s, 1, LONG) : converte_Puxa(s, 0, LONG);
}

/** 
 * @brief faz uma operação e entre 2 elementos caso forem diferentes de zero ambos coloca 1 na stack, caso não sejam coloca 0
 * @param s stack
 */
void e(STACK *s) {
    DATA x = pop(s);
    DATA y = pop(s);
    double tx = toDouble(x);
    double ty = toDouble(y);
    (tx != 0 && ty != 0) ? converte_Puxa(s, tx, LONG) : converte_Puxa(s, 0, LONG);
}

/** 
 * @brief faz uma operação ou entre 2 elementos caso o 2º seja diferentes de zero é recolocado na stack, caso 2º elemento seja igual a 0 , verificamos o 1º elemento caso seja diferente de 0 é recolocado na stack, caso ambos sejam iguais a 0 é colocado 0 na stack
 */
void ou(STACK *s) {
    DATA x = pop(s);
    DATA y = pop(s);
    double tx = toDouble(x);
    double ty = toDouble(y);
    (ty != 0) ? converte_Puxa(s, ty, y.type) : (tx != 0) ? converte_Puxa(s, tx, x.type) : converte_Puxa(s, 0, LONG);
}