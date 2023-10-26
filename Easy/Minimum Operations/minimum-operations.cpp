//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
   int f(int n)
    {
        if(n==1)
        return 1;
        
        if(n%2==0)
        return 1+f(n/2);
        
        else
        return 1+f(n-1);
        
    }
    int minOperation(int n)
    {
        //code here.
        return f(n);
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
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}
// } Driver Code Ends