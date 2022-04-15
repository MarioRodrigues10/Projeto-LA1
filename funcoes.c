#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "parser.h"

/**
 * @brief adiciona dois elementos e coloca a soma na stack
 * @param s stack
 */
void adicionar(STACK *s){
    int num1 = pop(s);
    int num2 = pop(s);
    push(s, num1+num2);
} 
/**
 * @brief subtrai dois elementos e coloca a subtração na stack
 * @param s stack
 */
void sub(STACK *s){
    int num1 = pop(s);
    int num2 = pop(s);
    push(s, num2-num1);
}
/**
 * @brief eleva o 2 elemento da stack ao primeiro e coloca o resultado na stack
 * @param s 
 */
void expoente(STACK *s){
    int num1 = pop(s);
    int num2 = pop(s);
    push(s, pow(num2,num1));
}
/**
 * @brief multiplica dois elementos e coloca a multiplicação na stack
 * @param s stack
 */
void multiply(STACK *s){
    int num1 = pop(s);
    int num2 = pop(s);
    push(s, num2*num1);
    
}
/**
 * @brief divide dois elementos e coloca a divisão na stack
 * @param s stack
 */
void divisao(STACK *s){
    int num1 = pop(s);
    int num2 = pop(s);
    push(s, num2/num1);
}
/**
 * @brief retira 1 ao elemento no topo da stack e volta a colocar-lo no topo da stack
 * @param s stack
 */
void dec(STACK *s){
    int num1 = pop(s)-1;
    push(s, num1);
}
/**
 * @brief adiciona 1 ao elemento no topo da stack e volta a colocar-lo no topo da stack
 * @param s stack
 */
void inc(STACK *s){
    int num1 = pop(s)+1;
    push(s, num1);
}
/**
 * @brief coloca o elemento no topo da stack em módulo e volta a colocar-lo no topo do stack
 * @param s stack
 */
void modulo(STACK *s){
    int num1 = pop(s);
    int num2 = pop(s);
    push(s, num2 % num1);
}
/**
 * @brief faz a operação and entre dois elementos e coloca o resultado na stack
 * @param s stack
 */
void and(STACK *s){
    int num1 = pop(s);
    int num2 = pop(s);
    push(s, num2 & num1);
}
/**
 * @brief faz a operação or entre dois elementos e coloca o resultado na stack
 * @param s stack
 */
void or(STACK *s){
    int num1 = pop(s);
    int num2 = pop(s);
    push(s, num2 | num1);
}
/**
 * @brief faz a operação xor entre dois elementos e coloca o resultado na stack
 * @param s stack
 */
void xor(STACK *s){
    int num1 = pop(s);
    int num2 = pop(s);
    push(s, num2 ^ num1);
}
/**
 * @brief faz a operação not entre dois elementos e coloca o resultado na stack
 * @param s stack
 */
void not(STACK *s){
    int num1 = pop(s);
    push(s, ~ num1);
}
