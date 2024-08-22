//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  

  
    int longestCommonSubstr(string str1, string str2) {
        // your code here
        
        // don,t write code for shortest common supersequence
        int n = str1.length();
        int m = str2.length();
        
        // Dont use recursion******************************
        
        // use tabulation
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i = 0; i <= n; i++)  dp[i][0] = 0;
        for(int j = 0; j <= m; j++)  dp[0][j] = 0;
        int ans = 0;

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(str1[i-1] == str2[j-1]) 
                {
                    
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans,dp[i][j]);
                }
        
                else
                dp[i][j] = 0;
            }
        }

        return ans;
        
        // vector<int> prev(m+1,0);
        // vector<int> curr(m+1,0);
        // int ans = 0;
        
        // for(int i = 1; i <= n; i++)
        // {
        //     for(int j = 1; j <= m; j++)
        //     {
        //         if(str1[i-1] == str2[j-1])
        //         {
        //         curr[j] = 1 + prev[j-1];
        //         ans = max(ans,curr[j]);
        //         }
        //         else
        //         curr[j] = 0;
        //     }
        //     prev = curr;
        // }
        
        // return ans;
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