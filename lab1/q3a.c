//Write a C program to sort a given list of elements using

//Bubble Sort
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, temp;
    printf("enter the number of elements in the array:\n");
    scanf("%d", &n);

    int arr[n];
    printf("enter the elements of the array:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    // Bubble sort algorithm
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Printing the sorted array
    printf("sorted array:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}
