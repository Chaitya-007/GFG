//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int fun(int ind,int sum, int arr[], vector<vector<int>> &dp)
	{
	    if(ind == 0)
	    {
	        if(sum == 0 && arr[0] == 0) return 2;
	        if(sum == 0 || arr[0] == sum) return 1;
	        return 0;
	    }
	    
	    if(dp[ind][sum] != -1) return dp[ind][sum];
	    
	    int notTake = fun(ind-1,sum,arr,dp);
	    int take = 0;
	    if(arr[ind] <= sum) take = fun(ind-1,sum - arr[ind],arr,dp);
	    return dp[ind][sum] = take + notTake;
	}
	
	const int MOD = 1e9 + 7;
	
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        // vector<vector<int>> dp(n,vector<int>(sum + 1,-1));
        // return fun(n-1,sum,arr,dp);
        
        //   vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

        // // Base cases
        // if (arr[0] == 0) dp[0][0] = 2;  // If the first element is 0 and sum is 0, there are 2 ways (include or exclude)
        // else dp[0][0] = 1;               // There's always 1 way to make sum 0 (by excluding all elements)
        
        // if (arr[0] != 0 && arr[0] <= sum) dp[0][arr[0]] = 1;  // If first element is equal to or less than the sum, there's 1 way to achieve it
    
        // // Fill the dp table iteratively
        // for (int ind = 1; ind < n; ind++) {
        //     for (int target = 0; target <= sum; target++) {
        //         int notTake = dp[ind-1][target];  // Not taking the current element
        //         int take = 0;
        //         if (arr[ind] <= target) {
        //             take = dp[ind-1][target - arr[ind]];  // Taking the current element
        //         }
        //         dp[ind][target] = take + notTake;
        //     }
        // }
        
        // // The answer will be stored in dp[n-1][sum]
        // return dp[n-1][sum];
        
        
         vector<int> prev(sum + 1, 0), curr(sum + 1, 0);

        // Base cases
        if (arr[0] == 0) prev[0] = 2;  // If the first element is 0 and sum is 0, there are 2 ways (include or exclude)
        else prev[0] = 1;               // There's always 1 way to make sum 0 (by excluding all elements)
        
        if (arr[0] != 0 && arr[0] <= sum) prev[arr[0]] = 1;  // If first element is equal to or less than the sum, there's 1 way to achieve it
    
        // Fill the dp array iteratively
        for (int ind = 1; ind < n; ind++) {
            for (int target = 0; target <= sum; target++) {
                int notTake = prev[target];  // Not taking the current element
                int take = 0;
                if (arr[ind] <= target) {
                    take = prev[target - arr[ind]];  // Taking the current element
                }
                curr[target] = (take + notTake) % MOD;
            }
            prev = curr;  // Move the current row to the previous row for the next iteration
        }
        
        // The answer will be stored in prev[sum]
        return prev[sum];
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends