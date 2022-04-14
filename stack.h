#define ___STACK_H___
#include <assert.h>



typedef struct stack{
	int *stack;	    
	int tamanho;		
	int numeroelems;	
} STACK;

STACK *new_stack();
void push(STACK *s, int elem);
int pop(STACK *s);
void printStack(STACK *s);