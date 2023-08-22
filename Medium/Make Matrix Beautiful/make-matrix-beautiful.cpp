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
          int sum_of_matrix = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sum_of_matrix = sum_of_matrix + matrix[i][j];
            }
        }
    
        int rows_max_total = 0;
        int cloumns_max_total = 0;
    
        for (int i = 0; i < n; i++) {
            int a = 0;
            for (int j = 0; j < n; j++) {
                a = a + matrix[i][j];
            }
            rows_max_total = max(rows_max_total, a);
    
            int b = 0;
            for (int j = 0; j < n; j++) {
                b = b + matrix[j][i];
            }
            cloumns_max_total = max(cloumns_max_total, b);
        }
    
        int maxVal = max(cloumns_max_total, rows_max_total);
    
        return maxVal * n - sum_of_matrix;
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