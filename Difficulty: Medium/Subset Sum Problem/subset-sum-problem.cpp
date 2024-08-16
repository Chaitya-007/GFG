//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    
    bool fun(int ind, int sum, vector<int> arr)
    {
        if(sum == 0)  return true;
        
        if(ind == 0)  return arr[0] == sum;
        
        bool notTake = fun(ind - 1, sum, arr);
        
        bool take = false;
        
        if(arr[ind] <= sum) take = fun(ind-1, sum - arr[ind], arr);
        
        return notTake | take;
    }
    
     bool fundp(int ind, int sum, vector<int> arr,  vector<vector<int>> &dp)
    {
        if(sum == 0)  return true;
        
        if(ind == 0)  return arr[0] == sum;
        
        if(dp[ind][sum] != -1)  return dp[ind][sum];
        
        bool notTake = fundp(ind - 1, sum, arr, dp);
        
        bool take = false;
        
        if(arr[ind] <= sum) take = fundp(ind-1, sum - arr[ind], arr, dp);
        
        return dp[ind][sum] = notTake | take;
    }
    
    bool funMapdp(int ind, int sum, vector<int> &arr, map<pair<int, int>, int> &dp) {
    if (sum == 0) return true;
    
    if (ind == 0) return arr[0] == sum;
    
    if (dp.find({ind, sum}) != dp.end()) return dp[{ind, sum}];
    
    bool notTake = funMapdp(ind - 1, sum, arr, dp);
    
    bool take = false;
    
    if (arr[ind] <= sum) take = funMapdp(ind - 1, sum - arr[ind], arr, dp);
    
    return dp[{ind, sum}] = notTake | take;
}

    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        // return fun(n-1,sum,arr);
        
        // vector<vector<int>> dp(n,vector<int> (sum + 1, -1));
        // return fundp(n-1,sum,arr,dp);
        
        //  map<pair<int, int>, int> dp;  // Use map instead of vector
        //  return funMapdp(n - 1, sum, arr, dp);
    
        
        vector<vector<bool>> dp(n, vector<bool> (sum+1,false));
        
        for(int i = 0; i < n; i++) dp[i][0] = true;
        
        if(arr[0] <= sum) dp[0][arr[0]] = true;
        
        for(int ind = 1; ind < n; ind++)
        {
            for(int target = 1; target <= sum; target++)
            {
                bool notTake = dp[ind - 1][target];
        
                bool take = false;
                
                if(arr[ind] <= target) take = dp[ind-1][target - arr[ind]];
                
                 dp[ind][target] = notTake | take;
            }
        }
        
        return dp[n-1][sum];
        
        
    //       map<pair<int, int>, bool> dp;  // Use map instead of vector<vector<bool>>

    // // Base case initialization
    //     for(int i = 0; i < n; i++) dp[{i, 0}] = true;
        
    //     if(arr[0] <= sum) dp[{0, arr[0]}] = true;
    
    //     // Filling the dp map
    //     for(int ind = 1; ind < n; ind++) {
    //         for(int target = 1; target <= sum; target++) {
    //             bool notTake = dp[{ind - 1, target}];
    //             bool take = false;
                
    //             if(arr[ind] <= target) take = dp[{ind - 1, target - arr[ind]}];
                
    //             dp[{ind, target}] = notTake | take;
    //         }
    //     }
        
    //     return dp[{n-1, sum}];
        
        // vector<bool> prev(sum+1,false);
        // vector<bool> curr(sum+1,false);
        
        // prev[0] = true;
        // curr[0] = true;
        
        // if(arr[0] <= sum) prev[arr[0]] = true;
        
        
        // for(int ind = 1; ind < n; ind++)
        // {
        //     for(int target = 1; target <= sum; target++)
        //     {
        //         bool notTake = prev[target];
        
        //         bool take = false;
                
        //         if(arr[ind] <= target) take = prev[target - arr[ind]];
                
        //          curr[target] = notTake | take;
        //     }
        //     prev = curr;
        // }
        
        // return prev[sum];
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends