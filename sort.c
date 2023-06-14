#include <stdio.h>

void swap(int *a, int *b);
void sort(int array[], const int length);
void print_arr(const int *array, const int length);

int main() {
    int arr[] = {3, 4, 9, 2, 1, 6};
    int length = sizeof(arr) / sizeof(arr[0]);

    printf("Array: ");
    print_arr(arr, length);

    sort(arr, length);

    printf("Sorted Array: ");
    print_arr(arr, length);

    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int array[], const int length) {
    for (int i = 0; i < length - 1; ++i) {
        for (int j = 0; j < length - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

void print_arr(const int *array, const int length)
{
    for (int i = 0; i < length; ++i) {
        printf("%d%c", array[i], ' ');
    }
    printf("\n");
}