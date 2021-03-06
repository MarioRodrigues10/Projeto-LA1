#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "stack.h"


/**
 * @brief verifica se o tipo de um elemento é igual ao tipo passado por parâmetro
 * @return 1 se os tipos forem iguais, 0 caso contrário
 */
int has_type(DATA elem, int mask) {
  return (elem.type & mask) != 0;
}

/**
 * @brief cria uma nova stack
 * @return devolve uma nova stack
 */
STACK *stack_new(){
	STACK *stack2 = (STACK *) calloc(1, sizeof(STACK));
	stack2->tamanho = 10000;
	stack2->stack = (DATA *) calloc(stack2->tamanho, sizeof(DATA));
	return stack2;
}



/**
 * \brief A função push recebe uma stack e um valor com um tipo DATA, e adiciona esse valor à stack.
 * @param s stack
 * @param valor inteiro a ser adicionado
 */
void push(STACK *s, DATA valor){
	if(s->numeroelems == s->tamanho){
		s->tamanho += 200;
		s->stack = (DATA *) realloc(s->stack, s->tamanho * sizeof(DATA));
	}
	s->stack[s->numeroelems] = valor;
	s->numeroelems++;
}
/**
 * \brief A função pop recebe uma stack e devolve o último inteiro adicionado na stack.
 * @param s stack
 * @return inteiro
 */
DATA pop(STACK *s){
	s->numeroelems--;
	return s->stack[s->numeroelems];
}

/**
 * \brief A função printStack recebe uma stack e imprime os elementos da stack.
 * @param s stack
 */
void printStack(STACK *s){
	for(int i = 0; i < s -> numeroelems; i++){
			DATA elem = s->stack[i];
			TYPE type = elem.type;
			if(type == LONG){
				printf("%ld", elem.LONG);
			}
			else if(type == DOUBLE){
				printf("%g", elem.DOUBLE);
			}
			else if(type == CHAR){
				if(elem.CHAR == '\n'){
					printf("\n");
				}
				else printf("%c", elem.CHAR);
			}
			else if(type == STRING){
				printf("%s", elem.STRING);
			}
			else if(type == ARRAYS){
				printStack(elem.ARRAYS);
			}
			else if(type == BLOCKS){
				printf("%s", elem.BLOCKS);
			}
	}
}


/**
 * @brief Função que converte um double para o seu tipo respetivo e adiciona-o à stack
 * @param s stack
 * @param valor valor a ser convertido
 * @param tipo tipo a que se pretende converter o valor
 */
void converte_Puxa(STACK *s, double valor, TYPE tipo){
	DATA elemento;
	elemento.type = tipo;
	if(tipo == LONG){
		elemento.LONG = valor;
	}
	else if(tipo == DOUBLE){
		elemento.DOUBLE = valor;
	}
	else if(tipo == CHAR){
		elemento.CHAR = valor;
	}
	push(s, elemento);
}

/** @brief Função que converte um double para o seu tipo respetivo
 * @param valor valor a ser convertido
 * @param tipo tipo a que se pretende converter o valor
 * @return valor convertido com tipo DATA
 */
DATA converte(double valor, TYPE tipo){
	DATA elemento;
	elemento.type = tipo;
	if(tipo == LONG){
		elemento.LONG = valor;
	}
	else if(tipo == DOUBLE){
		elemento.DOUBLE = valor;
	}
	else if(tipo == CHAR){
		elemento.CHAR = valor;
	}
    return elemento;
}


DATA top(STACK *s){
	return s->stack[s->numeroelems -1];
}


DATA penultimo(STACK *s){
	return s->stack[s->numeroelems -2];
}



#define STACK_OPERATION(_type, _name)			\
	void push_##_name(STACK *s, _type val){ 	\
		DATA elem;								\
		elem.type = _name;						\
		elem._name = val;						\
		push(s, elem);							\
	}											\
	_type pop_##_name(STACK *s){				\
		DATA elem = pop(s); 					\
		assert(elem.type == _name);				\
		return elem._name;						\
	}

/**
* \brief Protótipos para a macro.
*/
STACK_OPERATION(long, LONG)
STACK_OPERATION(double, DOUBLE)
STACK_OPERATION(char, CHAR)
STACK_OPERATION(char *, STRING)
STACK_OPERATION(struct stack *, ARRAYS)
STACK_OPERATION(char *, BLOCKS)