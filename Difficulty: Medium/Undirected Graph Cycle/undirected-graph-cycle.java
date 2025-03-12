//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            String[] s = br.readLine().trim().split(" ");
            int V = Integer.parseInt(s[0]);
            int E = Integer.parseInt(s[1]);
            ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
            for (int i = 0; i < V; i++) adj.add(i, new ArrayList<Integer>());
            for (int i = 0; i < E; i++) {
                String[] S = br.readLine().trim().split(" ");
                int u = Integer.parseInt(S[0]);
                int v = Integer.parseInt(S[1]);
                adj.get(u).add(v);
                adj.get(v).add(u);
            }
            Solution obj = new Solution();
            boolean ans = obj.isCycle(adj);
            if (ans)
                System.out.println("1");
            else
                System.out.println("0");

            System.out.println("~");
        }
    }
}
// } Driver Code Ends

class Pair
{
    int node;
    int parent;
    
    public Pair(int node_, int parent_)
    {
        this.node = node_;
        this.parent = parent_;
    }
    
    public int getNode()
    {
        return node;
    }
    
    public int getParent()
    {
        return parent;
    }
}

class Solution {
    // Function to detect cycle in an undirected graph.
    
    public boolean bfs(int node, ArrayList<ArrayList<Integer>> adj, boolean[] vis)
    {
        Queue<Pair> q = new LinkedList<>();
        
        q.offer(new Pair(node,-1));
        vis[node] = true;
        
        while(!q.isEmpty())
        {
            int element = q.peek().getNode();
            int parent = q.peek().getParent();
            q.poll();
            
            for(Integer val : adj.get(element))
            {
                if(!vis[val])
                {
                    vis[val] = true;
                    q.offer(new Pair(val,element));
                }
                else if(val != parent)
                {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    
    public boolean isCycle(ArrayList<ArrayList<Integer>> adj) {
        // Code here
        
        int v = adj.size();
        boolean[] vis = new boolean[v];
        
        for(int i = 0; i < v; i++)
        {
            if(!vis[i])
            {
                if(bfs(i,adj,vis)) return true;
            }
        }
        
        return false;
    }
}