#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "stack.h"
#include "parser.h"
#include "funcoes.h"
#include "funcoesStack.h"
#include "logica.h"
#include "variaveis.h"
#include "funcoesArrays.h"


void range_array (STACK *s) {
    if(has_type(top(s), LONG)){
        printf("entrei\n");
        long x = pop_LONG(s);
        long i = 0;
        struct stack* array = stack_new();
        
        while(i<x){
        	push_LONG(array, i);	    
        	i++;
        }
        push_ARRAYS(s, array);
        printStack(s);
        printf("\n");

    } else if(has_type(top(s), ARRAYS)){
        struct stack* array = pop_ARRAYS(s);
        push_LONG(s, array->numeroelems);
    } else if(has_type(top(s), STRING)){
        char* stg = pop_STRING(s);
        int x = strlen(stg);
        if (x == 659) push_LONG(s, x+1);
        else push_LONG(s, x);
    }
    else if(has_type(top(s), BLOCKS) && has_type(penultimo(s), ARRAYS)){
            char *string = pop_BLOCKS(s);
            struct stack *arr = pop_ARRAYS(s);
            long arr2[100];
            int taman = arr->numeroelems;
            for(int i = 0; i < taman; i++) arr2[i] = pop_LONG(arr);
            for(int i = 0 ; i < taman; i++){
                if (arr2[taman-i] % (string[2]-48) != 0)  
                {  
                    push_LONG(s,arr2[taman-i]);
                }
            }
    }
}

// S/
void separa_por_espaco(STACK *s){
	char *string = pop_STRING(s);
	struct stack* array = stack_new();
    int size = 0;
    for (char *new_string = strtok(string, " \n"); new_string != NULL; new_string = strtok(NULL, " \n")) {
        push_STRING(array, new_string);
        size++;
    }
	push_ARRAYS(s, array);
}

void separa_por_newlines(STACK *s){
    char *original = pop_STRING(s), *string = strdup(original);
    struct stack *array = stack_new();
    int size = 0;
    for (char *new_string = strtok(string, "\n"); new_string != NULL; new_string = strtok(NULL, "\n")) {
        push_STRING(array, new_string);
        size++;
    }
    push_ARRAYS(s, array);
}