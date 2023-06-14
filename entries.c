#include <stdio.h>

struct Entry
{
    int key;
    int value;
};

void entries(const int* array, const int length, struct Entry* result) {
    for (int i = 0; i < length; ++i) {
        result[i].key = i;
        result[i].value = array[i];
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    const int length = sizeof(arr) / sizeof(arr[0]);

    struct Entry result[length];
    entries(arr, length, result);

    printf("Entries:\n");
    for (int i = 0; i < length; i++) {
        printf("[%d] -> %d\n", result[i].key, result[i].value);
    }

    return 0;
}