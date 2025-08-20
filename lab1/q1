/*Given an array of n integers and a key element, write a C program to search the element
using linear search. */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;

    int key;
    printf("enter the number of elements in the array:");printf("\n");
    scanf("%d",&n);
    int arr[n];
    printf("enter the elements of the array:");printf("\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("\n");
    printf("enter the element to find:");

    scanf("%d",&key);
    printf("\n");
    int i;
    //linear search algorithm
    for(i=0;i<n;i++){
        if(arr[i] == key){
            printf("position of %d is %d ",key,i+1);
            break;
        }

    }
     if(i==n) {
            printf("%d is not found in the given array",key);
        }

    return 0;
}

