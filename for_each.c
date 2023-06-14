#include <stdio.h>

void for_each(const int *array, const int length, void(*callback)(int))
{
    for (int i = 0; i < length; ++i) {
        callback(array[i]);
    }
}

void print_arr(int num) {
    printf("%d ", num);
}

int main() {
    int array[] = {1, 2, 3, 4, 5};
    int length = sizeof(array) / sizeof(array[0]);

    printf("Array: ");
    for_each(array, length, print_arr);
    printf("\n");

    return 0;
}





