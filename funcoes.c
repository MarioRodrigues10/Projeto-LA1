#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "parser.h"

/**
 * @brief adiciona dois elementos e coloca a soma na stack
 * @param s stack
 * @return 1 se a operação foi bem sucedida
 */
int adicionar(STACK *s){
    int num1 = pop(s);
    int num2 = pop(s);
    push(s, num1+num2);
    return 1;
} 
/**
 * @brief subtrai dois elementos e coloca a subtração na stack
 * @param s stack
 * @return 1 se a operação foi bem sucedida
 */
int sub(STACK *s){
    int num1 = pop(s);
    int num2 = pop(s);
    push(s, num2-num1);
    return 1;
}
/**
 * @brief eleva o 2 elemento da stack ao primeiro e coloca o resultado na stack
 * @param s 
 * @return 1 se a operação foi bem sucedida
 */
int expoente(STACK *s){
    int num1 = pop(s);
    int num2 = pop(s);
    push(s, pow(num2,num1));
    return 1;
}
/**
 * @brief multiplica dois elementos e coloca a multiplicação na stack
 * @param s stack
 * @return 1 se a operação foi bem sucedida
 */
int multiply(STACK *s){
    int num1 = pop(s);
    int num2 = pop(s);
    push(s, num2*num1);
    return 1;
}
/**
 * @brief divide dois elementos e coloca a divisão na stack
 * @param s stack
 * @return 1 se a operação foi bem sucedida
 */
int divisao(STACK *s){
    int num1 = pop(s);
    int num2 = pop(s);
    push(s, num2/num1);
    return 1;
}
/**
 * @brief retira 1 ao elemento no topo da stack e volta a colocar-lo no topo da stack
 * @param s stack
 * @return 1 se a operação foi bem sucedida
 */
int dec(STACK *s){
    int num1 = pop(s)-1;
    push(s, num1);
    return 1;
}
/**
 * @brief adiciona 1 ao elemento no topo da stack e volta a colocar-lo no topo da stack
 * @param s stack
 * @return 1 se a operação foi bem sucedida
 */
int inc(STACK *s){
    int num1 = pop(s)+1;
    push(s, num1);
    return 1;
}
/**
 * @brief coloca o elemento no topo da stack em módulo e volta a colocar-lo no topo do stack
 * @param s stack
 * @return 1 se a operação foi bem sucedida
 */
int modulo(STACK *s){
    int num1 = pop(s);
    int num2 = pop(s);
    push(s, num2 % num1);
    return 1;
}
/**
 * @brief faz a operação and entre dois elementos e coloca o resultado na stack
 * @param s stack
 * @return 1 se a operação foi bem sucedida
 */
int and(STACK *s){
    int num1 = pop(s);
    int num2 = pop(s);
    push(s, num2 & num1);
    return 1;
}
/**
 * @brief faz a operação or entre dois elementos e coloca o resultado na stack
 * @param s stack
 * @return 1 se a operação foi bem sucedida
 */
int or(STACK *s){
    int num1 = pop(s);
    int num2 = pop(s);
    push(s, num2 | num1);
    return 1;
}
/**
 * @brief faz a operação xor entre dois elementos e coloca o resultado na stack
 * @param s stack
 * @return 1 se a operação foi bem sucedida
 */
int xor(STACK *s){
    int num1 = pop(s);
    int num2 = pop(s);
    push(s, num2 ^ num1);
    return 1;
}
/**
 * @brief faz a operação not entre dois elementos e coloca o resultado na stack
 * @param s stack
 * @return 1 se a operação foi bem sucedida
 */
int not(STACK *s){
    int num1 = pop(s);
    push(s, ~ num1);
    return 1;
}
