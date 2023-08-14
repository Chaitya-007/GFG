//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string revStr(string S) {
        // code here
        // if(S.length()%2 != 0)
        int n = S.length();
        for(int i = 0 ; i < (n/2) ; i++)
        {
            char temp;
            temp = S[i];
            S[i] = S[n-1-i];
            S[n-1-i] = temp;
        }
        
        return S;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.revStr(S) << endl;
    }
    return 0;
}

// } Driver Code Ends