enum state {False, True};

typedef struct node {
    int data;
    struct node* next;
} node;

typedef struct queue {
    struct node* head;
    struct node* tail;
} queue;

queue* queue() {
    queue* q = (queue*) malloc(sizeof(queue));
    q->head = NULL;
    q->tail = NULL;
}

void enqueue(queue* q, int data) {
    node* node = (node*) malloc(sizeof(node));
    node->data = data;
    node->next = NULL;
    if (q->head == NULL && q->tail == NULL) {
        q->head = node;
        q->tail = node;
    } else {
        if (q->head == q->tail) {
            q->tail = node;
            q->head->next = node;
        } else {
            q->tail->next = node;
            q->tail = node;
        }
    }
}

enum state is_empty(queue* q) {
    if (q->head == NULL) {
        return True;
    }
    return False;
};

int dequeue(queue* q) {
    if (is_empty(q)) {
        return NULL;
    }

    node* head = q->head;
    int data = head->data;

    if (q->head == q->tail) {
        q->tail = NULL;
    }

    q->head = q->head->next;
    free(head);

    return data;
}

int size(queue* q) {
    if (is_empty(q)) {
        return 0;
    }

    int size = 1;
    node* node = q->head;
    while (node->next != NULL) {
        ++size;
        node = node->next;
    }

    return size;
}