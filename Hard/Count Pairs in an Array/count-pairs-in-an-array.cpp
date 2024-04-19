//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    
    int merge(int arr[],int low, int mid, int high)
    {
        int left = low;
        int right = mid + 1;
        vector<int> vec;
        int inv = 0;
        
        while(left <= mid && right <= high)
        {
            if(arr[left] <= arr[right])
            {
                vec.emplace_back(arr[left]);
                left++;
            }
            else
            {
             vec.emplace_back(arr[right]);
             right++;
             inv += (mid + 1 - left);
            }
        }
        
        while(left<=mid)
        {
            vec.emplace_back(arr[left]);
            left++;
        }
        
        while(right<=high)
        {
            vec.emplace_back(arr[right]);
            right++;
        }
        
        for(int i = low; i <= high; i++)
        {
            arr[i] = vec[i - low];
        }
        
        return inv;
    }
    
    int mergesort(int arr[], int low, int high)
    {
        int inv = 0;
        if(low < high)
        {
            int mid = (low + high)/2;
            inv += mergesort(arr,low,mid);
            inv += mergesort(arr,mid+1,high);
            inv += merge(arr,low,mid,high);
        }
        
        return inv;
    }
    
    int countPairs(int arr[] , int n ) 
    {
        // Your code goes here  
        
        for(int i = 0; i < n; i++)
        {
            arr[i] = (i*arr[i]);
        }
        
       int inversion = mergesort(arr, 0, n-1);
       return inversion;
        
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