#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>


#include "stack.h"
#include "parser.h"
#include "variaveis.h"
/**
 * @brief cria uma nova stack, e devolve a stack criada para a função parser. No fim da execução imprime o conteúdo da stack
 * @return 0 se não houver erros
*/
int main(){
    STACK *s = stack_new();
    iniciarArray(s);
    char line[10000];
    if(fgets(line, 10000, stdin) != (char *) NULL){
        parse_line(s, line);
    }
    printStack(s);
    printf("\n");
    return 0;
}