#include <stdio.h>
#include <stdlib.h>

int* map(const int *array, const int length, int(*callback)(int));
int square(int num);
void print_arr(const int *array, const int length);

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6};
    const int length = sizeof(array) / sizeof(array[0]);

    int *result = map(array, length, square);

    print_arr(result, length);

    free(result);
}

int* map(const int *array, const int length, int(*callback)(int))
{
    int *res = (int*)malloc(length * sizeof(int));

    if (res == NULL)
    {
        printf("%s\n", "Memory allocation failed!");
        return NULL;
    }

    for (int i = 0; i < length; ++i) {
        res[i] = callback(array[i]);
    }
    return res;
}

int square(int num) {
    return num * num;
}

void print_arr(const int *array, const int length)
{
    for (int i = 0; i < length; ++i) {
        printf("%d%c", array[i], ' ');
    }
    printf("\n");
}