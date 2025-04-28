//{ Driver Code Starts
// Initial Template for Java
import java.util.*;


// } Driver Code Ends

// User function Template for Java

class Solution {
    // Function to find number of strongly connected components in the graph.
    
    public void dfs(int node,boolean[] vis,ArrayList<ArrayList<Integer>> adj, Stack<Integer> st)
    {
        vis[node] = true;
        
        for(Integer adjNode : adj.get(node))
        {
            if(!vis[adjNode])
            {
                dfs(adjNode,vis,adj,st);
            }
        }
        
        st.push(node);
    }
    
    public void dfscc(int node,boolean[] vis,ArrayList<ArrayList<Integer>> adj)
    {
        vis[node] = true;
        
        for(Integer adjNode : adj.get(node))
        {
            if(!vis[adjNode])
            {
                dfscc(adjNode,vis,adj);
            }
        }
        
        
    }
    
    
    public int kosaraju(ArrayList<ArrayList<Integer>> adj) {
        // code here
        Stack<Integer> st = new Stack<>();
        int v = adj.size();
        boolean[] vis = new boolean[v];
        
        // Sort the nodes in order
        for(int i = 0; i < v; i++)
        {
            if(!vis[i])
            {
                
            dfs(i,vis,adj,st);
            }
            
        }
        
        
        // Reverse The Graph
        ArrayList<ArrayList<Integer>> reverseList = new ArrayList<>();
        
        for(int i = 0; i < v; i++)
        {
            reverseList.add(new ArrayList<>());
        }
        
        for(int i = 0; i < v; i++)
        {
            for(Integer adjNode : adj.get(i))
            {
                reverseList.get(adjNode).add(i);
            }
        }
        
        // Do a dfs again
        
        vis = new boolean[v];
        int cnt = 0;
        while(!st.isEmpty())
        {
            int node = st.peek();
            st.pop();
            if(!vis[node])
            {
                cnt++;
                dfscc(node,vis,reverseList);
                
            }
        }
        
        return cnt;
        
    }
}


//{ Driver Code Starts.

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int V = sc.nextInt();
            int E = sc.nextInt();

            ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
            for (int i = 0; i < V; i++) {
                adj.add(new ArrayList<>());
            }

            for (int i = 0; i < E; i++) {
                int u = sc.nextInt();
                int v = sc.nextInt();
                adj.get(u).add(v);
            }

            Solution obj = new Solution();
            System.out.println(obj.kosaraju(adj));

            System.out.println("~");
        }
        sc.close();
    }
}

// } Driver Code Ends