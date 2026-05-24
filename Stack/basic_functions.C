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
    }
    int value = s->itens[s->top];
    s->top--;
    return value;
}


int main(){
    
    return 0;
}