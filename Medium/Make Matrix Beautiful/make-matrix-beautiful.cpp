//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        // code here 
          int total = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                total = total + matrix[i][j];
            }
        }
    
        int row_max_sum = 0;
        int cloumns_max_sum = 0;
    
        for (int i = 0; i < n; i++) {
            int a = 0;
            for (int j = 0; j < n; j++) {
                a = a + matrix[i][j];
            }
            row_max_sum = max(row_max_sum, a);
    
            int b = 0;
            for (int j = 0; j < n; j++) {
                b = b + matrix[j][i];
            }
            cloumns_max_sum = max(cloumns_max_sum, b);
        }
    
        int maxVal = max(cloumns_max_sum, row_max_sum);
    
        return maxVal * n - total;
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
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends