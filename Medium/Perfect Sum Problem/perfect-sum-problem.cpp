//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int perfectSum(int arr[], int n, int total)
	{
        // Your code goes here
         const int modulo = 1e9 + 7;
       
 vector<vector<int>> dynamic_programming(n + 1, vector<int>(total + 1, 0));
 
    // Initialize the dp array
    dynamic_programming[0][0] = 1;
    for (int j = 1; j <= total; j++)
        dynamic_programming[0][j] = 0;
 
    // Fill the dp array
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= total; j++) {
            if (arr[i - 1] <= j)
                dynamic_programming[i][j] = (dynamic_programming[i - 1][j] + dynamic_programming[i - 1][j - arr[i - 1]]) % modulo;
            else
                dynamic_programming[i][j] = dynamic_programming[i - 1][j];
        }
    }
 
    return dynamic_programming[n][total];
        
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