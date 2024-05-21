//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends


class Solution{
    public:
    
    
    
    
        long long pairWithMaxSum(long long arr[], long long N)
    {
        // Your code goes here
        // Brute force
        // long long res = 0;
        // long long score = 0;
        // for(int i = 0; i < (N - 1); i++)
        // {
        //     long long smallest = arr[i];
        //     long long ssmallest = arr[i + 1];
        //     for(int j = i + 1; j < N; j++)
        //     {
                
        //         if(smallest > arr[j])
        //         {
        //             ssmallest = smallest;
        //             smallest = arr[j];
        //         }
                
        //         score = smallest + ssmallest;
                
        //         res = max(res,score);
        //     }
        // }
        
        // return res;
         long long ans=0;
       long long i=0,j=N-1;
       while(i<j){
           long long val=arr[i]+arr[i+1];
           ans=max(ans,val);
           i++;
       }
       return ans;
        
        
    }
};



//{ Driver Code Starts.
int main() 
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll a[n];
	    for(ll i=0;i<n;i++)
		    cin>>a[i];
		Solution ob;
	    cout<<ob.pairWithMaxSum(a,n)<<endl;
	}
	return 0;
}


// } Driver Code Ends