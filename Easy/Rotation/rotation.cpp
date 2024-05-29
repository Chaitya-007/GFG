//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	    int mino = INT_MAX;
	    int index = -1;
	    int low = 0;
	    int high = n - 1;
	    
	    while(low <= high)
	    {
	        int mid = low + (high - low)/2;
	        
	        if(arr[low] <= arr[high])
	        {
	            if(arr[low] < mino)
	            {
	                index = low;
	                mino = arr[low];
	            }
	            break;
	        }
	        
	        if(arr[low] <= arr[mid])
	        {
	            if(arr[low] < mino)
	            {
	                index = low;
	                mino = arr[low];
	            }
	            low = mid + 1;
	        }
	        else
	        {
	            if(arr[mid] < mino)
	            {
	                index = mid;
	                mino = arr[mid];
	            }
	            high = mid - 1;
	        }
	    }
	    
	    return index;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends