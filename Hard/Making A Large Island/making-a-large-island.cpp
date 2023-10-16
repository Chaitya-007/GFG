//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    
    map<int, int> mp;
    bool isValid(int i, int j, int n)
    {
        if(i<0 || j<0 || i==n || j==n)
            return false;
        else
            return true;
    }
    int dfs(int i, int j, vector<vector<int>> &grid, bool **vis, int name, int n)
    {
        if(isValid(i, j, n)== false)
            return 0;
            
        if(vis[i][j]== true || grid[i][j]== 0)
            return 0;
            
        vis[i][j]= true;
        grid[i][j]= name;
        int cntl= dfs(i, j-1, grid, vis, name, n);
        int cntu= dfs(i-1, j, grid, vis, name, n);
        int cntr= dfs(i, j+1, grid, vis, name, n);
        int cntd= dfs(i+1, j, grid, vis, name, n);
        
        return 1+ cntl+cntu+cntr+cntd;
        
    }
    
public:
    int largestIsland(vector<vector<int>>& grid) 
    {
        // Your code goes here.
         int name= 2;
        int n= grid.size();
        bool **vis= new bool * [n];
        for(int i= 0; i<n; i++)
        {
            vis[i]= new bool[n];
            for(int j= 0; j<n; j++)
            {
                vis[i][j]= false;
            }
        }
        
        for(int i= 0; i<n; i++)
        {
            for(int j= 0; j<n; j++)
            {
                if(grid[i][j]== 1 && !vis[i][j])
                {
                    int count= dfs(i, j, grid, vis, name, n);
                    mp[name]= count;
                    name++;
                }
            }
        }
        int ans= 0;
        for(int i= 0; i<n; i++)
        {
            for(int j= 0; j<n; j++)
            {
                int cnt= 1;
                if(grid[i][j]== 0)
                {
                    set<int> st;
                    if(isValid(i, j-1, n) && grid[i][j-1]!= 0)
                    {
                        cnt+= mp[grid[i][j-1]];
                        st.insert(grid[i][j-1]);
                    }
                    if(isValid(i-1, j, n) && grid[i-1][j]!= 0 && st.find(grid[i-1][j])==st.end())
                    {
                        cnt+= mp[grid[i-1][j]];
                        st.insert(grid[i-1][j]);
                    }
                    if(isValid(i, j+1, n) && grid[i][j+1]!= 0 && st.find(grid[i][j+1])==st.end())
                    {
                        cnt+= mp[grid[i][j+1]];
                        st.insert(grid[i][j+1]);
                    }
                    if(isValid(i+1, j, n) && grid[i+1][j]!= 0 && st.find(grid[i+1][j])==st.end())
                    {
                        cnt+= mp[grid[i+1][j]];
                        st.insert(grid[i+1][j]);
                    }
                        
                    if(cnt>ans)
                        ans= cnt;
                }
            }
        }
        if(ans== 0)
            return n*n;
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    }
    return 0;
}

// } Driver Code Ends