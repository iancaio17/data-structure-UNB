/*Invertendo números com pilha
Utilizando uma pilha, leia uma sequência de números inteiros e imprima os valores na ordem inversa.
Exemplo:
    Entrada:
    1 2 3 4 5
    Saída:
    5 4 3 2 1
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct{
    int itens[MAX_SIZE];
    int top;
} Stack;

Stack* create_Stack(){
    Stack *s = (Stack*) malloc(sizeof(Stack));
    if (s != NULL) s->top = -1;
    return s;
}

int is_empty(Stack *s){
    return(s->top == -1);
}

void push(Stack *s, int value){
    if(s->top == (MAX_SIZE - 1)){
        printf("Error: Stack Overflow\n");
        return;
    }
    s->top++;
    s->itens[s->top] = value;
}

int pop(Stack *s){
    if(is_empty(s)){
        printf("Error: Stack Underflow\n");
        return -1;
    }
    int value = s->itens[s->top];
    s->top--;
    return value;
}


int main(){
    Stack *s = create_Stack();
    int number;
    int amount = 5;
    printf("Type a stack of %d numbers: ", amount);
    
    for(int i = 0; i<amount; i++){
        scanf("%d", &number);
        push(s, number);
    }
    printf("Inverted stack:");
    
    while(!is_empty(s)){
        int popped = pop(s);
        printf("%d ", popped);
    }
    printf("\n");
    
    free(s);
    return 0;
}



















