//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
   
    int minOperation(int n)
    {
        //code here.
        int a=-1,b=-1;
        while(n){
            a++;
            if(n&1) b++;
            n>>=1;
        }
        return 1+a+b;
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