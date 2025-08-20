/*Write a recursive C program to implement Selection Sort using pointers.
• The recursive function should sort the array using the Selection Sort algorithm.
• Access and manipulate the array elements using pointers (i.e., avoid using arr[i]
style directly).
• The program should read the array from the user in the main function, call the
recursive sorting function, and display the sorted array.*/
/*#include <stdio.h>
#include<stdlib.h>
// Function to swap two elements using pointers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void recursiveSelectionSort(int *arr, int start, int n) {
    if (start >= n - 1)
        return;
    int minIndex = start;
    for (int i = start + 1; i < n; i++) {
        if (*(arr + i) < *(arr + minIndex)) {
            minIndex = i;
        }
    }
    if (minIndex != start) {
        swap(arr + start, arr + minIndex);
    }

    // Recursive call for the next part of the array
    recursiveSelectionSort(arr, start + 1, n);
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    recursiveSelectionSort(arr, 0, n);
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    return 0;
}
*/
