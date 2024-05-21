//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        map<int,int> prefixsum;
        
        int sum = 0;
        int maxlen = 0;
        
        for(int i = 0; i < N; i++)
        {
            sum += A[i];
            
            if(sum == K)
            {
                maxlen = max(maxlen, i + 1);
            }
            
            int rem = sum - K;
            
            if(prefixsum.find(rem) != prefixsum.end())
            {
                int len = i - prefixsum[rem];
                maxlen = max(maxlen,len);
            }
            
            if(prefixsum.find(sum) == prefixsum.end())
            {
                prefixsum[sum] = i;
            }
        }
        
        return maxlen;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends