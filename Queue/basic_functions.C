#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *tail;
} Queue;

Queue* create_queue() {
    Queue *q = (Queue*) malloc(sizeof(Queue));
    if (q != NULL) {
        q->front = NULL;
        q->tail = NULL;
    }
    return q;
}

int is_empty(Queue *q) {
    return (q->front == NULL);
}

void enqueue(Queue *q, int value) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory allocation error!\n");
        return;
    }
    new_node->value = value;
    new_node->next = NULL;

    if (is_empty(q)) {
        q->front = new_node;
        q->tail = new_node;
    } else {
        q->tail->next = new_node;
        q->tail = new_node;
    }
}

int dequeue(Queue *q) {
    if (is_empty(q)) {
        printf("Error: Queue underflow!\n");
        return -1;
    }

    Node *temp = q->front;
    int dequeued_value = temp->value;

    q->front = q->front->next;

    if (q->front == NULL) {
        q->tail = NULL;
    }

    free(temp);
    return dequeued_value;
}

int main() {

    return 0;
}