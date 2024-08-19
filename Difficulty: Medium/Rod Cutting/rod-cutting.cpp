//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  
    int fun(int ind, int W, int price[])
    {
        if(ind == 0)
        {
            return (W/(ind+1)) * price[ind];
        }
        
        int notTake = fun(ind - 1, W, price);
        int take = INT_MIN;
        
        if((ind+1) <= W)
        {
            take = price[ind] + fun(ind,W - (ind+1),price);
        }
        
        return max(take,notTake);
    }
    
     int fundp(int ind, int W, int price[], vector<vector<int>> &dp)
    {
        if(ind == 0)
        {
            return (W/(ind+1)) * price[ind];
        }
        
        if(dp[ind][W] != -1) return dp[ind][W];
        
        int notTake = fundp(ind - 1, W, price,dp);
        int take = INT_MIN;
        
        if((ind+1) <= W)
        {
            take = price[ind] + fundp(ind,W - (ind+1),price, dp);
        }
        
        return dp[ind][W] = max(take,notTake);
    }
  
    int cutRod(int price[], int n) {
        //code here
        // return fun(n-1,n,price);
    
        vector<vector<int>> dp(n, vector<int> (n+1,-1));
        return fundp(n-1,n,price,dp);
      
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends