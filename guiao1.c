#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>


#include "stack.h"
#include "parser.h"

int main(){
    char line[10000];
    assert(fgets(line,10000,stdin) != NULL);
    STACK *s = new_stack();
    parser(s, line);
    return 0;
}