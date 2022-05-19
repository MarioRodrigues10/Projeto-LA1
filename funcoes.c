#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "stack.h"
#include "parser.h"
#include "funcoesStack.h"

/**Macro usada para calcular o tipo do elemento que vai ser colocado na stack. */
#define MAX(a,b) (((a)>(b)) ? (a):(b))

/**
 * @brief transforma qualquer elemento da stack em double
 * @param elemento elemento a ser convertido
 * @return devolve uma nova stack
 */
double toDouble(DATA elemento){
	if(elemento.type == DOUBLE){
		return elemento.DOUBLE;
	}
	else if(elemento.type == LONG){
		return elemento.LONG;
	}
	else if(elemento.type == CHAR){
		return elemento.CHAR;
	}
	else{
		return 0;
	}
	return 0;
}


/**
 * @brief Soma os 2 valores que estão no topo da stack
 * @param s stack
 */
void adicionar(STACK *s) {             
	if(has_type(penultimo(s), STRING) && has_type(top(s), LONG)){
        long x = pop_LONG(s);
        char* y = pop_STRING(s);
        char* x2 = x + "\0";
        push_STRING(s, strcat(y,x2));
	}
	else if(has_type(penultimo(s), CHAR) && has_type(top(s), STRING)){
		char* x = pop_STRING(s);
		char y = pop_CHAR(s);
		char *x2 = malloc(sizeof(char)*2+sizeof(x)*2);
		x2[0] = y;
		x2[1] = '\0';
		push_STRING(s, strcat(x2,x));
	}else if(has_type(top(s), CHAR) && has_type(penultimo(s), STRING)){
		char x = pop_CHAR(s);
		char* y = pop_STRING(s);
		char* x2 = malloc(sizeof(char)*2+sizeof(y)*2);
		x2[0] = x;
		x2[1] = '\0';
		push_STRING(s, strcat(y,x2));
	}else if(has_type(top(s), STRING) && has_type(penultimo(s), STRING)){
        char* x = pop_STRING(s);
        char* y = pop_STRING(s);
        char* r = malloc(sizeof(char) * (strlen(x) + strlen(y) + 1));
        strcpy(r,y);
		strcat(r,x);
        push_STRING(s, r);
    } else if(has_type(top(s), ARRAYS) && (has_type(penultimo(s), CHAR) || has_type(penultimo(s), LONG) || has_type(penultimo(s), DOUBLE))){
        struct stack* x = pop_ARRAYS(s);
        DATA y = pop(s);
        int i = x->numeroelems;
        push(x, x->stack[i-1]);
        i--;
        while(i > 0){
            x->stack[i] = x->stack[i -1];
            i--;
        }
       
        x->stack[0] = y;

        push_ARRAYS(s, x);
    } else if(has_type(top(s), ARRAYS) && (has_type(penultimo(s), CHAR) || has_type(penultimo(s), LONG) || has_type(penultimo(s), DOUBLE) )){
        struct stack* x = pop_ARRAYS(s);
        DATA y = pop(s);

        push(x, y);

        push_ARRAYS(s, x);
    } else if(has_type(top(s), LONG) && has_type(penultimo(s), ARRAYS)){
        long x = pop_LONG(s);
        struct stack* array = pop_ARRAYS(s);
		int tamanho = array->numeroelems;
		int i = 0;
		while(i < tamanho){
			array->stack[i].LONG = array->stack[i].LONG + x;
			i++;
		}
		push_ARRAYS(s, array);
    } else if(has_type(top(s), ARRAYS) && has_type(penultimo(s), ARRAYS)){
        struct stack* array1 = pop_ARRAYS(s);   // juntar 1 ao 2
        struct stack* array2 = pop_ARRAYS(s);

        int i = 0;
        while(i < array1->numeroelems){
            push(array2,array1->stack[i]); 
            i++;
        }

        push_ARRAYS(s, array2);
    }
	else{
		DATA x = pop(s);
  		DATA y = pop(s);
		double tx = toDouble(x);
		double ty = toDouble(y);
		converte_Puxa(s, ty+tx, MAX(x.type, y.type));
	}
}

/**
 * @brief Subtrai os 2 valores que estão no topo da stack
 * @param s stack
 */
