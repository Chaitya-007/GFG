//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
        //  int low = l;
        //  int high = m + 1;
         
         int n1 = m - l + 1;
         int n2 = r - m;
         int leftarr[n1] = {0};
         int rightarr[n2] = {0};
         
         for(int i = 0; i < n1 ; i++)
         {
            leftarr[i] = arr[l + i];
         }
         
         for(int i = 0; i < n2 ; i++)
         {
            rightarr[i] = arr[m + 1 + i];
         }
         
        //  vector<int> vec;
         
         int i = 0;
         int j = 0; 
         int k = l;
         
         while(i < n1 and j < n2)
         {
             if(leftarr[i] <= rightarr[j])
             {
                 arr[k] = leftarr[i];
                 i++;
                 k++;
             }
             else if(leftarr[i] > rightarr[j])
             {
                 arr[k] = rightarr[j];
                 j++;
                 k++;
             }
            //  else
            //  {
            //      arr[k] = leftarr[i];
            //      i++;
            //      k++;
            //      arr[k] = rightarr[j];
            //      j++;
            //      k++;
            //  }
             
         }
         
         while(i < n1)
         {
             arr[k] = leftarr[i];
             i++;
             k++;
         }
         
         while(j < n2)
         {
             arr[k] = rightarr[j];
             j++;
             k++;
         }
         
         
        //  while(low <= m && high <= r)
        //  {
        //      if(arr[low] <= arr[high])
        //      {
        //          vec.emplace_back(arr[low]);
        //          low++;
        //      }
        //      else
        //      {
        //          vec.emplace_back(arr[high]);
        //          high++;
        //      }
        //  }
         
        //  while(low <= m)
        //  {
        //      vec.emplace_back(arr[low]);
        //      low++;
        //  }
         
        //  while(high <= r)
        //  {
        //      vec.emplace_back(arr[high]);
        //      high++;
        //  }
         
        //  for(int i = l; i <= r; i++)
        //  {
        //      arr[i] = vec[i - l];
        //  }
         
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l < r)
        {
            int mid = (l + r)/2;
            mergeSort(arr, l, mid);
            mergeSort(arr, mid + 1, r);
            merge(arr, l, mid, r);
        }
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends