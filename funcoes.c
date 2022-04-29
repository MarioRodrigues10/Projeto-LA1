#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
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
  	DATA x = pop(s);
  	DATA y = pop(s);
	double tx = toDouble(x);
	double ty = toDouble(y);
	converte_Puxa(s, ty+tx, MAX(x.type, y.type));
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
void multiply(STACK *s) {             
  	DATA x = pop(s);
  	DATA y = pop(s);
  	double tx = toDouble(x);
	double ty = toDouble(y);
	converte_Puxa(s, ty*tx, MAX(x.type,y.type));
}

/**
 * @brief Divide os 2 valores que estão no topo da stack
 * @param s stack
 */
void divisao(STACK *s) {                                      
    DATA x = pop(s);                                     
    DATA y = pop(s);                                     
    double tx = toDouble(x);
	double ty = toDouble(y);
	converte_Puxa(s, ty/tx, MAX(x.type,y.type));                                           
  	
}

/**
 * @brief Calcula o resto entre os 2 valores que estão no topo da stack
 * @param s stack
 */
void modulo(STACK *s)  {                                 
    DATA x = pop(s);                                
    DATA y = pop(s);                                
	long tx = toDouble(x);
	long ty = toDouble(y);
	converte_Puxa(s, ty%tx, MAX(x.type,y.type));
}
/**
 * @brief Coloca o 2º valor do topo da stack elevado ao 1º valor do topo da stack
 * @param s stack
 */
void expoente(STACK *s) {             
  	DATA x = pop(s);
  	DATA y = pop(s);
	double tx = toDouble(x);
	double ty = toDouble(y);
	converte_Puxa(s, pow(ty, tx), MAX(x.type,y.type));
}

/**
 * @brief Incrementa o valor que está no topo da stack
 * @param s stack
 */
void inc(STACK *s){
	DATA x = pop(s);
	double tx = toDouble(x);
	converte_Puxa(s, tx+1, x.type);
}

/**
 * @brief Decrementa o valor que está no topo da stack
 * @param s stack
 */
void dec(STACK *s){
	DATA x = pop(s);
	double tx = toDouble(x);
	converte_Puxa(s, tx-1, x.type);	
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
    DATA x = pop(s);                                
	long tx = toDouble(x);
	converte_Puxa(s, ~tx, x.type);
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

