//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{   
    public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int> > matrix, int n, int m) 
    {
        // code here3 1
    vector<int> ans_new;
        for(int i = 0; i < m; i++)
            ans_new.push_back(matrix[0][i]);
        for(int i = 1; i < n - 1; i++)
            ans_new.push_back(matrix[i][m - 1]);
        if(n == 1)
            return ans_new;
        for(int i = m - 1; i >= 0; i--)
            ans_new.push_back(matrix[n - 1][i]);
        if(m == 1)
            return ans_new;
        for(int i = n - 2; i >= 1; i--)
            ans_new.push_back(matrix[i][0]);
        return ans_new;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.boundaryTraversal(matrix, n, m);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends