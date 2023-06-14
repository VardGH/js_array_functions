#include <stdio.h>
#include <stdlib.h>

int* slice1(const int *array, const int length, const int start);
int* slice2(const int *array, const int length, const int start, const int end);
void print_arr(const int *array, const int length);

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7};
    const int length = sizeof(array) / sizeof(array[0]);

    const int start = -4;
    int *res = slice1(array, length, start);

    if (res != NULL) {
        print_arr(res, abs(start));
    } else {
        printf("start out of range\n");
    }

    const int start1 = 0;
    const int end1 = 5;
    int *res1 = slice2(array, length, start1, end1);

    if (res1 != NULL) {
        print_arr(res1, end1 - start1);
    } else {
        printf("out of range\n");
    }

    const int start2 = 4;
    const int end2 = -1;
    int *res2 = slice2(array, length, start2, end2);

    if (res2 != NULL) {
        print_arr(res2, length - start2 - abs(end2));
    } else {
        printf("out of range\n");
    }

    free(res);
    free(res1);
    free(res2);
}

int* slice1(const int *array, const int length, const int start)
{
    if (start >= 0 && start < length) {
        int *result = (int*)malloc((length - start) * sizeof(int));

        if (result == NULL) {
            return NULL;
        }

        for (int i = start, j = 0; i < length; ++i) {
            result[j++] = array[i];
        }
        return result;
    } else if (start < 0 && abs(start) < length) {
        int *result = (int*)malloc(abs(start) * sizeof(int));

        if (result == NULL) {
            return NULL;
        }

        for (int i = length - abs(start), j = 0; i < length; ++i) {
            result[j++] = array[i];
        }
        return result;
    }
    return NULL;
}

int* slice2(const int *array, const int length, const int start, const int end)
{
    if (start >= 0 && end > 0 && end < length) {
        int *res = (int*)malloc(sizeof(int)*(end - start));

        if (res == NULL) {
            return NULL;
        }

        for (int i = start, j = 0; i < end; ++i) {
            res[j++] = array[i];
        }
        return res;

    } else if (start >= 0 && end < 0) {
        int *res = (int*)malloc(sizeof(int) * (length - start - abs(end)));

        if (res == NULL) {
            return NULL;
        }

        for (int i = start, j = 0; i < length - abs(end); ++i) {
            res[j++] = array[i];
        }
        return res;
    }
    return NULL;
}

void print_arr(const int *array, const int length)
{
    for (int i = 0; i < length; ++i) {
        printf("%d%c", array[i], ' ');
    }
    printf("\n");
}