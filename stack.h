
/**
* Struct que define a estrutura da stack, tendo ela uma inicialização com os valores padrões.
*/
typedef enum {
	LONG = 1,	/**< Tipo Long com o valor 1 (2⁰) associado */
	DOUBLE = 2, /**< Tipo Double com o valor 2 (2¹) associado */
	CHAR = 4, 	/**< Tipo Char com o valor 4 (2²) associado */
	STRING = 8,	/**< Tipo String com o valor 8 (2³) associado */
	ARRAYS = 16,/**< Tipo Array com o valor 16 (2⁴) associado */
	BLOCKS = 32	/**< Tipo Bloco com o valor 32 (2⁵) associado */
} TYPE;

/**
* Uma struct que nos dá os tipos de dados que estamos a usar na stack
*/
typedef struct data {
	TYPE type;		/**< tipos de dados vindos do enum TYPE */

	long LONG;		/**< Tipo long */
	double DOUBLE;	/**< Tipo double */
	char CHAR;		/**< Tipo char */
	char *STRING;	/**< Tipo string */
	struct stack *ARRAYS;	/**< Tipo array */
	char *BLOCKS;	/**< Tipo bloco */
} DATA;

/**
* Uma struct que nos dá os tipos de dados que estamos a usar na stack
*/
typedef struct stack{
	DATA letras[26];	/**< Array de letras */
	DATA *stack;	     /**< Stack de Tipo */
	int tamanho;	 /**< Tamanho da Stack */
	int numeroelems;	/**< Numero de elementos ao momento na stack */
} STACK;

/**
 * @brief cria uma nova stack
 * @return devolve uma nova stack
*/
STACK *stack_new();

/**
 * @brief verifica se o tipo de um elemento é igual ao tipo passado por parâmetro
 * @return 1 se os tipos forem iguais, 0 caso contrário
 */
int has_type(DATA elem, int mask);

/**
 * \brief A função push recebe uma stack e um valor com um tipo DATA, e adiciona esse valor à stack.
 * @param s stack
 * @param valor inteiro a ser adicionado
 */
void push(STACK *s, DATA elem);


/**
 * \brief A função pop recebe uma stack e devolve o último inteiro adicionado na stack.
 * @param s stack
 * @return inteiro
 */
DATA pop(STACK *s);


/**
 * \brief A função printStack recebe uma stack e imprime os elementos da stack.
 * @param s stack
 */
void printStack(STACK *s);

/**
 * @brief Função que converte um double para o seu tipo respetivo e adiciona-o à stack
 * @param s stack
 * @param valor valor a ser convertido
 * @param tipo tipo a que se pretende converter o valor
 */
void converte_Puxa(STACK *s, double valor, TYPE tipo);

/** @brief Função que converte um double para o seu tipo respetivo
 * @param valor valor a ser convertido
 * @param tipo tipo a que se pretende converter o valor
 * @return valor convertido com tipo DATA
 */
DATA converte(double valor, TYPE tipo);
DATA top(STACK *s);
DATA penultimo(STACK *s);

#define STACK_OPERATION_PROTO(_type, _name)		\
	void push_##_name(STACK *s, _type val);		\
	_type pop_##_name(STACK *s);


STACK_OPERATION_PROTO(long, LONG)
STACK_OPERATION_PROTO(double, DOUBLE)
STACK_OPERATION_PROTO(char, CHAR)
STACK_OPERATION_PROTO(char *, STRING)
STACK_OPERATION_PROTO(struct stack *, ARRAYS)
STACK_OPERATION_PROTO(char *, BLOCKS)

