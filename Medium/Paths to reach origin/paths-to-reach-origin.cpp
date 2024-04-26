//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution
{
public:

int mod = 1e9 + 7;

    int solve(int x, int y, vector<vector<int>> &dp)
    {
        if(x == 0 && y==0)
        {
            return 1;
        }
        
        if(dp[x][y] != -1)
        {
            return dp[x][y];
        }
        
        int left = 0, up = 0;
        
        if(y > 0)
        {
            up = solve(x,y-1,dp);
        }
        
        if(x > 0)
        {
            left = solve(x-1,y,dp);
        }
        
        return dp[x][y] = (left + up)%mod;
    }


    int ways(int x, int y)
    {
        //code here.
        
    //     const int MOD = 1000000007;
    // const int MAX_N = 1001; // Adjust this based on constraints

    // int dp[MAX_N][MAX_N];

    // // Initialize the base cases
    // dp[0][0] = 1;
    // for (int i = 1; i <= x; i++) {
    //     dp[i][0] = 1;
    // }
    // for (int j = 1; j <= y; j++) {
    //     dp[0][j] = 1;
    // }

    // // Fill up the dp array
    // for (int i = 1; i <= x; i++) {
    //     for (int j = 1; j <= y; j++) {
    //         dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
    //     }
    // }

    // return dp[x][y];
    
    vector<vector<int>> dp(x+1, vector<int> (y+1,-1));
    
    return solve(x,y,dp);
    
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<<ob.ways(x,y)<<endl;
    }
	return 0;
}

// } Driver Code Ends