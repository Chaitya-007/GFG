//{ Driver Code Starts
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
            boolean ans = obj.isCyclic(V, edges);
            System.out.println(ans ? "true" : "false");
        }
        sc.close();
    }
}
// } Driver Code Ends


class Solution {
    public boolean isCyclic(int V, int[][] edges) {
        // code here
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
        }
        
        int[] indegree = new int[V];
        
        for(int i = 0; i < adj.size(); i++)
        {
            for(Integer adjNode : adj.get(i))
            {
                indegree[adjNode] += 1;
            }
        }
        
        Queue<Integer> q = new LinkedList<>();
        
        for(int i = 0; i < V; i++)
        {
            if(indegree[i] == 0)
            {
                q.offer(i);
            }
        }
        
        List<Integer> ans = new ArrayList<>();
        
        while(!q.isEmpty())
        {
            int node = q.peek();
            ans.add(node);
            q.poll();
            
            for(Integer adjNode : adj.get(node))
            {
                if(indegree[adjNode] > 0)
                {
                    indegree[adjNode] -= 1;
                    if(indegree[adjNode] == 0)
                    {
                        q.offer(adjNode);
                    }
                }
            }
        }
        
        
        if(ans.size() == V) return false;
        return true;
    }
}