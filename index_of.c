#include <stdio.h>

int index_of(const int *array, const int length, const int target)
{
    for (int i = 0; i < length; ++i) {
        if (array[i] == target) {
            return i;
        }
    }
    return -1;
}

int main()
{
    int array[] = {1, 2, 3, 4, 5};
    int length = sizeof(array) / sizeof(array[0]);

    int elem1 = 13;
    int id1 = index_of(array, length, elem1);

    if (id1 != -1) {
        printf("Index of %d: %d\n", elem1, id1);
    } else {
        printf("Element %d not found in the array.\n", elem1);
    }

    int elem2 = 4;
    int id2 = index_of(array, length, elem2);

    if (id2 != -1) {
        printf("Index of %d: %d\n", elem2, id2);
    } else {
        printf("Element %d not found in the array.\n", elem2);
    }

    return 0;
}