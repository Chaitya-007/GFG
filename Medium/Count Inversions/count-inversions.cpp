//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    long long int merge(long long arr[], long long left, long long mid, long long right)
    {
        long long low = left;
        long long high = mid + 1;
        vector<long long int> temp;
        long long int inversion = 0;
        
        while(low <= mid && high <= right)
        {
            if(arr[low] <= arr[high])
            {
                temp.emplace_back(arr[low]);
                low++;
            }
            else
            {
                inversion += (mid + 1 - low);
                temp.emplace_back(arr[high]);
                high++;
            }
        }
        
        while(low <= mid)
        {
            temp.emplace_back(arr[low]);
            low++;
        }
        
        while(high <= right)
        {
            temp.emplace_back(arr[high]);
            high++;
        }
        
        for(int i = left; i <= right ; i++)
        {
            arr[i] = temp[i - left];
        }
        
        return inversion;
    }
    
    
    long long int mergesort(long long arr[],long long left, long long right)
    {
        long long int inversion = 0;
        if(left < right)
        {
            long long mid = (left + right)/2;
            inversion += mergesort(arr,left,mid);
            inversion += mergesort(arr,mid+1,right);
            inversion += merge(arr,left,mid,right);
        }
        
        return inversion;
    }
    
    
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here

        long long int inversions = mergesort(arr,0,N-1);
        return inversions;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends