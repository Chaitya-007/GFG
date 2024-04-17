//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
public:
    int merging(int arr[], int low, int mid, int high)
    {
        int i = low, j = mid + 1, count = 0, k = 0, n = high - low + 1;
        int temp[n];
        
        while(i <= mid and j <= high) 
        {
            if(arr[i] <= arr[j])
                temp[k++] = arr[i++];
            else 
            {
                count += mid - i + 1;
                temp[k++] = arr[j++];
            }
        }
        
        while(i <= mid)
            temp[k++] = arr[i++];
            
        while(j <= high)
            temp[k++] = arr[j++];
            
        for(i = 0, j = low; i < n; i++, j++)
            arr[j] = temp[i];
            
        return count;
    }

    int mergeSort(int arr[], int low, int high) 
    {
        int count = 0;
        
        if(low < high) 
        {
            int mid = low + (high - low) / 2;
            count += mergeSort(arr, low, mid);
            count += mergeSort(arr, mid + 1, high);
            count += merging(arr, low, mid, high);
        }
        
        return count;
    }

    int countPairs(int arr[] , int n ) 
    {
        for(int i = 0; i < n; i++)
            arr[i] *= i;
            
        return mergeSort(arr, 0, n - 1);
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	Solution ob;
    	cout<<ob.countPairs(a, n)<<endl;
    }
}
// } Driver Code Ends