/*Write a small function to find the smallest element in an array using pointers.
In the main function, create a dynamically allocated array, read the values from the
keyboard, and pass the array to the function.
Display the result (smallest element) in the main function.*/

#include <stdio.h>
#include <stdlib.h>

int smallest_element(int *p, int n) {
    if (n == 0) {
        printf("Array does not exist.\n");
        return -1;
    }

    int smallest = *p; // Start with the first element

    for (int i = 1; i < n; i++) {
        if (*(p + i) < smallest) {
            smallest = *(p + i);
        }
    }

    return smallest;
}

int main() {
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    // Dynamically allocate array
    int *a = (int *)malloc(n * sizeof(int));
    if (a == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Given array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    int smallest = smallest_element(a, n);
    printf("\nThe smallest element of the given array is %d\n", smallest);

    // Free the dynamically allocated memory
    free(a);

    return 0;
}

