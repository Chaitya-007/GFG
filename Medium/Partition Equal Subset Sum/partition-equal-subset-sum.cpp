//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int get_total=0;
        for(int i=0;i<N;i++)
        get_total+=arr[i];
        if(get_total%2!=0)
        return 0;
        vector<int>dp(get_total+1,0);
        dp[0]=1;
        for(int i=1;i<=N;i++)
        {
            for(int j=get_total/2;j>=arr[i-1];j--)
            {
              if(arr[i-1]<=j)
               {
                dp[j]=dp[j] || dp[j-arr[i-1]];
               }
            }
        }
        return dp[get_total/2];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends