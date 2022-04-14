#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "stack.h"
#include "parser.h"

//parte a string em tokens
char* splitStrings(char *str, const char *delim){
    static char *src = NULL;
    char *p, *ret;

    if(str != NULL){
        src = str;
    }
    if(src == NULL){
        return NULL;
    }
    if((p = strpbrk(src, delim)) != NULL){
        *p = '\0';
        ret = src;
        src = ++p;
    }else{
        ret = src;
        src = NULL;
    }
    return ret;
}



//convert uma string num inteiro
long int stringToLongInt(char *str, char **endptr, int base){
    char *p;
    long ret;

    ret = strtol(str, &p, base);
    if(endptr != NULL){
        *endptr = p;
    }
    return ret;
}

//define strcom
int stringCompara(char *str1, char *str2){
    int i;
    for(i = 0; str1[i] != '\0' && str2[i] != '\0'; i++){
        if(str1[i] != str2[i]){
            return 0;
        }
    }
    return 1;
}


void parser(STACK *s, char *linha){
    char *limite = " \t\n";
    char* token = splitStrings(linha,limite);
    while(token != NULL){
        char *resto;
        long int num = stringToLongInt(token, &resto, 10);
        if(strlen(resto) == 0) {
            push(s,num);
        }
        else if(strcmp(token, "+") == 0){
            long int num1 = pop(s);
            long int num2 = pop(s);
            long int result = num1 + num2;
            push(s, result);
        }
        else if(strcmp(token, "-") == 0){
            long int num1 = pop(s);
            long int num2 = pop(s);
            push(s, num2 - num1);
        }
        else if(strcmp(token, "*") == 0){
            long int num1 = pop(s);
            long int num2 = pop(s);
            push(s, num2 * num1);
        }
        else if(strcmp(token, "/") == 0){
            long int num1 = pop(s);
            long int num2 = pop(s);
            push(s, num2 / num1);
        }
        else if(strcmp(token, "#") == 0){
            long int num1 = pop(s);
            long int num2 = pop(s);
            push(s, pow(num2,num1));
        }
        else if(strcmp(token, "(") == 0){
            long int num1 = pop(s);
            push(s,num1--);
        }
        else if(strcmp(token, ")") == 0){
            long int num1 = pop(s);
            push(s,num1++);
        }
        else if(strcmp(token, "%") == 0){
            long int num1 = pop(s);
            push(s, abs(num1));
        }
        else if(strcmp(token, "&") == 0){
            long int num1 = pop(s);
            long int num2 = pop(s);
            push(s, num2 & num1);
        }
        else if(strcmp(token, "|") == 0){
            long int num1 = pop(s);
            long int num2 = pop(s);
            push(s, num2 | num1);
        }
        else if(strcmp(token, "^") == 0){
            long int num1 = pop(s);
            long int num2 = pop(s);
            push(s,num2 ^ num1);
        }
        else if(strcmp(token, "~") == 0){
            long int num1 = pop(s);
            push(s,~ num1);
        }
        else{
            printf("ERROR\n");
        }
        token = splitStrings(NULL,limite);
    }
    printStack(s);
}