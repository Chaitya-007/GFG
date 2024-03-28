//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int solve(vector<vector<vector<int>>>& graph,int n,int threshold,int i,vector<int>&vis){
        queue<pair<int,int>>q;
        vector<int>mp(n,-1);
        q.push({i,0});
        mp[i] = 0;
        int ct = 0;
        while(!q.empty()){
            int siz = q.size();
            for(int k=0;k<siz;k++){
                pair<int,int>fr = q.front();
                q.pop();
                for(int j=0;j<graph[fr.first].size();j++){
                    vector<int>neigh = graph[fr.first][j];
                    if(fr.second+neigh[1] <= threshold){
                        if(mp[neigh[0]]>0  and mp[neigh[0]] > fr.second+neigh[1]){
                            q.push({neigh[0],fr.second+neigh[1]});
                            mp[neigh[0]] = fr.second+neigh[1];
                        }
                        else if(mp[neigh[0]] == -1){
                            q.push({neigh[0],fr.second+neigh[1]});
                            mp[neigh[0]] = fr.second+neigh[1];
                            ct++;
                        }
                    }
                }
            }
        }
        return ct;
    }
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<vector<int>>>graph(n);
        for(int i=0;i<m;i++){
            //O(m)
            graph[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            graph[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        int city = -1;
        int val = INT_MAX;
        for(int i=0;i<n;i++){
            // O(n * n * n)
            vector<int>vis(n,0);
            vis[0] = 1;
            int c = solve(graph,n,distanceThreshold,i,vis);
            if(val >= c){
                city = i; 
                val = c;
            }
        }
        return city;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends