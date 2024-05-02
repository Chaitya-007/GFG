//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        // Code here
        pair<int, int> direction = {0,1};
        int row = 0;
        int col = 0;
        int nrow,ncol;
        
        while(true)
        {
            if(matrix[row][col] == 1)
            {
                if(direction.first == 0 && direction.second == 1)
                {
                    direction.first = 1;
                    direction.second = 0;
                }
                else if(direction.first == 1 && direction.second == 0)
                {
                    direction.first = 0;
                    direction.second = -1;
                }
                else if(direction.first == 0 && direction.second == -1)
                {
                    direction.first = -1;
                    direction.second = 0;
                }
                else if(direction.first == -1 && direction.second == 0)
                {
                    direction.first = 0;
                    direction.second = 1;
                }
                
                matrix[row][col] = 0;
            }
            
            nrow = row + direction.first;
            ncol = col + direction.second;
            
            if(nrow >= n || nrow < 0 || ncol >= m || ncol < 0)
            {
                return {row,col};
            }
            
            row = nrow;
            col = ncol;
        }
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends