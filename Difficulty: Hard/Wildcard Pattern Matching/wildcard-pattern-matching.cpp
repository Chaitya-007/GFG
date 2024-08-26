//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method*/
       int fun(int i, int j, string p, string s)
    {
        if(i < 0 && j < 0) return true;
        if(i < 0 && j >=0) return false;
        if(i >= 0 && j < 0)
        {
            for(int m = 0; m <= i; m++)
            {
                if(p[m] != '*')
                {
                    return false;
                }
            }
            
            return true;
        }
        
        if(p[i] == '*')
        {
            return fun(i-1,j,p,s) | fun(i,j-1,p,s);
        }
        
        if(p[i] == s[j] || p[i] == '?')
        {
            return fun(i-1,j-1,p,s);
        }
        
        return false;
    }
    
     int funDp(int i, int j, string &p, string &s, vector<vector<int>> &dp)
    {
        if(i < 0 && j < 0) return true;
        if(i < 0 && j >=0) return false;
        if(i >= 0 && j < 0)
        {
            for(int m = 0; m <= i; m++)
            {
                if(p[m] != '*')
                {
                    return false;
                }
            }
            
            return true;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(p[i] == '*')
        {
            return dp[i][j] = funDp(i-1,j,p,s,dp) | funDp(i,j-1,p,s,dp);
        }
        
        if(p[i] == s[j] || p[i] == '?')
        {
            return dp[i][j] = funDp(i-1,j-1,p,s,dp);
        }
        
        return dp[i][j] = false;
    }
    
     int funDpOneShift(int i, int j, string &p, string &s, vector<vector<int>> &dp)
    {
        if(i == 0 && j == 0) return true;
        if(i == 0 && j > 0) return false;
        if(i > 0 && j == 0)
        {
            for(int m = 1; m <= i; m++)
            {
                if(p[m-1] != '*')
                {
                    return false;
                }
            }
            
            return true;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(p[i-1] == '*')
        {
            return dp[i][j] = funDpOneShift(i-1,j,p,s,dp) | funDpOneShift(i,j-1,p,s,dp);
        }
        
        if(p[i-1] == s[j-1] || p[i-1] == '?')
        {
            return dp[i][j] = funDpOneShift(i-1,j-1,p,s,dp);
        }
        
        return dp[i][j] = false;
    }
    
    int wildCard(string pattern, string str) {
        // code here
        int n = pattern.length();
        int m = str.length();
        // return fun(n-1,m-1,pattern,str);
        
        // vector<vector<int>> dp(n, vector<int> (m, -1));
        // return funDp(n-1,m-1,pattern,str,dp);
        
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        return funDpOneShift(n,m,pattern,str,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends