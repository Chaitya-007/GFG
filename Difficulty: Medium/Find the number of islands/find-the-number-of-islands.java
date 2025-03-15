//{ Driver Code Starts
import java.util.*;

class GFG {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int tc = scanner.nextInt(); // Number of test cases
        while (tc-- > 0) {
            int n = scanner.nextInt(); // Number of rows
            int m = scanner.nextInt(); // Number of columns
            char[][] grid = new char[n][m];

            // Read the grid input
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    grid[i][j] = scanner.next().charAt(0);
                }
            }
            Solution obj = new Solution();
            int ans = obj.numIslands(grid);
            System.out.println(ans);
            System.out.println("~");
        }
        scanner.close();
    }
}

// } Driver Code Ends


class Solution {
    
    public void dfs(int row, int col, char[][] grid, boolean[][] vis,int[] delRow, int[] delCol)
    {
        vis[row][col] = true;
        
        int n = grid.length;
        int m = grid[0].length;
        
        for(int i = 0; i < 8; i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol])
            {
                dfs(nrow,ncol,grid,vis,delRow,delCol);
            }
        }
        
    }
    
    public int numIslands(char[][] grid) {
        // Code here
        int n = grid.length;
        int m = grid[0].length;
        
        boolean[][] vis = new boolean[n][m];
        int ans = 0;
        
        int[] delRow = {-1,-1,0,1,1,1,0,-1};
        int[] delCol = {0,1,1,1,0,-1,-1,-1};
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(!vis[i][j] && grid[i][j] == '1')
                {
                    ans++;
                    dfs(i,j,grid,vis,delRow,delCol);
                }
            }
        }
        
        return ans;
    }
}