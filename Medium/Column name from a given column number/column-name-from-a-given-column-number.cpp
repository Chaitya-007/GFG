//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
           string result = "";
    
        while (n > 0) {
            // Calculate the remainder when dividing by 26
            int remainder = (n - 1) % 26;
            
            // Convert the remainder to a character ('A' to 'Z')
            char charValue = 'A' + remainder;
            
            // Prepend the character to the result string
            result = charValue + result;
            
            // Update n for the next iteration
            n = (n - 1) / 26;
        }
        
        return result;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends