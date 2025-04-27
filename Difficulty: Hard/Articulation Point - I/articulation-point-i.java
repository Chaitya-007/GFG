//{ Driver Code Starts
// Initial Template for Java
import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            String[] s = br.readLine().trim().split(" ");
            int V = Integer.parseInt(s[0]);
            int E = Integer.parseInt(s[1]);
            ArrayList<ArrayList<Integer>>adj = new ArrayList<>();
            for(int i = 0; i < V; i++)
                adj.add(i, new ArrayList<Integer>());
            for(int i = 0; i < E; i++){
                String[] S = br.readLine().trim().split(" ");
                int u = Integer.parseInt(S[0]);
                int v = Integer.parseInt(S[1]);
                adj.get(u).add(v);
                adj.get(v).add(u);
            }
            Solution obj = new Solution();
            ArrayList<Integer>ans = obj.articulationPoints(V, adj);
            for (int i =0 ;i < ans.size (); i++) 
                System.out.print (ans.get (i) + " ");
            System.out.println();
        
System.out.println("~");
}
    }
}

// } Driver Code Ends


class Solution {
    
    int timer = 1;
    
    public void dfs(int node,int parent, boolean[] vis, ArrayList<ArrayList<Integer>> adj,ArrayList<Integer> ans,int[] startTime,int[] lowest)
    {
        vis[node] = true;
        startTime[node] = lowest[node] = timer;
        timer++;
        
        int child = 0;
        
        for(Integer adjNode : adj.get(node))
        {
            
            if(parent == adjNode) continue;
            
            if(!vis[adjNode])
            {
                dfs(adjNode,node,vis,adj,ans,startTime,lowest);
                
                lowest[node] = Math.min(lowest[node],lowest[adjNode]);
                
                
                // this say that it the child lowest is equal or greater than the parent
                // that means => it cannot reach to parent via any other node
                if(lowest[adjNode] >= startTime[node] && parent != -1)
                {
                    ans.set(node,1);
                }
                
                child++;
            }
            else 
            {
                lowest[node] = Math.min(lowest[node],startTime[adjNode]);
            }
        }
        
        if(parent == -1 && child > 1)
        {
            ans.set(node,1);
        }
        
        
      
    }
    
    
    // Function to return Breadth First Traversal of given graph.
    public ArrayList<Integer> articulationPoints(int V,
                                                 ArrayList<ArrayList<Integer>> adj) {
                                                     
                                                     
        // Code here
        
        boolean[] vis = new boolean[V];
        int[] startTime = new int[V];
        int[] lowest = new int[V];
        ArrayList<Integer> ans = new ArrayList<>();
        
        for(int i = 0; i < V; i++)
        {
            ans.add(0);
        }
        
        for(int i = 0; i < V; i++)
        {
            if(!vis[i])
            {
                dfs(i,-1,vis,adj,ans,startTime,lowest);
            }
        }
        
        ArrayList<Integer> result = new ArrayList<>();
        
        for(int i = 0; i < V; i++)
        {
            if(ans.get(i) == 1)
            {
            result.add(i);
                
            }
        }
        
        if(result.size() == 0)
        {
            result.add(-1);
        }
        Collections.sort(result);
        return result;
        
    }
}