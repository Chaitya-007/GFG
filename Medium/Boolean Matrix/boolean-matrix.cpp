//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        // code here 
        vector<int>vec;
        for(int i = 0; i < matrix.size(); i++)
        {
            int j;
            int flag = 0;
            for( j = 0; j < matrix[i].size(); j++)
            {
                if(matrix[i][j] == 1)
                {
                    flag = 1;
                    vec.emplace_back(i);
                    vec.emplace_back(j);
                }
            }
            
            if(flag == 1)
            {
                for(int k = 0; k < matrix[i].size(); k++)
                {
                    matrix[i][k] = 1;
                }
                
                
            }
            
        }
        
        // auto itr = vec.begin();
        // int start = 0;
        int i = 0;
        while(i < vec.size())
        {

            int j = vec[i+1];
            for(int i = 0; i < matrix.size() ; i++)
            {
                matrix[i][j] = 1;
            }
            i = i + 2;
        
            
        }
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        ob.booleanMatrix(matrix);


        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}



// } Driver Code Ends