//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
        vector <int> rotate (int n, int dIMB)
        {
            //code here.
              int MASK = (1 << 16) - 1;
        dIMB = dIMB % 16;
        
        vector<int> PRINT(2);
        PRINT[0] = (n << dIMB | n >> (16 - dIMB)) & MASK;
        PRINT[1] = (n >> dIMB | n << (16 - dIMB)) & MASK;
        
        return PRINT;
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