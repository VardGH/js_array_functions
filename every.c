#include <stdio.h>
#include <stdbool.h>

bool every(const int *array, const int length, bool(*callback)(int))
{
    for (int i = 0; i < length; ++i) {
        if (!callback(array[i])) {
            return false;
        }
    }
    return true;
}

bool is_positive(int num) {
    return num > 0;
}

bool is_even(int num) {
    return num % 2 == 0;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int length1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {2, 4, 5, 8, 10};
    int length2 = sizeof(arr2) / sizeof(arr2[0]);

    int res1 = every(arr1, length1, is_positive);
    int res2 = every(arr2, length2, is_even);

    printf("All elements in arr1 are positive: %s\n", res1 ? "true" : "false");
    printf("All elements in arr2 are even: %s\n", res2 ? "true" : "false");

    return 0;
}