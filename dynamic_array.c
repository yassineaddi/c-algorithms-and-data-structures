enum state {False, True};

typedef struct array {
    int* array;
    // size_t is unsigned type, so it assures representing
    // positive values
    size_t size;
    size_t index;
} Array;

Array* create(int size) {
    Array* array = (Array*) malloc(sizeof(Array));
    array->array = (int*) malloc(sizeof(int) * size);
    array->index = 0;
    array->size = size;

    return array;
}

int size(Array* array) {
    return array->index;
}

int capacity(Array* array) {
    return array->size;
}

enum state is_empty(Array* array) {
    return size(array) == 0 ? True : False;
}

void push(Array* array, int data) {
    if (array->size == array->index) {
        array->size *= 2;
        array->array = (int*) realloc(array->array, sizeof(int) * array->size);
    }
    array->array[array->index++] = data;
}

void set(Array* array, int index, int data) {
    array->array[index] = data;
}

int at(Array* array, int index) {
    return array->array[index];
}

void destroy(Array* array) {
    free(array->array);
    array->array = NULL;
    array->size = array->index = 0;
}