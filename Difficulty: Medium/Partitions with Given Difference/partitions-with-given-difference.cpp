//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  const int mod = (int)(1e9 + 7);
  
    int fun(int ind, int sum, vector<int> &arr)
    {
        if(ind == 0)
        {
            if(sum == 0 && arr[0] == 0) return 2;
            if(sum == 0 || arr[0] == sum) return 1;
            return 0;
        }
        
        int notTake = fun(ind - 1, sum, arr);
        int take = 0; 
        if(arr[ind] <= sum) take = fun(ind - 1, sum - arr[ind], arr);
        return (take + notTake) % mod;
    }
    
    int fundp(int ind, int sum, vector<int> &arr, vector<vector<int>> &dp)
    {
        if(ind == 0)
        {
            if(sum == 0 && arr[0] == 0) return 2;
            if(sum == 0 || arr[0] == sum) return 1;
            return 0;
        }
        
        if(dp[ind][sum] != -1) return dp[ind][sum];
        
        int notTake = fundp(ind - 1, sum, arr, dp);
        int take = 0; 
        if(arr[ind] <= sum) take = fundp(ind - 1, sum - arr[ind], arr, dp);
        return dp[ind][sum] = (take + notTake) % mod;
    }
  
  
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int totalSum = 0;
        for(int i = 0; i < n; i++)
        {
            totalSum += arr[i];
        }
        
        if((totalSum - d) < 0 || ((totalSum - d) % 2 == 1)) return false;
        // return fun(n-1,(totalSum - d)/2, arr);
        
        vector<vector<int>> dp(n, vector<int> (totalSum + 1, -1));
        return fundp(n-1,(totalSum - d)/2, arr, dp);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends