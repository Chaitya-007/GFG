//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
   void DjskstrasAlgo(int src, unordered_map<int, list<pair<int,int>>>& adj, vector<int>& dist) {
        dist[src] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, src});
        
        while(!pq.empty()) {
            auto node = pq.top().second;
            auto nodeDist = pq.top().first;
            pq.pop();
            
            for(auto nbr: adj[node]) {
                if(nbr.second + nodeDist < dist[nbr.first]) {
                    dist[nbr.first] = nodeDist + nbr.second;
                    pq.push({dist[nbr.first], nbr.first});
                }
            }
        }
        
        return;
    }
  
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        // Your code here
        
        unordered_map<int, list<pair<int,int>>> adj;
        for(int i=0; i<m; i++) {
            auto u = edges[i][0];
            auto v = edges[i][1];
            auto w = edges[i][2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        int minCities = INT_MAX, ans = 0;
        for(int i=0; i<n; i++) {
            vector<int> dist(n, 1e9);
            
            DjskstrasAlgo(i, adj, dist);
            
            int cityCnt = 0;
            for(int j=0; j<n; j++) {
                // cout << dist[j] << " ";
                if(dist[j] <= distanceThreshold && dist[j] != 0) {
                    cityCnt++;
                }
            }
            
            if(cityCnt <= minCities) {
                minCities = cityCnt;
                ans = i;
            }
        }
        
        return ans;
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