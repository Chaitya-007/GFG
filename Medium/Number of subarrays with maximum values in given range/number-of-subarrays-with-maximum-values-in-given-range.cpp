//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    long countSubarrays(int a[], int n, int L, int R)
    {
        // Complete the function
          long long int ans=0;
        int start=0;
        int p=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]>=L && a[i]<=R)
            {
                p=i-start+1;
            }
            else if(a[i]>R)
            {
                start=i+1;
                p=0;
            }
            ans=ans+p;
        }
        return ans;
        
        
    }
};

//{ Driver Code Starts.
// driver program
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        
        int n ,l,r;
        cin >> n>>l>>r;
        int a[n];
        for(int i=0;i<n;i++)
        cin >> a[i];
        Solution ob;
    	cout << ob.countSubarrays(a, n, l, r)<<endl;
    }
	return 0;
}

// } Driver Code Ends