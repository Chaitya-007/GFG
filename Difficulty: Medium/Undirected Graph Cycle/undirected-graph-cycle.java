//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();
        while (tc-- > 0) {
            int V = sc.nextInt();
            int E = sc.nextInt();
            int[][] edges = new int[E][2];
            for (int i = 0; i < E; i++) {
                edges[i][0] = sc.nextInt();
                edges[i][1] = sc.nextInt();
            }

            Solution obj = new Solution();
            boolean ans = obj.isCycle(V, edges);
            System.out.println(ans ? "true" : "false");
            System.out.println("~");
        }
        sc.close();
    }
}

// } Driver Code Ends


class Solution {
    
    public boolean dfs(int node, int parent, List<List<Integer>> adj, boolean[] vis)
    {
        vis[node] = true;
        
        for(Integer adjNode : adj.get(node))
        {
            if(!vis[adjNode])
            {
                if(dfs(adjNode,node,adj,vis))
                {
                    return true;
                }
            }
            else
            {
                if(adjNode != parent)
                {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    public boolean isCycle(int V, int[][] edges) {
        // Code here
        List<List<Integer>> adj = new ArrayList<>();
        for(int i = 0; i < V; i++)
        {
            adj.add(new ArrayList<>());
        }
        
        for(int i = 0; i < edges.length; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj.get(u).add(v);
            adj.get(v).add(u);
        }
        
        boolean[] vis = new boolean[V];
        
        for(int i = 0; i < V; i++)
        {
            if(!vis[i])
            {
                if(dfs(i,-1,adj,vis)) return true;
            }
        }
        
        return false;
    }
}