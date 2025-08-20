//Write a C program to sort a given list of elements using insertion sort
#include <stdio.h>

int main() {
    int n, key, j;

    printf("enter the number of elements in the array:\n");
    scanf("%d", &n);

    int arr[n];
    printf("enter the elements of the array:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Insertion sort
    for(int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Shift elements that are greater than key to one position ahead
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    // Print the sorted array
    printf("sorted array:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
