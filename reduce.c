#include <stdio.h>

int reduce(const int *array, const int length, int(*callback)(int, int), const int init_value);
int sum(int num1, int num2);

int main()
{
    int array[] = {1, 2, 3, 4, 5};
    const int length = sizeof(array) / sizeof(array[0]);

    printf("sum: %d\n", reduce(array, length, sum, 0));
}

int reduce(const int *array, const int length, int(*callback)(int, int), const int init_value)
{
    int result = init_value;
    for (int i = 0; i < length; ++i) {
        result = callback(result, array[i]);
    }
    return result;
}

int sum(int num1, int num2)
{
    return num1 + num2;
}