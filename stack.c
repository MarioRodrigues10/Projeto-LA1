#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

STACK *new_stack(){
	STACK *s = (STACK *) calloc(1, sizeof(STACK));
	s->tamanho = 10000;
	s->stack = (int *) calloc(s->tamanho, sizeof(int));
	return s;
}

void push(STACK *s, int elem){
	if(s->tamanho == s->numeroelems){
		s->tamanho += 200;
		s->stack = (int *) realloc(s->stack, s->tamanho * sizeof(int));
	}
	s->stack[s->numeroelems] = elem;
	s->numeroelems++;
}

int pop(STACK *s){
	s->numeroelems--;
	return s->stack[s->numeroelems];
}

//print stack
void printStack(STACK *s){
    int i;
    for(i = 0; i < (s->numeroelems)-1; i++){
        printf("%d ", s->stack[i]);
    }
    printf("\n");
}
