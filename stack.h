
/**
* Struct que define a estrutura da stack, tendo ela uma inicialização com os valores padrões.
*/
typedef struct stack{
	int *stack;	     /**< Stack de Inteiros */
	int tamanho;	 /**< Tamanho da Stack */
	int numeroelems;	/**< Numero de elementos ao momento na stack */
} STACK;

STACK *new_stack();
void push(STACK *s, int elem);
int pop(STACK *s);
void printStack(STACK *s);