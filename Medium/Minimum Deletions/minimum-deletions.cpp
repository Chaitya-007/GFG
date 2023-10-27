//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int minimumNumberOfDeletions(string s) { 
        // code here
        // int maxlen = 1;
        // int st = 0;
        // int n = S.length();
        // for(int i = 0; i < n - 1; i++)
        // {
        //     int l = i;
        //     int r = i + 1;
        //     while(l>= 0 and r < n)
        //     {
        //         if(S[l] != S[r])
        //         {
        //             break;
        //         }
        //         l--;
        //         r++;
        //     }
            
        //     int len = r - l - 1;
        //     if(maxlen < len)
        //     {
        //         maxlen = len;
        //     }
        // }
        
        // for(int i = 0; i < n; i++)
        // {
        //     int l = i;
        //     int r = i;
        //     while(l >= 0 and r<n)
        //     {
        //         if(S[l] != S[r])
        //         {
        //             break;
        //         }
        //         l--;
        //         r++;
        //     }
        //     int len = r - l - 1;
        //     if(maxlen < len)
        //     {
        //         maxlen = len;
        //     }
        // }
        // int result = (n - maxlen);
        // return result;
        
          int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++) 
        {
            for (int j = 1; j <= n; j++) 
            {
                if (s[i - 1] == s[n - j]) 
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else 
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        int len = dp[n][n];
        return n-len;
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends