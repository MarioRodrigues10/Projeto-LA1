/** 
 * @brief faz uma operação if then else entre 2 elementos
 * @param s stack
 */
void ifThenElse(STACK *s);

/** 
 * @brief faz uma operação igual then else entre 2 elementos caso forem iguais coloca 1 na stack, caso não sejam coloca 0
 * @param s stack
 */
void igual(STACK *s);

/** 
 * @brief faz uma operação menor entre 2 elementos caso forem diferentes coloca 1 na stack, caso não sejam coloca 0
 * @param s stack
 */
void menor(STACK *s);

/** 
 * @brief faz uma operação maior entre 2 elementos caso o 1º seja menor coloca 1 na stack, caso não sejam coloca 0
 * @param s stack
 */
void maior(STACK *s);

/** 
 * @brief faz uma operação menor entre 2 elementos coloca o menor na stack
 * @param s stack
 */
void emenor(STACK *s);

/** 
 * @brief faz uma operação maior entre 2 elementos coloca o maior na stack
 * @param s stack
 */
void emaior(STACK *s);


/** 
 * @brief faz uma operação not em 1 elemento caso seja igual a 0 coloca 1 na stack, caso não seja coloca 0
 * @param s stack
 */
void nao(STACK *s);

/** 
 * @brief faz uma operação e entre 2 elementos caso forem diferentes de zero ambos coloca 1 na stack, caso não sejam coloca 0
 * @param s stack
 */
void e(STACK *s);


/** 
 * @brief faz uma operação ou entre 2 elementos caso o 2º seja diferentes de zero é recolocado na stack, caso 2º elemento seja igual a 0 , verificamos o 1º elemento caso seja diferente de 0 é recolocado na stack, caso ambos sejam iguais a 0 é colocado 0 na stack
 */
void ou(STACK *s);