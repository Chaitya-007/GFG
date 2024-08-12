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

    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        // return fun(n-1,sum,arr);
        
        vector<vector<int>> dp(n,vector<int> (sum + 1, -1));
        return fundp(n-1,sum,arr,dp);
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