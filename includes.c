#include <stdio.h>
#include <stdbool.h>

int includes(const int *array, const int length, const int target)
{
    for (int i = 0; i < length; ++i) {
        if (target == array[i]) {
            return true;
        }
    }
    return false;
}

int main()
{
    int array[] = {1, 3, -7, 8,  2, -9};
    const int length = sizeof(array) / sizeof(array[0]);

    printf("Negative num: %d\n", includes(array, length, negative));

}