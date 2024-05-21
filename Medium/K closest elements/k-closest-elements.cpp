//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        // code here
         int i = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
        int j = i-1;
        if(j >= 0 && arr[j] == x)
            j--;

        vector<int> res;
        while(k--) {
            int upperDiff = INT_MAX;
            if(i < n) upperDiff = arr[i] - x;
            int lowerDiff = INT_MAX;
            if(j >= 0) lowerDiff = x - arr[j];
            
            if(upperDiff <= lowerDiff) res.push_back(arr[i++]);
            else res.push_back(arr[j--]);
        }

        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends