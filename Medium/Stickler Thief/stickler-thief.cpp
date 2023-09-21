//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        if (n == 0) {
        return 0;
    }

    if (n == 1) {
        return arr[0]; 
    }

    vector<int> dp(n, 0); 

    dp[0] = arr[0]; 
    dp[1] = max(arr[0], arr[1]); 

    for (int i = 2; i < n; i++) {
        // The maximum money at the i-th house is the maximum of two options:
        // 1. Skip the current house and take the maximum money from the previous house.
        // 2. Loot the current house and add its money to the maximum money from two houses ago.
        dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
    }

    return dp[n - 1]; // Return the maximum money at the last house.
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends