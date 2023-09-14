//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
         const int modu = 1e9 + 7;
       
 vector<vector<int>> dyn_prog(n + 1, vector<int>(sum + 1, 0));
 
    // Initialize the dp array
    dyn_prog[0][0] = 1;
    for (int j = 1; j <= sum; j++)
        dyn_prog[0][j] = 0;
 
    // Fill the dp array
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            if (arr[i - 1] <= j)
                dyn_prog[i][j] = (dyn_prog[i - 1][j] + dyn_prog[i - 1][j - arr[i - 1]]) % modu;
            else
                dyn_prog[i][j] = dyn_prog[i - 1][j];
        }
    }
 
    return dyn_prog[n][sum];
        
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends