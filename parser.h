/**
* \brief A função parse recebe uma stack e uma linha (vindas da main), percorre essa linha separa em tokens e compara se existe um caracter específico para que possa ser executada uma operação.
* \brief Saindo do ciclo for, a função print_stack imprime a stack.
* @param s Passagem da stack como parâmetro
* @param line Linha a ser lida.
*/
void parse_line(STACK *s, char* line);

char *parse_line3(STACK *a, STACK *new, char *line);

char fstWord(char *line);

char *scanForStrings(STACK *s, char *line);

void divide_string_by_token(char *line, char token, char *before_token, char *after_token);

char *trata_blocos(STACK *s, char *line);

void parse_lineB(STACK *s, char *line);

void handle_B(STACK *s, char *token);