//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

// using dp
    bool fun(int ind, int target, vector<int> arr)
    {
        if(target == 0) return true;
        
        if(ind == 0) return (arr[0] == target);
        
        bool notTake = fun(ind - 1, target,arr);
        bool take = false;
        
        if(arr[ind] <= target)
        {
            take = fun(ind - 1, target - arr[ind],arr);
        }
        
        return (take | notTake);
    }
    
    // using dp
    bool funDP(int ind, int target, vector<int> arr, vector<vector<int>>& dp)
    {
        if(target == 0) return true;
        
        if(ind == 0) return (arr[0] == target);
        
        if(dp[ind][target] != -1) return dp[ind][target];
        
        bool notTake = funDP(ind - 1, target,arr,dp);
        
        bool take = false;
        
        if(arr[ind] <= target)
        {
            take = funDP(ind - 1, target - arr[ind],arr,dp);
        }
        
        return dp[ind][target] = (take | notTake);
    }

    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        
        // Using recursion
        // return fun(n-1,sum,arr);
        // T.C -> 2^n
        // S.C -> O(N)
        
        // Using dp
        // vector<vector<int>> dp(n,vector<int> (sum + 1, -1));
        // return funDP(n-1,sum,arr,dp);
        // T.C -> O(N*target)
        // S.C -> O(N) + O(M*N)
        
        // Tabulation
        // T.C -> O(N*target)
        // S.C -> O(N * target)
        
    
        // vector<vector<bool>> dp(n, vector<bool>(sum + 1, 0));
        
        // for(int i = 0; i < n; i++)
        // {
        //     dp[i][0] = true;
        // }
        
        // dp[0][arr[0]] = true;
        
        // for(int ind = 1; ind < n; ind++)
        // {
        //     for(int target = 1; target <= sum; target++)
        //     {
        //         bool notTake = dp[ind - 1][target];
        //         bool take = false;
        //         if(arr[ind] <= target)
        //         {
        //             take = dp[ind - 1][target - arr[ind]];
        //         }
                
        //         dp[ind][target] = (take | notTake);
        //     }
        // }
        
        
        // return dp[n-1][sum];
        
        vector<bool> prev(sum+1,0);
        vector<bool> curr(sum+1,0);
        
        prev[0] = curr[0] = true;
        
        if(arr[0] <= sum)
        {
            
        prev[arr[0]] = true;
        }
        
        for(int ind = 1; ind < n; ind++)
        {
            for(int target = 1; target <= sum; target++)
            {
                bool notTake = prev[target];
                bool take = false;
                if(arr[ind] <= target)
                {
                    take = prev[target - arr[ind]];
                }
                
                curr[target] = (take | notTake);
            }
            
            prev = curr;
        }
        
        return prev[sum];
        
        
        
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