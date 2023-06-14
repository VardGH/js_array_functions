#include <stdlib.h>
#include <stdio.h>

int* concat(const int *array1, const int length1, const int *array2, const int length2);
void print_arr(const int *array, const int length);

int main()
{
    int array1[] = {1, 2, 3};
    int length1 = sizeof(array1) / sizeof(array1[0]);
    
    int array2[] = {4, 5, 6, 7};
    int length2 = sizeof(array2) / sizeof(array2[0]);

    int *res = concat(array1, length1, array2, length2);

    if (res != NULL) {
        print_arr(res, length1 + length2);
        free(res);
    }
    
    return 0;
}

int* concat(const int *array1, const int length1, const int *array2, const int length2)
{
    int *result = (int*)malloc((length1 + length2) * sizeof(int));
    
    if (result == NULL) {
        printf("%s\n", "Memory allocation failed!");
        return NULL;
    }

    for (int i = 0; i < length1; ++i) {
        result[i] = array1[i];
    }

    for (int i = length1; i < length1 + length2; ++i) {
        result[i] = array2[i - length1];
    }

    return result;
}

void print_arr(const int *array, const int length)
{
    for (int i = 0; i < length; ++i) {
        printf("%d%c", array[i], ' ');
    }
    printf("\n");
}