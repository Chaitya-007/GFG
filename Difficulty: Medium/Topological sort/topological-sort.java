//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int V = sc.nextInt();
            int E = sc.nextInt();
            ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
            for (int i = 0; i < V; i++) adj.add(i, new ArrayList<Integer>());

            int[][] edges = new int[E][2];
            for (int i = 0; i < E; i++) {
                edges[i][0] = sc.nextInt();
                edges[i][1] = sc.nextInt();
                adj.get(edges[i][0]).add(edges[i][1]);
            }

            ArrayList<Integer> res = new Solution().topoSort(V, edges);

            if (check(adj, V, res) == true)
                System.out.println("true");
            else
                System.out.println("false");
            System.out.println("~");
        }
    }

    static boolean check(ArrayList<ArrayList<Integer>> adj, int V,
                         ArrayList<Integer> res) {

        if (V != res.size()) return false;

        int[] map = new int[V];
        for (int i = 0; i < V; i++) {
            map[res.get(i)] = i;
        }
        for (int i = 0; i < V; i++) {
            for (int v : adj.get(i)) {
                if (map[i] > map[v]) return false;
            }
        }
        return true;
    }
}

// } Driver Code Ends


class Solution {
    
    public static void dfs(int node, boolean[] vis,List<List<Integer>> adj,Stack<Integer> st)
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
        return;
    }
    
    
    
    
    public static ArrayList<Integer> topoSort(int V, int[][] edges) {
        // code here
        
        // DFS
        // List<List<Integer>> adj = new ArrayList<>();
        // for(int i = 0; i < V; i++)
        // {
        //     adj.add(new ArrayList<>());
        // }
        
        // for(int i = 0; i < edges.length; i++)
        // {
        //     int u = edges[i][0];
        //     int v = edges[i][1];
        //     adj.get(u).add(v);
        // }
        
        // boolean[] vis = new boolean[V];
        // Stack<Integer> st = new Stack<>();
        
        // for(int i = 0; i < V; i++)
        // {
        //     if(!vis[i])
        //     {
        //         dfs(i,vis,adj,st);
        //     }
        // }
        
        // ArrayList<Integer> ans = new ArrayList<>();
        
        // while(!st.isEmpty())
        // {
        //     ans.add(st.peek());
        //     st.pop();
        // }
        
        // return ans;
        
        
        // BFS
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
        
        ArrayList<Integer> result = new ArrayList<>();
        int[] indegree = new int[V];
        
        for(int i = 0; i < adj.size(); i++)
        {
            for(Integer adjNode : adj.get(i))
            {
                indegree[adjNode] = indegree[adjNode] + 1;
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
        
        while(!q.isEmpty())
        {
            int node = q.peek();
            result.add(node);
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
        
        return result;
        
        
        
    }
}