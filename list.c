#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* create(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

int length(Node* head) {
    int i = 0;

    if (head != NULL) {
        i++;

        Node* p = head;

        while (p->next != NULL) {
            i++;
            p = p->next;
        }
    }

    return i;
}

void add(Node** head, int data) {
    // Adds an information (data) to the end of the list.
    Node* node = create(data);

    if (*head == NULL) {
        *head = node;
    } else {
        Node* p = *head;

        while (p->next != NULL) {
            p = p->next;
        }

        p->next = node;
    }
}

void insert(Node** head, int data, int index) {
    // Inserts an element at the specified index of the list.
    Node* node = create(data);
    int i = 0;
    if (i == index) {
        if ((*head)->next != NULL) {
            Node* temp = *head;
            *head = node;
            (*head)->next = temp;
        } else {
            *head = node;
        }
    } else {
        Node* p = *head;

        while (p->next != NULL && i+1 != index) {
            i++;
            p = p->next;
        }

        if (p->next != NULL && i+1 == index) {
            Node* temp = p->next;
            p->next = node;
            p->next->next = temp;
        }
    }
}

// avoid conflicting types with reverse
void rev(Node** head) {
    Node* prev = NULL;
    Node* curr = *head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *head = prev;
}

int index_of(Node* head, int data) {
    // Returns the index of the first occurrence of data within the entire list.
    int i = 0;

    if (head->data == data) {
        return i;
    }

    Node* p = head;

    while (p->next != NULL) {
        p = p->next;
        i++;
        if (p->data == data) {
            return i;
        }
    }

    return -1;
}

bool contains(Node* head, int data) {
    // Determines whether an element exists in the list.
    if (head->data == data) {
        return true;
    }

    Node* p = head;

    while (p->next != NULL) {
        p = p->next;
        if (p->data == data) {
            return true;
        }
    }

    return false;
}

void clear(Node** head) {
    // Removed all elements from the list.
    Node* p = *head;

    while (p->next != NULL) {
        Node* temp = p;
        p = p->next;
        free(temp);
    }

    *head = NULL;
}

// to avoid conflicting types with remove...
int remove_by(Node** head, int data) {
    // Removes the first occurrence of a specific element from the list.
    int i = 0;
    if ((*head)->data == data) {
        if ((*head)->next != NULL) {
            Node* temp = *head;
            *head = (*head)->next;
            free(temp);
        } else {
            free(*head);
            *head = NULL;
        }
        return i;
    } else {
        Node* p = *head;

        while (p->next != NULL && p->next->data != data) {
            i++;
            p = p->next;
        }

        if (p->next != NULL && p->next->data == data) {
            Node* temp = p->next;
            if (p->next->next != NULL) {
                p->next = p->next->next;
            } else {
                p->next = NULL;
            }

            free(temp);

            return i+1;
        }
    }

    return -1;
}

bool remove_at(Node** head, int index) {
    // Removes the element at the specified index of the list.
    int i = 0;
    if (i == index) {
        if ((*head)->next != NULL) {
            Node* temp = *head;
            *head = (*head)->next;
            free(temp);
        } else {
            free(*head);
            *head = NULL;
        }

        return true;
    } else {
        Node* p = *head;

        while (p->next != NULL && i+1 != index) {
            i++;
            p = p->next;
        }

        if (p->next != NULL && i+1 == index) {
            Node* temp = p->next;
            if (p->next->next != NULL) {
                p->next = p->next->next;
            } else {
                p->next = NULL;
            }

            free(temp);

            return true;
        }
    }

    return false;
}

void to_string(Node* head) {
    // A representation of the list and its data
    Node* p = head;
    printf("(%d)", p->data);

    while (p->next != NULL) {
        p = p->next;
        printf(" -> (%d)", p->data);
    }
}

int main() {
    Node* head = NULL;

    add(&head, 5);
    add(&head, 3);
    add(&head, 12);
    add(&head, 9);
    insert(head, 4, 0);

    to_string(head);

    return 0;
}
