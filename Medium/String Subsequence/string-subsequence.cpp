//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int mod=1e9+7;
  int help(string a,string b,int i,int j,vector<vector<int>>&dp){
      if(j==b.size())return 1;
      if(i==a.size())return 0;
      if(dp[i][j]!=-1)return dp[i][j];
      int x=0,y=0;
      if(a[i]==b[j])x=help(a,b,i+1,j+1,dp);
      y=help(a,b,i+1,j,dp);
      return dp[i][j]=+(x+y)%mod;
  }
  
  
    int countWays(string s1, string s2) {
        // code here
         vector<vector<int>>dp(s1.length(),vector<int>(s2.size(),-1));
        return help(s1,s2,0,0,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        Solution obj;
        int res = obj.countWays(s1, s2);

        cout << res << endl;
    }
}

// } Driver Code Ends