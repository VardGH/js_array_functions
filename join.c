#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* join(const int* array, const int length, const char* separator);

int main() 
{
    int array[] = {1, 2, 3, 4, 5};
    const int length = sizeof(array) / sizeof(array[0]);
    const char* separator = "/";

    char* result = join(array, length, separator);
    printf("%s\n", result);

    free(result);

    return 0;
}

char* join(const int* array, const int length, const char* separator) 
{
    int separator_length = strlen(separator);
    int digit_length = 11;  // max number of digits for a 32-bit integer
    int sum_length = 0;

    for (int i = 0; i < length; ++i) {
        sum_length += digit_length;
        if (i < length - 1) {
            sum_length += separator_length;
        }
    }

    char* result = (char*)malloc((sum_length + 1) * sizeof(char));
    result[0] = '\0';

    for (int i = 0; i < length; ++i) {
        char number[digit_length];
        snprintf(number, digit_length, "%d", array[i]);
        strcat(result, number);
        if (i < length - 1) {
            strcat(result, separator);
        }
    }

    return result;
}