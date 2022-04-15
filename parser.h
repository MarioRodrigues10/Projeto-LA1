/**
* \brief A função parse recebe uma stack e uma linha (vindas da main), percorre essa linha separa em tokens e compara se existe um caracter específico para que possa ser executada uma operação.
* \brief Saindo do ciclo for, a função print_stack imprime a stack.
* @param s Passagem da stack como parâmetro
* @param line Linha a ser lida.
*/
void parser(STACK *s,char *linha);



/**
 * \brief A função splitStrings recebe uma string e um delimitador, e devolve um array de strings.
 * @param str string a ser dividida
 * @param delim delimitador da string
 * @return devolve um array de strings
 */
char* splitStrings(char *str, const char *delim);



