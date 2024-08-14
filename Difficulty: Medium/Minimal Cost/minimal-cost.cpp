//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int fun(int ind, vector<int> &arr,int k)
    {
        if(ind == 0) return 0;
        
        int mmsteps = INT_MAX;
        
        for(int j = 1; j <= k; j++)
        {
            if(ind - j >= 0)
            {
                int jumps = fun(ind - j,arr,k) + abs(arr[ind] - arr[ind - j]);
                mmsteps = min(mmsteps,jumps);
            }
        }
        
        return mmsteps;
    }
    
     int fundp(int ind, vector<int> &arr,int k, vector<int> &dp)
    {
        if(ind == 0) return 0;
        
        if(dp[ind] != -1) return dp[ind];
        int mmsteps = INT_MAX;
        
        for(int j = 1; j <= k; j++)
        {
            if(ind - j >= 0)
            {
                int jumps = fundp(ind - j,arr,k,dp) + abs(arr[ind] - arr[ind - j]);
                mmsteps = min(mmsteps,jumps);
            }
        }
        
        return dp[ind] = mmsteps;
    }
  
    int minimizeCost(vector<int>& arr, int& k) {
        // Code here
        int n = arr.size();
        // return fun(n-1,arr,k);
        
        vector<int> dp(n,-1);
        return fundp(n-1,arr,k,dp);
        
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(arr, k);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends