// Write a C program to sort a given list of elements using selection sort
#include <stdio.h>

int main() {
    int n, minIndex, temp;

    printf("enter the number of elements in the array:\n");
    scanf("%d", &n);

    int arr[n];
    printf("enter the elements of the array:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Selection sort algorithm
    for(int i = 0; i < n - 1; i++) {
        minIndex = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first unsorted element
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    // Print the sorted array
    printf("sorted array:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}


