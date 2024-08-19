//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int fun(int ind, int W, int val[], int wt[])
    {
        
        if(ind == 0)
        {

         return (W/wt[0]) * val[0];
        }
        
        int notTake = fun(ind - 1, W, val, wt);
        int take = INT_MIN;
        
        if(wt[ind] <= W)
        {
            take = val[ind] + fun(ind, W - wt[ind], val, wt);
        }
        
        return max(take, notTake);
    }
    
    int fundp(int ind, int W, int val[], int wt[], vector<vector<int>> &dp)
    {
        
        if(ind == 0)
        {
           return (W/wt[0]) * val[0];
        }
        
        if(dp[ind][W] != -1) return dp[ind][W];
        
        int notTake = fundp(ind - 1, W, val, wt, dp);
        int take = INT_MIN;
        
        if(wt[ind] <= W)
        {
            take = val[ind] + fundp(ind, W - wt[ind], val, wt, dp);
        }
        
        return dp[ind][W] = max(take, notTake);
    }

    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        // return fun(N-1,W,val,wt);
        // vector<vector<int>> dp(N, vector<int> (W+1,-1));
        // return fundp(N-1, W, val, wt, dp);
        
        // vector<vector<int>> dp(N, vector<int> (W+1,0));
        
        // for(int target = 0; target <= W; target++)
        // {
        //     dp[0][target] = (target/wt[0]) * val[0];
        // }
        
        // for(int ind = 1; ind < N; ind++)
        // {
        //     for(int target = 0; target <= W; target++)
        //     {
        //         int notTake = dp[ind - 1][target];
        //         int take = INT_MIN;
                
        //         if(wt[ind] <= target)
        //         {
        //             take = val[ind] + dp[ind][target - wt[ind]];
        //         }
                
        //          dp[ind][target] = max(take, notTake);
        //     }
        // }
        
        // return dp[N-1][W];
        
        // vector<int> prev(W+1,0);
        // vector<int> curr(W+1,0);
        
        // for(int target = 0; target <= W; target++)
        // {
        //     prev[target] = (target/wt[0]) * val[0];
        // }
        
        // for(int ind = 1; ind < N; ind++)
        // {
        //     for(int target = 0; target <= W; target++)
        //     {
        //         int notTake = prev[target];
        //         int take = INT_MIN;
                
        //         if(wt[ind] <= target)
        //         {
        //             take = val[ind] + curr[target - wt[ind]];
        //         }
                
        //          curr[target] = max(take, notTake);
        //     }
        //     prev = curr;
        // }
        
        // return prev[W];
        
        vector<int> prev(W+1,0);
        
        for(int target = 0; target <= W; target++)
        {
            prev[target] = (target/wt[0]) * val[0];
        }
        
        for(int ind = 1; ind < N; ind++)
        {
            for(int target = 0; target <= W; target++)
            {
                int notTake = prev[target];
                int take = INT_MIN;
                
                if(wt[ind] <= target)
                {
                    take = val[ind] + prev[target - wt[ind]];
                }
                
                 prev[target] = max(take, notTake);
            }
        }
        
        return prev[W];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends