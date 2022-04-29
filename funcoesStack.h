
/**
 * @brief transforma qualquer elemento da stack em int e coloca na stack
 * @param s stack
 */
void converteInt(STACK *s);

/**
 * @brief transforma qualquer elemento da stack em double e coloca na stack
 * @param s stack
 */
void converterDouble(STACK *s);

/**
 * @brief transforma qualquer elemento da stack em char e coloca na stack
 * @param s stack
 */
void converteCHAR(STACK *s);

/**
 * @brief lê uma nova linha e coloca o seu conteúdo na stack
 * @param s stack
 */
void lerLinha(STACK *s);


/**
 * @brief troca os 2 elementos do topo da stack
 * @param s stack
 */
void trocar(STACK *s);

/**
 * @brief duplica o elemento que está no topo da stack
 * @param s stack
 */
void duplicar(STACK *s);

/**
 * @brief roda os 3 elementos do topo da stack
 * @param s stack
 */
void rodar3(STACK *s);

/**
 * @brief copia um elemento numa 'n' posição da stack para o topo
 * @param s stack
 */
void copiarNTopo(STACK *s);

/**
 * @brief retira um elemento da stack
 * @param s stack
 */
void popp(STACK *s);