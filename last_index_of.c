#include <stdio.h>

int last_index_of(const int *array, const int length, const int target)
{
    for (int i = length - 1; i > -1; --i) {
        if (array[i] == target) {
            return i;
        }
    }
    return -1;
}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 3, 4, 1};
    int length = sizeof(array) / sizeof(array[0]);

    int elem1 = 3;
    int id1 = last_index_of(array, length, elem1);

    if (id1 != -1) {
        printf("Last index of %d: %d\n", elem1, id1);
    } else {
        printf("Element %d not found in the array.\n", elem1);
    }

    int elem2 = 13;
    int id2 = last_index_of(array, length, elem2);

    if (id2 != -1) {
        printf("Last index of %d: %d\n", elem2, id2);
    } else {
        printf("Element %d not found in the array.\n", elem2);
    }

    return 0;
}