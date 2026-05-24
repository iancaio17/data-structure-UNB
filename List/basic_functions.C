#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} Node;

typedef struct {
    Node *head;
} List;

List *create_list(void){
    List *l = (List*) malloc(sizeof(List));
    if(l != NULL) {
        l->head = NULL;
    }
    return l;    
}

void push_front(List *l, int value){
    Node *new_node = (Node*) malloc(sizeof(Node));
    if(new_node != NULL){
        new_node->value = value;
        new_node->next = l->head;
        l->head = new_node;
    } else {
        printf("Erro ao alocar memoria\n");
    }
}

void push_back(List *l, int value){
    Node *new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL) {
        printf("Erro ao alocar memoria\n");
        return;
    }
    new_node->next = NULL;
    new_node->value = value;
    
     if(l->head == NULL){
        l->head = new_node;
    } 
    else {
        Node *current = l->head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = new_node;
    }
}

void print_list(List *l){
    Node *current = l->head;
    if(current == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    while (current != NULL){
        printf("%d\n", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

int size(List *l){
    Node *current = l->head;
    int count = 0;
    while (current != NULL){
        count++;
        current = current->next;
    }
    return count;
}

int main(){
    
    return 0;
}