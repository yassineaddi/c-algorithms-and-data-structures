int* merge(int left[], int right[], int left_size, int right_size) {
    int i = 0, j = 0, k = 0;
    int *merged = (int*) malloc(sizeof(int)*(left_size+right_size));

    while (i < left_size && j < right_size) {
        if (right[j] < left[i]) {
            merged[k] = right[j];
            ++j;
        } else {
            merged[k] = left[i];
            ++i;
        }
        ++k;
    }

    while (i < left_size) {
        merged[k] = left[i];
        ++k;
        ++i;
    }
    while (j < right_size) {
        merged[k] = right[j];
        ++k;
        ++j;
    }

    return merged;
}

int* merge_sort(int array[], int size) {
    if (size == 1) {
        return array;
    }

    int mid = size/2;
    int* left = (int*) malloc(sizeof(int)*mid);
    int* right = (int*) malloc(sizeof(int)*(size-mid));

    for (int i=0; i<mid; i++) {
        left[i] = array[i];
    }
    int j = 0;
    for (int i=mid; i<size; i++) {
        right[j] = array[i];
        ++j;
    }

    left = merge_sort(left, mid);
    right = merge_sort(right, size-mid);

    return merge(left, right, mid, size-mid);
}