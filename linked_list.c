#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* create(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->next = NULL;
    node->data = data;
    return node;
}

void append(Node* head, int data) {
    Node* p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = create(data);
}

void prepend(Node** head, int data) {
    Node* p = create(data);
    p->next = *head;
    *head = p;
}

void destroy(Node* head) {
    Node* p = head;
    while (p->next != NULL) {
        Node* temp = p;
        p = p->next;
        free(temp);
    }
    head = NULL;
}

void visualize(Node* head) {
    printf("%d", head->data);
    Node* p = head;
    while (p->next != NULL) {
        p = p->next;
        printf(" -> %d", p->data);
    }
}

int main() {
    Node* head = create(2);

    append(head, 14);
    prepend(&head, 3);
    append(head, 8);
    append(head, 11);
    prepend(&head, 7);
    append(head, 4);

    visualize(head);

    destroy(head);

    return 0;
}
