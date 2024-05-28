//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	   // int lbind = lower_bound(arr,arr+n,x) - arr;
	   // if(lbind == n)
	   // {
	   //     return 0;
	   // }
	   // int ubind = upper_bound(arr,arr+n,x) - arr;
	   // int highind = ubind - 1;
	    
	   // return (highind - lbind + 1);
	   
	   int low = 0;
	   int high = n - 1;
	   int firstind = -1;
	   
	   while(low <= high)
	   {
	       int mid = low + (high - low)/2;
	       
	       if(arr[mid] == x)
	       {
	           firstind = mid;
	           high = mid - 1;
	       }
	       else if(arr[mid] < x)
	       {
	           low = mid + 1;
	       }
	       else
	       {
	           high = mid - 1;
	       }
	   }
	   
	   if(firstind == -1)
	   {
	       return 0;
	   }
	   
	   low = 0;
	   high = n - 1;
	   int lastind = -1;
	   
	   while(low <= high)
	   {
	       int mid = low + (high - low)/2;
	       
	       if(arr[mid] == x)
	       {
	           lastind = mid;
	           low = mid + 1;
	       }
	       else if(arr[mid] > x)
	       {
	           high = mid - 1;
	       }
	       else
	       {
	           low = mid + 1;
	       }
	   }
	   
	   //int lastind = upbound - 1;
	   
	   return (lastind - firstind + 1);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends