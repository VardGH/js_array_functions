#include <stdio.h>
#include <stdlib.h>

int* splice1(const int* array, const int length, const int start);
int* splice2(const int* array, const int length, const int start, const int end);
int* splice3(const int* array, const int length, const int start, const int end, int value);
void print_arr(const int *array, const int length);

int main() {
    int array[] = {1, 2, 3, 4, 5};
    const int length = sizeof(array) / sizeof(array[0]);
    
    int start = 2;
    int* result = splice1(array, length, start);

    if (result != NULL) {
        printf("Spliced array: ");
        print_arr(result, start);
    } else {
        printf("Invalid start index\n");
    }

    int array2[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int length2 = sizeof(array2) / sizeof(array2[0]);
    int start2 = 5;
    int end2 = 2;
    int* result2 = splice2(array2, length2, start2, end2);

    if (result2 != NULL) {
        printf("Spliced array2: ");
        print_arr(result2, length2 - end2);
    } else {
        printf("Invalid start or end index\n");
    }

    int array3[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int length3 = sizeof(array3) / sizeof(array3[0]);
    int start3 = -4;
    int end3 = 3;
    int* result3 = splice2(array3, length3, start3, end3);

    if (result3 != NULL) {
        printf("Spliced array3: ");
        print_arr(result3, length3 - end3);
    } else {
        printf("Invalid start or end index\n");
    }


    int array4[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int length4 = sizeof(array4) / sizeof(array4[0]);
    int start4 = 3;
    int end4 = 2;
    int* result4 = splice3(array4, length4, start4, end4, 100);

    if (result4 != NULL) {
        printf("Spliced array4: ");
        print_arr(result4, length4 - end4 + 1);
    } else {
        printf("Invalid start or end index\n");
    }


    free(result);
    free(result2);
    free(result3);
    free(result4);

    return 0;
}

int* splice1(const int* array, const int length, const int start) 
{
    int *result = (int*)malloc(start*sizeof(int));
    for (int i = 0; i < start; ++i) {
        result[i] = array[i];
    }
    return result;
}

int* splice2(const int* array, const int length, const int start, const int end) 
{
    int* result = result = (int*)malloc((length - end) * sizeof(int));

    if (start >= 0) {
        for (int i = 0; i < start; ++i) {
            result[i] = array[i];
        }
        for (int i = start + end, j = 0; i < length; ++i) {
            result[start + j] = array[i];
            ++j;
        }
    } else {
        for (int i = 0; i < length - abs(start); ++i) {
            result[i] = array[i];
        }
        for (int i = length - abs(start) + end, j = 0; i < length; ++i) {
            result[length - abs(start) + j] = array[i];
            ++j;
        }
    } 

    return result;
}

int* splice3(const int* array, const int length, const int start, const int end, int value) 
{
    int* result = result = (int*)malloc((length - end + 1) * sizeof(int));

    if (start >= 0) {
        for (int i = 0; i < start; ++i) {
            result[i] = array[i];
        }
        result[start] = value;
        for (int i = start + end, j = 0; i < length; ++i) {
            result[start + j + 1] = array[i];
            ++j;
        }
    }

    return result;
}


void print_arr(const int *array, const int length)
{
    for (int i = 0; i < length; ++i) {
        printf("%d%c", array[i], ' ');
    }
    printf("\n");
}
