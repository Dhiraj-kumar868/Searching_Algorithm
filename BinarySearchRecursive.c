/*Write a program to search an element x in an array of n integers using binary search
algorithm that uses divide and conquer technique. Find out the best case, worst case and
average case time complexities for different values of n and plot a graph of the time
taken versus n. The n integers can be generated randomly and x can be choosen
randomly, or any element of the array or middle or last element of the array depending
on type of time complexity analysis.*/


#include <stdio.h>
#include <stdlib.h>
#include<time.h>
void insertionSort(int array[], int n)
{
    
    for (int i = 1; i < n; i++)
    {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && key < array[j])
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}
int BinarySearch(int arr[], int lb,int ub,int x)
{
    
     int mid;
     if(lb>ub){
         return -1;
     }else{
     mid=(lb+ub)/2;
     if(x==arr[mid]){
         return mid;
     }
     else if(x<arr[mid])
         return BinarySearch(arr, lb, mid - 1, x);
     else 
         return BinarySearch(arr, mid + 1, ub, x);
     }
}

int main()
{
    int n;
    clock_t start_t, end_t;
    double total_t;
    printf("\nEnter the number of element:");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % n;
    }
    insertionSort(arr,n);
    printf("\n\nDisplaying Elements:\n ");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", arr[i]);
    }
    start_t = clock();
    int x;
    printf("\n\nEnter the number to search:");
    scanf("%d",&x);
    int result=BinarySearch(arr,0,n-1,x);
    end_t = clock();
    if(result==-1){
        printf("\n\nElement not found.");
    }
    else{
        printf("\n\nElement found.");
    }
     total_t = (double)(end_t - start_t) / (double)CLOCKS_PER_SEC;
    printf("\n\nThe time required to search an element= %lf ", total_t);
    printf("\n\n");
    return 0;
}