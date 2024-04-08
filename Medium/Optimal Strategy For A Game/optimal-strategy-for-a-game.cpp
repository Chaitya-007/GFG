//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
     long long dp[1001][1001];
     long long f(int s , int e , int arr[])
    {
       // cout<<s<<" "<<e<<endl;
        if(s>e)
        return 0;
        if(dp[s][e]!=-1)
        return dp[s][e];
        long long a = arr[s]+min(f(s+1,e-1,arr),f(s+2,e,arr));
        long long b = arr[e]+min(f(s,e-2,arr),f(s+1,e-1,arr));
        return dp[s][e]=max(a,b);
        
    }
    long long maximumAmount(int n, int arr[]){
        // Your code here
        memset(dp,-1,sizeof(dp));
        return f(0,n-1,arr);
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(n,a)<<endl;
	}
	return 0;
}
// } Driver Code Ends