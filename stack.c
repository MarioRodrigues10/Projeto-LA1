#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


// elem número a ser comparado
// Bitmask  (mask) que compara com o tipo do número associado.
// retorna true se tiverem o mesmo tipo
int has_type(DATA elem, int mask){
	return (elem.type & mask) != 0;
}


void push(STACK *s, DATA elem){
	if(s->size == s->n_elems){
		s->size += 200;
		s->stack = (DATA *) realloc(s->stack, s->size * sizeof(DATA));
	}
	s->stack[s->n_elems] = elem;
	s->n_elems++;
}

DATA pop(STACK *s){
	s->n_elems--;
	return s->stack[s->n_elems];
}
