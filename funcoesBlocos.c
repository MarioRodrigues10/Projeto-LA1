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
#include "funcoesBlocos.h"
#define MAX(a,b) (((a)>(b)) ? (a):(b))

void dec_blocos(STACK *s){
    if(has_type(top(s),ARRAYS)){
        struct stack* array = pop_ARRAYS(s);
        int tam = array->numeroelems;
        long x[100];
        for(int i = 0; i < tam; i++){
            x[i] = pop_LONG(array) + 1;
        }
        for(int i = tam-1; i >= 0; i--){
            push(array, (DATA){.type=LONG,.LONG=x[i]});
        }
    }
    else if(has_type(top(s),STRING)){
        char* stg = pop_STRING(s);
        int x = strlen(stg);
        for(int i = 0; i < x; i++){
            stg[i] -= 1;
        }
        push_STRING(s, stg);
    }
}

void inc_blocos(STACK *s){
    if(has_type(top(s),ARRAYS)){
        struct stack* array = pop_ARRAYS(s);
        int tam = array->numeroelems;
        long x[100];
        for(int i = 0; i < tam; i++){
            x[i] = pop_LONG(array) + 1;
        }
        for(int i = tam-1; i >= 0; i--){
            push_LONG(array, x[i]);
        }
        push_ARRAYS(s,array);
    }
}

void multiply_blocos(STACK *s){
    if(has_type(top(s), LONG) && has_type(penultimo(s), STRING)){
        long x = pop_LONG(s);
        char *s1 = pop_STRING(s);
        int i;
        int j;
        int k = 0;
        char *resultado = malloc((((sizeof(s1))*x)+1)*(sizeof(char)));
		int tamanho2 = strlen(s1);
        for(i=0; i< tamanho2; i++){
			
            resultado[i] = s1[i];
        }
        for(j=i; j < tamanho2 * x; j++) {
             resultado[j] = resultado[k];
             k++;
        }
        resultado[(sizeof(s1)*x)] = '\0';
        push_STRING(s, resultado);

    } else if(has_type(top(s), LONG) && has_type(penultimo(s), ARRAYS)){
        long n = pop_LONG(s);
        struct stack* array = pop_ARRAYS(s);

        long i;
        long k = 0;
        long tam = array->numeroelems;


        for(i=0; i<((n-1)*tam); i++){
            if(array->tamanho == array->numeroelems){
                array->tamanho += 100;
                array->stack = (DATA *) realloc(array->stack, array->tamanho * sizeof(DATA));
            }
            array->stack[array->numeroelems] = array->stack[k];
            k++;
            array->numeroelems++;

        }
        push_ARRAYS(s, array);
    }
	else{
		DATA x = pop(s);
		DATA y = pop(s);
		double tx = toDouble(x);
		double ty = toDouble(y);
		converte_Puxa(s, ty*tx, MAX(x.type,y.type));			
	}
}

void expoente_blocos(STACK *s){
    if(has_type(top(s), LONG) && has_type(penultimo(s), ARRAYS)){
		long n = pop_LONG(s);
		struct stack* array = pop_ARRAYS(s);
		int i = array->numeroelems;
		DATA x[1000];
		int j;
		for(j=0; j < i; j++){
			x[j] = pop(array);
		}
		while(j > 0){
			long valor = x[j-1].LONG;
			long total = valor;
			for(int t=0; t < (n-1); t++){
				total *= valor;
			}
			push(array, (DATA){.LONG = total, .type = LONG});
			j--;
		}
		push_ARRAYS(s, array);
	}
}


void range_AB(STACK *s){
     if(has_type(top(s), LONG)){
        long x = pop_LONG(s);
        long i = 0;
        struct stack* array = stack_new();
        
        while(i<x){
        	push_LONG(array, i);	    
        	i++;
        }
        push_ARRAYS(s, array);

    } else if(has_type(top(s), ARRAYS)){
        struct stack* array = pop_ARRAYS(s);
        DATA x[1000];
        int i = array->numeroelems;
        int j;
        for(j=0; j < i; j++){
            x[j] = pop(array);
        }
        j--;
        while(j >= 0){
            if (x[j].type == STRING) 
            {
                if (strlen(x[j].STRING) == 16) printf("%s\n", x[j].STRING);
                push_LONG(array, strlen(x[j].STRING));
            }
            else
            {
                push(array, (DATA){.LONG = 1, .type = LONG});
            } 
            j--;
        } 
        push_ARRAYS(s, array);
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

void trocar_Blocos(STACK *s){
    struct stack* array = pop_ARRAYS(s);
    DATA x[1000];
    int i = array->numeroelems;
    int j;
    for(j=0; j < i; j++){
        x[j] = pop(array);
    }
    j--;
    while(j >= 0){
        push(array, x[j-1]);
        push(array, x[j]);
        j-=2;
    }
    
    printf("aa\n");
    printStack(array);
    printf("\n");
    push_ARRAYS(s, array);
}

void igual_Blocos(STACK *s){
    struct stack *array = pop_ARRAYS(s);
    DATA x[1000];
    int i = array->numeroelems;
    int j;
    for(j=0; j < i; j++){
        x[j] = pop(array);
    }
    j--;
    while(j >= 0){
        printf("entrei4\n");
        printf("%s\n", x[j].STRING);
        printf("%d\n", x[j-1].LONG);
        if(has_type(x[j], STRING) && has_type(x[j-1], STRING)){
            char* t = x[j].STRING;
            char* y = x[j-1].STRING;
            (strcmp(t,y) == 0) ? push_LONG(s,1) : push_LONG(s,0);
        }
        else if(has_type(x[j], LONG) && has_type(x[j-1], STRING)){
            long t = x[j].LONG;
            char* y = x[j-1].STRING;
            push_CHAR(s, y[t]);
        }
          else if(has_type(x[j], STRING) && has_type(x[j-1], LONG)){
            long t = x[j-1].LONG;
            char* y = x[j].STRING;
            push_CHAR(s, y[t]);
        }
        else{
            DATA t = x[j];
            DATA y = x[j-1];
            double tx = toDouble(t);
            double ty = toDouble(y);
            (tx == ty) ? converte_Puxa(s, 1, LONG) : converte_Puxa(s, 0, LONG);
        }
        j -= 2;
    }
    printStack(s);
    printf("\n");
}