void sub(STACK *s) {             
  	DATA x = pop(s);
  	DATA y = pop(s);
	double tx = toDouble(x);
	double ty = toDouble(y);
	converte_Puxa(s, ty-tx, MAX(x.type,y.type));
}

/**
 * @brief Multiplica os 2 valores que estão no topo da stack
 * @param s stack
 */
void multiply(STACK *s){
	if(has_type(top(s), LONG) && has_type(penultimo(s), STRING)){
        long x = pop_LONG(s);
        char *s1 = pop_STRING(s);
        int i;
        int j;
        int k = 0;
        char *resultado = malloc((((sizeof(s1))*x)+1)*(sizeof(char)));
		int tamanho2 = strlen(s1);
        for(i=0; i< tamanho2; i++){
			
            resultado[i] = s1[i];
        }
        for(j=i; j < tamanho2 * x; j++) {
             resultado[j] = resultado[k];
             k++;
        }
        resultado[(sizeof(s1)*x)] = '\0';
        push_STRING(s, resultado);

    } else if(has_type(top(s), LONG) && has_type(penultimo(s), ARRAYS)){
        long n = pop_LONG(s);
        struct stack* array = pop_ARRAYS(s);

        long i;
        long k = 0;
        long tam = array->numeroelems;


        for(i=0; i<((n-1)*tam); i++){
            if(array->tamanho == array->numeroelems){
                array->tamanho += 100;
                array->stack = (DATA *) realloc(array->stack, array->tamanho * sizeof(DATA));
            }
            array->stack[array->numeroelems] = array->stack[k];
            k++;
            array->numeroelems++;

        }
        push_ARRAYS(s, array);
    }
	else if(has_type(top(s), BLOCKS) && has_type(penultimo(s), ARRAYS)){

	}
	else{
		DATA x = pop(s);
		DATA y = pop(s);
		double tx = toDouble(x);
		double ty = toDouble(y);
		converte_Puxa(s, ty*tx, MAX(x.type,y.type));			
	}
}
/**
 * @brief Divide os 2 valores que estão no topo da stack
 * @param s stack
 */
void divisao(STACK *s){      
	if(has_type(top(s), STRING) && has_type(penultimo(s), STRING)){  
		char* x = pop_STRING(s);
		char* y = pop_STRING(s);
		struct stack* s1 = stack_new();
    	int size = 0;
		for (char *new_string = strtok(y, x); new_string != NULL; new_string = strtok(NULL, x)) {
			push_STRING(s1, new_string);
			size++;
		}
		push_ARRAYS(s, s1);
	}
	else{
		DATA x = pop(s);                                     
		DATA y = pop(s);                                     
		double tx = toDouble(x);
		double ty = toDouble(y);
		converte_Puxa(s, ty/tx, MAX(x.type,y.type));      
	}                                     
  	
}

/**
 * @brief Calcula o resto entre os 2 valores que estão no topo da stack
 * @param s stack
 */
void modulo(STACK *s){ 
	if(has_type(top(s), BLOCKS)){
		char *bloco = pop_BLOCKS(s);
		parse_lineB(s, bloco);
	}
	else{
		DATA x = pop(s);                                
		DATA y = pop(s);                                
		long tx = toDouble(x);
		long ty = toDouble(y);
		converte_Puxa(s, ty%tx, MAX(x.type,y.type));
	}
}
/**
 * @brief Coloca o 2º valor do topo da stack elevado ao 1º valor do topo da stack
 * @param s stack
 */
void expoente(STACK *s) { 
	if(has_type(top(s), STRING) && has_type(penultimo(s), STRING)){
		char *s1 = pop_STRING(s);
		char *s2 = pop_STRING(s);
		int pos = -1;
		if(strstr(s2, s1) != NULL) pos = (int)(strstr(s2, s1) - s2);

		push(s, converte((double)pos, LONG));
	}
	else if(has_type(top(s), LONG) && has_type(penultimo(s), ARRAYS)){
		long n = pop_LONG(s);
		struct stack* array = pop_ARRAYS(s);
		int i = array->numeroelems;
		DATA x[1000];
		int j;
		for(j=0; j < i; j++){
			x[j] = pop(array);
		}
		while(j > 0){
			long valor = x[j-1].LONG;
			long total = valor;
			for(int t=0; t < (n-1); t++){
				total *= valor;
			}
			push(array, (DATA){.LONG = total, .type = LONG});
			j--;
		}
		push_ARRAYS(s, array);
	}
	else {
		DATA x = pop(s);
		DATA y = pop(s);
		double tx = toDouble(x);
		double ty = toDouble(y);
		converte_Puxa(s, pow(ty, tx), MAX(x.type,y.type));
	}
}

