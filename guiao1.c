#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>


#include "stack.h"
#include "parser.h"

/**
 * @brief lê uma linha, cria uma nova stack, e chama a função parser que calcula o resultado entre números inteiros
 * @return 0 se não houver erros
*/
int main(){
    char line[10000];
    assert(fgets(line,10000,stdin) != NULL);
    STACK *s = new_stack();
    parser(s, line);
    return 0;
}