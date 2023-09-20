//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
        vector <int> rotate (int n, int due)
        {
            //code here.
            int MASK = (1 << 16) - 1;
        due = due % 16;
        
        vector<int> get(2);
        get[0] = (n << due | n >> (16 - due)) & MASK;
        get[1] = (n >> due | n << (16 - due)) & MASK;
        
        return get;
        }
};


//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        
        int n, d; cin >> n >> d;
        Solution ob;
        vector <int> res = ob.rotate (n, d);
        cout << res[0] << endl << res[1] << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends