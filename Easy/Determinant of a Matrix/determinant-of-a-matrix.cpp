//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function for finding determinant of matrix.
    int determinantOfMatrix(vector<vector<int> > matrix, int n)
    {
        // code here 
        // if the matrix is 1 * 1, return the single element
        if(n == 1) {
            return matrix[0][0];
        }
        
        int determinant = 0;
        
        // iterate over each element in the first row of the matrix
        for(int i = 0; i < n; i++) {
            vector <vector <int>> InnerMatrix (n - 1, vector <int> (n - 1));
            
            // create a submatrix excluding the current row and column
            for(int j = 1; j < n; j++) {
                int col = 0;
                for(int k = 0; k < n; k++) {
                    if(k == i) {
                        continue;
                    }
                    InnerMatrix[j - 1][col++] = matrix[j][k];
                }
            }
            
            // calculate the determinant using the formula
            if(i % 2 == 0) {
                determinant += (matrix[0][i]) * (determinantOfMatrix(InnerMatrix, n - 1));
            } else {
                determinant -= (matrix[0][i]) * (determinantOfMatrix(InnerMatrix, n - 1));
            }
            
        }
            // return the calculated determinant
            return determinant;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        int result = ob.determinantOfMatrix(matrix, n);
        cout<<result<<endl;
    }
    return 0;
}
// } Driver Code Ends