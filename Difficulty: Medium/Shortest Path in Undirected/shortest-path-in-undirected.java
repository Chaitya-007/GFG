//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
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
                adj.get(v).add(u); // Since the graph is undirected
            }

            int src = sc.nextInt();

            Solution obj = new Solution();
            int[] res = obj.shortestPath(adj, src);

            for (int i = 0; i < res.length; i++) {
                System.out.print(res[i] + " ");
            }
            System.out.println();
            System.out.println("~");
        }
    }
}

// } Driver Code Ends

class Pair
{
    int node;
    int distance;
    
    public Pair(int n, int dist)
    {
        this.node = n;
        this.distance = dist;
    }
    
    public int getNode()
    {
        return node;
    }
    
    public int getDistance()
    {
        return distance;
    }
}


class Solution {
    // Function to find the shortest path from a source node to all other nodes
    public int[] shortestPath(ArrayList<ArrayList<Integer>> adj, int src) {
        // code here
        int v = adj.size();
        int[] dis = new int[v];
        Arrays.fill(dis,-1);
        
        Queue<Integer> q = new LinkedList<>();
        q.offer(src);
        
        dis[src] = 0;
        
        while(!q.isEmpty())
        {
            int node = q.peek();
            q.poll();
            
            for(Integer adjNode : adj.get(node))
            {
                //
                if(dis[adjNode] == -1) // if not visited then only visit
                {
                    dis[adjNode] = dis[node] + 1;
                    q.offer(adjNode);
                }
              
            }
        }
        
        
        return dis;
    }
}
