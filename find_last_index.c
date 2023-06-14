#include <stdio.h>
#include <stdbool.h>

int find(const int *array, const int length, bool(*callback)(int))
{
    for (int i = length - 1; i > -1; --i) {
        if (callback(array[i])) {
            return i;
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
    int array[] = {1, 3, -7, 8,  2, -9, 10};
    const int length = sizeof(array) / sizeof(array[0]);

    printf("last index: %d\n", find(array, length, negative));

}