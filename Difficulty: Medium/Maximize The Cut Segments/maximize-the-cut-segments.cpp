//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int fun(int n, int x, int y, int z, vector<int> &dp)
    {
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];
        int op1 = INT_MIN;
        int op2 = INT_MIN;
        int op3 = INT_MIN;
        
        if(n>=x) op1 = fun(n-x,x,y,z,dp);
        if(n>=y) op2 = fun(n-y,x,y,z,dp);
        if(n>=z) op3 = fun(n-z,x,y,z,dp);
        
        return dp[n] = 1 + max(op1,max(op2,op3));
    }
    
    
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int> dp(n+1,-1);
        int ans = fun(n,x,y,z,dp);
        if(ans < 0) return 0;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends