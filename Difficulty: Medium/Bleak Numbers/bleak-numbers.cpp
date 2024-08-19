//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	int is_bleak(int n)
	{
	    // Code here.
	    for(int i = n - log2(n); i < n; i++)
	    {
	        int bits = __builtin_popcount(i);
	        if((i + bits) == n)
	        {
	           // cout<<i;
	            return false;
	        }
	    }
	    
	    return true;
	}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code Ends