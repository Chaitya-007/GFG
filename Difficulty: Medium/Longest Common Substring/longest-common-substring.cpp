//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestCommonSubstr(string s1, string s2) {
        // your code here
        int n = s1.length();
        int m = s2.length();
        vector<int> prev(m+1,0);
        vector<int> curr(m+1,0);
        int ans = 0;
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(s1[i-1] == s2[j-1])
                {
                    curr[j] = 1 + prev[j-1];
                    ans = max(ans,curr[j]);
                }
                else
                {
                    curr[j] = 0;
                }
            }
            prev = curr;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends