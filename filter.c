#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* filter(const int *array, const int length, bool(*callback)(int), int *filtered_length);
bool isPositive(int num);
void print_arr(const int *array, const int length);

int main() {
    int array[] = {-5, -4, -2, -1, 0, 1, 2, 3, 4, 5};
    int length = sizeof(array) / sizeof(array[0]);

    int filtered_length = 0;
    int *res = filter(array, length, isPositive, &filtered_length);

    if (res != NULL) {
        printf("Filtered array: ");
        print_arr(res, filtered_length);
        free(res);
    }

    return 0;
}

int* filter(const int *array, const int length, bool(*callback)(int), int *filtered_length)
{
    int count = 0;
    for (int i = 0; i < length; ++i) {
        if (callback(array[i])) {
            ++count;
        }
    }

    if (count == 0) {
        return NULL;
    } 

    int *res = (int*)malloc(count * sizeof(int));
    for (int i = 0, j = 0; i < length; ++i) {
        if (callback(array[i])) {
            res[j++] = array[i];
        }
    }

    *filtered_length = count;
    return res;
}

bool isPositive(int num) {
    return num > 0;
}

void print_arr(const int *array, const int length)
{
    for (int i = 0; i < length; ++i) {
        printf("%d%c", array[i], ' ');
    }
    printf("\n");
}