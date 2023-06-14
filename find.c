#include <stdio.h>
#include <stdbool.h>

int find(const int *array, const int length, bool(*callback)(int))
{
    for (int i = 0; i < length; ++i) {
        if (callback(array[i])) {
            return array[i];
        }
    }
    return -1;
}

bool negative(int num)
{
    return num < 0;
}

int main()
{
    int array[] = {1, 3, -7, 8,  2, -9};
    const int length = sizeof(array) / sizeof(array[0]);

    printf("Negative num: %d\n", find(array, length, negative));

}