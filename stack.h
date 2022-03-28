
// Struct que enumera os tipos e que vai aplica-los na struct data

typedef enum {
	LONG = 1,	// Tipo Long com o valor 1 (2⁰) associado 
	DOUBLE = 2, // Tipo Double com o valor 2 (2¹) associado 
	CHAR = 4, 	// Tipo Char com o valor 4 (2²) associado 
	STRING = 8,	// Tipo String com o valor 8 (2³) associado 
	arrays = 16 // Tipo arrays com o valor 16 (2⁴) associado 
} TYPE;


// Uma struct que nos dá os tipos de dados que estamos a usar na stack

typedef struct data {
	TYPE type;		// tipos de dados vindos do enum TYPE 
	long LONG;		// Tipo long 
	double DOUBLE;	// Tipo double 
	char CHAR;		// Tipo char 
	char *STRING;	// Tipo string 
	struct stack *arrays;	// Tipo arrays que é uma stack */
} DATA;

typedef struct stack{
	DATA *stack;	// Tipo da stack 
	int size;		// Tamanho da stack 
	int n_elems;	// Numero de elementos ao momento na stack 
} STACK;