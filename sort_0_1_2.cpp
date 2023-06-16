#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   int low=0,high=n-1,mid=0;
   while(mid<=high){
      if(arr[mid]==0){
          swap(arr[mid],arr[low]);low++;mid++;
      }
      else if(arr[mid]==1){
        mid++;
      }
      else{
         swap(arr[mid],arr[high]);high--;
      }
   }
   //   Write your code here
}
