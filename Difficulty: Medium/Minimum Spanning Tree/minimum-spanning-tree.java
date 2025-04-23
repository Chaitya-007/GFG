//{ Driver Code Starts


import java.io.*;
import java.lang.*;
import java.util.*;

public class Main {
    static BufferedReader br;
    static PrintWriter ot;

    public static void main(String args[]) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        ot = new PrintWriter(System.out);
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            int V = Integer.parseInt(br.readLine().trim());
            int E = Integer.parseInt(br.readLine().trim());
            List<List<int[]>> list = new ArrayList<>();
            for (int i = 0; i < V; i++) list.add(new ArrayList<>());
            for (int i = 0; i < E; i++) {
                String[] s = br.readLine().trim().split(" ");
                int a = Integer.parseInt(s[0]);
                int b = Integer.parseInt(s[1]);
                int c = Integer.parseInt(s[2]);
                list.get(a).add(new int[] {b, c});
                list.get(b).add(new int[] {a, c});
            }
            ot.println(new Solution().spanningTree(V, E, list));

            ot.println("~");
        }
        ot.close();
    }
}
// } Driver Code Ends


// User function Template for Java

class obj
{
    int wt;
    int node;
    int parent;
    
    public obj(int w,int n,int p)
    {
        this.wt = w;
        this.node = n;
        this.parent = p;
    }
    
    public int getWt()
    {
        return wt;
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

class Pair
{
    int v;
    int w;
    
    public Pair(int v,int w)
    {
        this.v = v;
        this.w = w;
    }
    
    public int getV()
    {
        return v;
    }
    
    public int getW()
    {
        return w;
    }
}


class Solution {
    static int spanningTree(int V, int E, List<List<int[]>> adj) {
        // Code Here.
        
        
    //      System.out.println("Debug: adj size = " + adj.size());
    // for(int i = 0; i < adj.size(); i++) {
    //     System.out.println("Debug: adj[" + i + "] size = " + adj.get(i).size());
    //     for(int j = 0; j < adj.get(i).size(); j++) {
    //         int[] arr = adj.get(i).get(j);
    //         System.out.print("Debug: adj[" + i + "][" + j + "] = [");
    //         for(int k = 0; k < arr.length; k++) {
    //             System.out.print(arr[k] + (k < arr.length - 1 ? ", " : ""));
    //         }
    //         System.out.println("]");
    //     }
    // }
        
        List<List<Pair>> adjList = new ArrayList<>();
        
        for(int i = 0; i < V; i++)
        {
            adjList.add(new ArrayList<>());
        }
        
        for (int u = 0; u < V; u++) {
            for (int[] edge : adj.get(u)) {
                int v = edge[0];
                int w = edge[1];
                adjList.get(u).add(new Pair(v, w));
                adjList.get(v).add(new Pair(u, w)); // Assuming undirected graph
            }
        }
        
        Comparator<obj> cmp = (p,q) -> 
        {
            return Integer.compare(p.getWt(),q.getWt());
        };
        
        PriorityQueue<obj> pq = new PriorityQueue<>(cmp);
        
        pq.offer(new obj(0,0,-1));
        
        int sum = 0;
        
        boolean[] vis = new boolean[V];
        
        while(!pq.isEmpty())
        {
            int wt = pq.peek().getWt();
            int node = pq.peek().getNode();
            int parent = pq.peek().getParent();
            pq.poll();
            
            if(vis[node]) continue;
            
            
            // This is when I add it to mst
            vis[node] = true;
            sum += wt;
            
            for(Pair p : adjList.get(node))
            {
                int adjV = p.getV();
                int w = p.getW();
                
                if(!vis[adjV])
                {
                    pq.offer(new obj(w,adjV,node));
                }
            }
        }
        
        
        return sum;
    }
}