#include <stdio.h>

void reverse(int *array, const int length)
{
    for (int i = 0; i < length / 2; ++i) {
        int tmp = array[i];
        array[i] = array[length - i - 1];
        array[length - i - 1] = tmp;
    }
}

void print_arr(const int *array, const int length)
{
    for (int i = 0; i < length; ++i) {
        printf("%d%c", array[i], ' ');
    }
    printf("\n");
}

int main()
{
    int array[] = {1, 2, 3, 4, 5};
    const int length = sizeof(array) / sizeof(array[0]);

    printf("Before reverse: ");
    print_arr(array, length);

    reverse(array, length);

    printf("After reverse: ");
    print_arr(array, length);
}