#include <stdio.h>
#include <stdbool.h>

bool some(const int *array, const int length, bool(*callback)(int));
bool is_even(int num);

int main()
{
    int array[] = {1, 2, 3, 5, 5};
    const int length = sizeof(array) / sizeof(array[0]);

    printf("Has even number: %s\n", some(array, length, is_even) ? "true" : "false");

    int array2[] = {1, 7, 3, 5, 5};
    const int length2 = sizeof(array2) / sizeof(array2[0]);
    printf("Has even number: %s\n", some(array2, length2, is_even) ? "true" : "false");

    return 0;
}

bool some(const int *array, const int length, bool(*callback)(int))
{
    for (int i = 0; i < length; ++i) {
        if (callback(array[i])) {
            return true;
        }
    }
    return false;
}

bool is_even(int num)
{
    return num % 2 == 0;
}
