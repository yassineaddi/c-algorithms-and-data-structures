int* quick_sort(int array[], int start, int end) {
    if (start >= end) {
        return array;
    }

    int pivot = array[end];
    int i = start-1;

    for (int j = start; j < end; j++) {
        if (array[j] < pivot) {
            ++i;
            int temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
    }

    int temp = array[i+1];
    array[i+1] = pivot;
    array[end] = temp;

    array = quick_sort(array, start, i);
    array = quick_sort(array, i+2, end);

    return array;
}