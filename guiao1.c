#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int Add     (int a, int b) { return a + b; }
int Subtract(int a, int b) { return a - b; }
int Multiply(int a, int b) { return a * b; }
int Divide  (int a, int b) { return a / b; }
int Exponent(int a,int b){
    int total = a;
    for(int i=0; i < b-1; i++){
        total = total *a;
    }
    return total;
}
int Xor(int a, int b){
    int res = 0;
 
    for (int i = 31; i >= 0; i--)
    {
       
        bool b1 = a & (1 << i);
        bool b2 = b & (1 << i);
 
        bool xoredBit = (b1 & b2) ? 0 : (b1 | b2);
 
        res <<= 1;
        res |= xoredBit;
    }
    return res;
}
int Incrementar(int a){ return (a+1);}
int Decrementar(int a){ return (a-1);}
int Modulo(int a){ return abs(a);  }
int And(int a, int b){
    return a&b;
}
int Or(int a, int b){
    return a|b;
}
int Not(int a){
    return ~a;
}
int DoFunction(int Select, int a, int b)
{
    typedef int (*MyFunctionPointer)(int a, int b);

    //  Construção da dispatch table com pointers a apontar para functions.
    MyFunctionPointer Table[] =
        {
            Add,
            Subtract,
            Multiply,
            Divide,
            Exponent,
            Xor,
            And,
            Or
        };

    //  Dispatch para a função requesitada.
    return Table[Select](a, b);
}

int DoFunction2(int Select, int a)
{
    typedef int (*MyFunctionPointer)(int a);

    //  Construção da dispatch table com pointers a apontar para functions.
    MyFunctionPointer Table[] =
        {
            Incrementar,
            Decrementar,
            Modulo,
            Not
        };

    //  Dispatch para a função requesitada.
    return Table[Select](a);
}


int main(void)
{
    //  Demonstração.
    printf("7 + 3 = %d.\n", DoFunction(0, 7, 3));
    printf("7 - 3 = %d.\n", DoFunction(1, 7, 3));
    printf("7 * 3 = %d.\n", DoFunction(2, 7, 3));
    printf("7 / 3 = %d.\n", DoFunction(3, 7, 3));
    printf("7³ = %d.\n", DoFunction(4,7,3));
    printf("Incrementar 7 = %d\n",DoFunction2(0,7));
    printf("Decrementar 7 = %d\n",DoFunction2(1,7));
    printf("Modulo (-7) = %d\n",DoFunction2(2,-7));
    printf("XOR 2 5 = %d\n",DoFunction(5,2,5));
    printf("AND 2 5 = %d\n",DoFunction(6,2,5));
    printf("OR 2 5 = %d\n",DoFunction(7,2,5));
    printf("~A = %d\n",DoFunction2(3,2));

    // E , OU , NOT  -> To Do
    // 2 & 5 = 0
    // 12 | (7 & 2) = 14
    // posso usar outras bibliotecas? (abs), se não mult (-1) a < 0; 1 caso a > 0
}