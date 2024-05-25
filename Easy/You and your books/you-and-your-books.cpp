//{ Driver Code Starts
#include <algorithm>
#include <cstdio>
#include <iostream>
//#include<Windows.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    /*You are requried to complete this method */
    long long max_Books(int arr[], int n, int k) {
        // Your code here
         long long maxbooks = 0LL;
        long long sum = 0LL;
        
        for(int i = 0; i < n; i++)
        {
            if(arr[i] <= k)
            {
                sum += arr[i];
                maxbooks = max(maxbooks,sum);
            }
            else
            {
                sum = 0LL;
            }
        }
        
        return maxbooks;
    }
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int ar[n];
        for (int i = 0; i < n; i++) {
            cin >> ar[i];
        }
        Solution ob;
        cout << ob.max_Books(ar, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends