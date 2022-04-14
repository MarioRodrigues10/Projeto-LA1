#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


/**
 * @brief cria uma nova stack
 * @return devolve uma nova stack
*/
STACK *new_stack(){
	STACK *s = (STACK *) calloc(1, sizeof(STACK));
	s->tamanho = 10000;
	s->stack = (int *) calloc(s->tamanho, sizeof(int));
	return s;
}
/**
 * \brief A função push recebe uma stack e um inteiro, e adiciona esse inteiro na stack.
 * @param s stack
 * @param valor inteiro a ser adicionado
 */
void push(STACK *s, int elem){
	if(s->tamanho == s->numeroelems){
		s->tamanho += 200;
		s->stack = (int *) realloc(s->stack, s->tamanho * sizeof(int));
	}
	s->stack[s->numeroelems] = elem;
	s->numeroelems++;
}

/**
 * \brief A função pop recebe uma stack e devolve o último inteiro adicionado na stack.
 * @param s stack
 * @return inteiro
 */
int pop(STACK *s){
	s->numeroelems--;
	return s->stack[s->numeroelems];
}

/**
 * \brief A função printStack recebe uma stack e imprime os elementos da stack.
 * @param s stack
 */
void printStack(STACK *s){
    int i;
    for(i = 0; i < (s->numeroelems)-1; i++){
        printf("%d", s->stack[i]);
    }
    printf("\n");
}