/**
 * @brief Incrementa o valor que está no topo da stack
 * @param s stack
 */
void inc(STACK *s){
	if(has_type(top(s), STRING)){
		char *s1 = pop_STRING(s);
		char *s2 = malloc((strlen(s1)+1)*(sizeof(char)));
		int tamanho = strlen(s1);
		int i;
		char especial = s1[tamanho-1];
		for(i=0; i < tamanho-1; i++){
			s2[i] = s1[i];
		}
		push_STRING(s, s2);
		push_CHAR(s, especial);
	}
	else if(has_type(top(s), ARRAYS)){
		struct stack* array = pop_ARRAYS(s);
		DATA x = pop(array);
		push_ARRAYS(s, array);
		push(s,x);
	}
	else{
		DATA x = pop(s);
		double tx = toDouble(x);
		converte_Puxa(s, tx+1, x.type);
	}
}

/**
 * @brief Decrementa o valor que está no topo da stack
 * @param s stack
 */
void dec(STACK *s){
	if(has_type(top(s), STRING)){
		char *s1 = pop_STRING(s);
		int tamanho = strlen(s1);
		int i;
		char especial = s1[0];
		for(i=0; i<tamanho; i++){
			s1[i] = s1[i+1];
		}
		push_STRING(s, s1);
		push_CHAR(s, especial);
	}
	else if(has_type(top(s), ARRAYS)){
		struct stack* array = pop_ARRAYS(s);
		DATA a[1000];
		int i;
		int b = array->numeroelems;
		for(i = 0; i < b; i++){
			a[i] = pop(array);
		}
		for(int j = b-2; j >= 0; j--){
			push(array, a[j]);
		}
		push_ARRAYS(s,array);
		push(s, a[i-1]);
	}
	else{
		DATA x = pop(s);
		double tx = toDouble(x);
		converte_Puxa(s, tx-1, x.type);	
	}
}

/**
 * @brief Calcula o valor lógico do AND entre os 2 valores que estão no topo da stack
 * @param s stack
 */
void and(STACK *s) {                              
    DATA x = pop(s);                                
    DATA y = pop(s);                                
   	long tx = toDouble(x);
	long ty = toDouble(y);
	converte_Puxa(s, tx&ty, MAX(x.type,y.type));
}

/**
 * @brief Calcula o valor lógico do OR entre os 2 valores que estão no topo da stack
 * @param s stack
 */
void xor(STACK *s)  {                                   
    DATA x = pop(s);                                
    DATA y = pop(s);                                
    long tx = toDouble(x);
	long ty = toDouble(y);
	converte_Puxa(s, tx^ty, MAX(x.type, y.type));           
}

/**
 * @brief Calcula o valor lógico de NOT do elemento no topo da stack
 * @param s stack
 */
void not(STACK *s){
	if(has_type(top(s), BLOCKS)){
		char* bloco = pop_BLOCKS(s);
		parse_lineB(s, bloco);
	}
	else if(top(s).type == ARRAYS){
		struct stack* array = pop_ARRAYS(s);
		int i;
		DATA x[BUFSIZ];
		int b = array->numeroelems;
		for(i=0 ; i < b; i++){
			x[i] = pop(array);
		}
		int j;
		for(j = b-1 ; j >= 0; j--){
			push(s, x[j]);
		}
	}
	else if(top(s).type != ARRAYS && top(s).type != STRING){                             
		DATA x = pop(s);                                
		long tx = toDouble(x);
		converte_Puxa(s, ~tx, x.type);
	}
}

/**
 * @brief Calcula o valor lógico do OR entre os 2 valores que estão no topo da stack
 * @param s stack
 */
void or(STACK *s){                                   
    DATA x = pop(s);                                
    DATA y = pop(s);                                
	long tx = toDouble(x);
	long ty = toDouble(y);
	converte_Puxa(s, tx|ty, MAX(x.type,y.type));
}

