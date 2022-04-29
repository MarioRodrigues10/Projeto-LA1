
/**
* Struct que define a estrutura da stack, tendo ela uma inicialização com os valores padrões.
*/
typedef enum {
	LONG = 1,	/**< Tipo Long com o valor 1 (2⁰) associado */
	DOUBLE = 2, /**< Tipo Double com o valor 2 (2¹) associado */
	CHAR = 4, 	/**< Tipo Char com o valor 4 (2²) associado */
	STRING = 8	/**< Tipo String com o valor 8 (2³) associado */
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