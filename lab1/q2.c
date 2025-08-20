/*Given an array of integers, implement binary search to find the position of a given key. */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;

    int key;
    printf("enter the number of elements in the array:");printf("\n");
    scanf("%d",&n);
    int arr[n];
    printf("enter the elements of the sorted array:");printf("\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("\n");
    printf("enter the element to find:");

    scanf("%d",&key);
    printf("\n");
    int i;
    //binary search algorithm
    int high=n;
    int low=0;
    while(high>low){
        int mid=(high+low)/2;
        if(arr[mid]==key){
            printf("position of %d is %d",key,mid+1);
            break;
        }
        else if(arr[mid]>key){
            high=mid;
        }
         else if(arr[mid]<key){
            low=mid;
        }
        else{printf("not found");
        }
    }


    return 0;
}

