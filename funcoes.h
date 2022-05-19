/**
 * @brief Soma os 2 valores que estão no topo da stack
 * @param s stack
 */
void adicionar(STACK *s);

/**
 * @brief Subtrai os 2 valores que estão no topo da stack
 * @param s stack
 */
void sub(STACK *s);

/**
 * @brief Multiplica os 2 valores que estão no topo da stack
 * @param s stack
 */
void multiply(STACK *s);

/**
 * @brief Coloca o 2º valor do topo da stack elevado ao 1º valor do topo da stack
 * @param s stack
 */
void expoente(STACK *s);

/**
 * @brief Divide os 2 valores que estão no topo da stack
 * @param s stack
 */
void divisao(STACK *s);

/**
 * @brief Decrementa o valor que está no topo da stack
 * @param s stack
 */
void dec(STACK *s);

/**
 * @brief Incrementa o valor que está no topo da stack
 * @param s stack
 */
void inc(STACK *s);

/**
 * @brief Calcula o resto entre os 2 valores que estão no topo da stack
 * @param s stack
 */
void modulo(STACK *s);


/**
 * @brief Calcula o valor lógico do AND entre os 2 valores que estão no topo da stack
 * @param s stack
 */
void and(STACK *s);

/**
 * @brief Calcula o valor lógico do OR entre os 2 valores que estão no topo da stack
 * @param s stack
 */
void or(STACK *s);

/**
 * @brief Calcula o valor lógico do XOR entre os 2 valores que estão no topo da stack
 * @param s stack
 */
void xor(STACK *s);

/**
 * @brief Calcula o valor lógico de NOT do elemento no topo da stack
 * @param s stack
 */
void not(STACK *s);

/**
 * @brief transforma qualquer elemento da stack em double
 * @param elemento elemento a ser convertido
 * @return devolve uma nova stack
 */
double toDouble(DATA elemento);

