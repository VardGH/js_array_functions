#include <stdio.h>
#include <stdlib.h>

int* with(const int *array, const int length, const int index, const int value)[]
void print_arr(const int *array, const int length);

int main()
{
    int array[] = {1, 3, -7, 8,  2, -9};
    const int length = sizeof(array) / sizeof(array[0]);

    int index = 2;
    int value = 10;
    int *res = with(array, length, index, value);
    print_arr(res, length);

    free(res);
}

int* with(const int *array, const int length, const int index, const int value)
{
    if (index < 0) {
        printf("Index is out of range\n");
        return NULL;
    }

    int *result = (int*)malloc(sizeof(int) * length);
    if (result == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    for (int i = 0; i < length; ++i) {
        result[i] = array[i];
    }
    result[index] = value;

    return result;
}

void print_arr(const int *array, const int length)
{
    for (int i = 0; i < length; ++i) {
        printf("%d%c", array[i], ' ');
    }
    printf("\n");
}