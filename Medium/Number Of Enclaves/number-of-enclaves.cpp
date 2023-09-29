//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

 int countlandCell(int r, int c, vector<vector<int>> &grid){
        int count =0;
        for(auto x : grid)
        {
            for(auto y: x){
                (y==1)?++count:0;
            }
        }
        return count;
    }
    
    bool isValid(int x , int y,  int r, int c ,vector<vector<int>> &grid ){
        if(x<r&&y<c&&x>=0&&y>=0&&grid[x][y]==1)return true;
        return false;
    }
    
    void dfs(int x , int y, int r , int c , vector<vector<int>> &grid){
        grid[x][y] = 0;
        int dx[4] = {0,0,-1,1};
        int dy[4] = {-1,1,0,0};
        for(int i=0;i<4;i++){
            int newX = x+dx[i];
            int newY = y+dy[i];
            if(isValid(newX,newY,r,c,grid)){
                dfs(newX , newY , r, c,grid);
            }
        }
        
    }

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int row = grid.size();
        int col = grid[0].size();
        
        for(int i=0;i<col;i++){
            int j=0;
            if(grid[j][i]==1)dfs(j,i,row,col,grid);
            j = row-1;
            if(grid[j][i]==1)dfs(j,i,row,col,grid);
            
        }
        for(int i=0;i<row;i++){
            int j=0;
            if(grid[i][j]==1)dfs(i,j,row,col,grid);
            j = col-1;
            if(grid[i][j]==1)dfs(i,j,row,col,grid);
        }
        return countlandCell(row ,col , grid);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends