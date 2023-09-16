//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        
        // your code here
          const long long MODULOS = 1000000007;
        // your code here
        if (n == 0 || n == 1) return 1;
        if (n == 2) return 2;
    
        // Initialize the only three variables to store results of the last three steps
        long long STEP_3 = 2, STEP_2 = 1, STEP_1 = 1;
    
        // Current step value
        long long current_POSITION = 0;
    
        for (int i = 3; i <= n; i++) {
            // Calculate current ways
            current_POSITION = (STEP_1 + STEP_2 + STEP_3) % MODULOS;
    
            // Update for next iteration
            STEP_1 = STEP_2;
            STEP_2 = STEP_3;
            STEP_3 = current_POSITION;
        }
        
        return current_POSITION;
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends