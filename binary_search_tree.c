enum state {False, True};

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} bst_node;

typedef struct q_node {
    int data;
    struct q_node* next;
} q_node;

typedef struct queue {
    struct q_node* head;
    struct q_node* tail;
} queue;

queue* queue() {
    queue* q = (queue*) malloc(sizeof(queue));
    q->head = NULL;
    q->tail = NULL;
}

void enqueue(queue* q, int data) {
    q_node* node = (q_node*) malloc(sizeof(q_node));
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

    q_node* head = q->head;
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
    q_node* node = q->head;
    while (node->next != NULL) {
        ++size;
        node = node->next;
    }

    return size;
}

// This creates a node, its value is the passed in data parameter
bst_node* bst_create(int data) {
    bst_node* node = (bst_node*) malloc(sizeof(bst_node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void bst_insert(bst_node* node, int data) {
    if (data <= node->data) {
        if (node->left == NULL) {
            node->left = bst_create(data);
        } else {
            bst_insert(node->left, data);
        }
    } else {
        if (node->right == NULL) {
            node->right = bst_create(data);
        } else {
            bst_insert(node->right, data);
        }
    }
}

// Whether or not the binary tree contains that data
enum state bst_contains(bst_node* node, int data) {
    if (data == node->data) {
        return True;
    }

    if (data > node->data) {
        if (node->right == NULL) {
            return False;
        }
        bst_contains(node->right, data);
    } else {
        if (node->left == NULL) {
            return False;
        }
        bst_contains(node->left, data);
    }
};

// Tree traversal: Depth-first search (DFS) and Breadth-first search (BFS)

// These searches are referred to as depth-first search (DFS)
void bst_in_order(bst_node* node) {
    if (node->left != NULL) {
        bst_in_order(node->left);
    }
    printf("%d ", node->data);
    if (node->right != NULL) {
        bst_in_order(node->right);
    }
}

void bst_pre_order(bst_node* node) {
    printf("%d ", node->data);
    if (node->left != NULL) {
        bst_pre_order(node->left);
    }
    if (node->right != NULL) {
        bst_pre_order(node->right);
    }
}

void bst_post_order(bst_node* node) {
    if (node->left != NULL) {
        bst_post_order(node->left);
    }
    if (node->right != NULL) {
        bst_post_order(node->right);
    }
    printf("%d ", node->data);
}

void breadth_first_search(bst_node* node) {
    queue* q = queue();
    bst_node* p = node;
    bst_node* set[10];
    int i = 0;
    int j = 0;
    enqueue(q, p->data);
    while ( !  is_empty(q)) {
        printf("%d ", dequeue(q));
        if (p->left != NULL) {
            set[j++] = p->left;
            enqueue(q, p->left->data);
        }
        if (p->right != NULL) {
            set[j++] = p->right;
            enqueue(q, p->right->data);
        }
        if (set[i] != NULL) {
            p = set[i++];
        }
    }
}