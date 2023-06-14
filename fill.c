#include <stdio.h>

void fill1(int *array, const int length, const int value)
{
    for (int i = 0; i < length; ++i) {
        array[i] = value;
    }
}

void fill2(int *array, const int length, const int value, const int start)
{
    for (int i = start; i < length; ++i) {
        array[i] = value;
    }
}

void fill3(int *array, const int length, const int value, const int start, const int end)
{
    for (int i = start; i < end; ++i) {
        array[i] = value;
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

    printf("Before fill: ");
    print_arr(array, length);

    int value = 6;
    fill1(array, length, value);

    printf("After fill: ");
    print_arr(array, length);

    int array1[] = {1, 2, 3, 4, 5};
    const int length1 = sizeof(array1) / sizeof(array1[0]);

    printf("Before fill: ");
    print_arr(array1, length1);

    int value1 = 10;
    int start1 = 3;
    fill2(array1, length1, value1, start1);

    printf("After fill: ");
    print_arr(array1, length1);

    int array2[] = {1, 2, 3, 4, 5, 6, 7};
    const int length2 = sizeof(array2) / sizeof(array2[0]);

    printf("Before fill: ");
    print_arr(array2, length2);

    int value2 = 20;
    int start2 = 3;
    int end2  = 6;
    fill3(array2, length2, value2, start2, end2);

    printf("After fill: ");
    print_arr(array2, length2);

}