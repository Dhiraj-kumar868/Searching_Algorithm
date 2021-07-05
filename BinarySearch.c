#include <stdio.h>
int BinarySearch(int array[], int start, int end, int element){
   while (start <= end){
      int middle = start + (end- start )/2;
      if (array[middle] == element)
         return middle;
      if (array[middle] < element)
         start = middle + 1;
      else
         end = middle - 1;
   }
   return -1;
}
int main(void){
   int arr[] = {10, 20, 30, 40, 50, 60, 70};
   int n = 7;
   int element = 40;
   int found_index = BinarySearch(arr, 0, n-1, element);
   if(found_index == -1 ) {
      printf("Element not found in the array ");
   }
   else {
      printf("Element found at index : %d",found_index);
   }
   return 0;
}