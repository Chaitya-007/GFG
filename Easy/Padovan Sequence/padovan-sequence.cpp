//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int m = 1e9+7;
    int padovanSequence(int n) {
        // code here.
          int a = 1, b = 1, c = 1;
        int d = 1;
        for(int i=3;i<=n;i++) {
            d = (b%m + c%m)%m;
            c = b;
            b = a;
            a = d;
        }
        return d;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.padovanSequence(n) << endl;
    }
    return 0;
}
// } Driver Code Ends