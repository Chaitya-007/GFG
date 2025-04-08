//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int[][] edge = new int[m][3];
            for (int i = 0; i < m; i++) {
                edge[i][0] = sc.nextInt();
                edge[i][1] = sc.nextInt();
                edge[i][2] = sc.nextInt();
            }
            Solution obj = new Solution();
            int res[] = obj.shortestPath(n, m, edge);
            for (int i = 0; i < n; i++) {
                System.out.print(res[i] + " ");
            }
            System.out.println();

            System.out.println("~");
        }
    }
}
// } Driver Code Ends


// User function Template for Java

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

class NodeAndDis
{
    int node;
    int dis;
    
    public NodeAndDis(int node,int dis)
    {
        this.node = node;
        this.dis = dis;
    }
    
    public int getNode()
    {
        return node;
    }
    
    public int getDis()
    {
        return dis;
    }
}


class Solution {

    public int[] shortestPath(int V, int E, int[][] edges) {
        // Code here
        // int vertices = edges.length;
        List<List<Pair>> adj = new ArrayList<>();
        
        for(int i = 0; i < V; i++)
        {
            adj.add(new ArrayList<>());
        }
        
        for(int i = 0; i < E; i++)
        {
            adj.get(edges[i][0]).add(new Pair(edges[i][1],edges[i][2]));
        }
        
        int[] dis = new int[V];
        Arrays.fill(dis, Integer.MAX_VALUE);
        dis[0] = 0;
         
        Queue<NodeAndDis> q = new LinkedList<>();
        q.offer(new NodeAndDis(0,0));
        
        while(!q.isEmpty())
        {
            int node = q.peek().getNode();
            int distance = q.peek().getDis();
            q.poll();
            
            for(Pair adjNode : adj.get(node))
            {
                int adjv = adjNode.getV();
                int adjw = adjNode.getW();
                
                if(dis[adjv] > (adjw + distance))
                {
                    dis[adjv] = adjw + distance;
                    q.offer(new NodeAndDis(adjv,(adjw + distance)));
                }
            }
        }
        
        for(int i = 0; i < V; i++)
        {
            if(dis[i] == Integer.MAX_VALUE)
            {
                dis[i] = -1;
            }
        }
        
        return dis;
    }
}