//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

class iPair {
    int first, second;

    iPair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}

class DriverClass {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String str[] = read.readLine().trim().split(" ");
            int V = Integer.parseInt(str[0]);
            int E = Integer.parseInt(str[1]);

            ArrayList<ArrayList<iPair>> adj = new ArrayList<ArrayList<iPair>>();
            for (int i = 0; i < V; i++) {
                adj.add(new ArrayList<iPair>());
            }

            int i = 0;
            while (i++ < E) {
                String S[] = read.readLine().trim().split(" ");
                int u = Integer.parseInt(S[0]);
                int v = Integer.parseInt(S[1]);
                int w = Integer.parseInt(S[2]);
                iPair t1 = new iPair(v, w);
                iPair t2 = new iPair(u, w);
                adj.get(u).add(t1);
                adj.get(v).add(t2);
            }

            int src = Integer.parseInt(read.readLine());

            Solution ob = new Solution();

            ArrayList<Integer> res = ob.dijkstra(adj, src);

            for (i = 0; i < V; i++) System.out.print(res.get(i) + " ");
            System.out.println();

            System.out.println("~");
        }
    }
}
// } Driver Code Ends


/*
class iPair {
    int first, second;

    iPair(int first, int second) {
        this.first = first;
        this.second = second;
    }
    
}
*/


class Pair
{
    int dis;
    int node;
    
    public Pair(int d,int n)
    {
        this.dis = d;
        this.node = n;
    }
    
    public int getDis()
    {
        return dis;
    }
    
    public int getNode()
    {
        return node;
    }
}


// User function Template for Java
class Solution {
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    ArrayList<Integer> dijkstra(ArrayList<ArrayList<iPair>> adj, int src) {
        // Write your code here
        
        
        Comparator < Pair > cmp = (p,q) ->
        {
            if(p.getDis() == q.getDis())
            {
                return Integer.compare(p.getNode(),q.getNode());
            }
            
            return Integer.compare(p.getDis(),q.getDis());
        };
        // Min heap
        PriorityQueue<Pair> pq = new PriorityQueue<>(cmp);
        
        int v = adj.size();
    
        
        int[] dis = new int[v];
        
        Arrays.fill(dis,Integer.MAX_VALUE);
        dis[src] = 0;
        pq.offer(new Pair(0,src));
        
        while(!pq.isEmpty())
        {
            int node = pq.peek().getNode();
            int distance = pq.peek().getDis();
            pq.poll();
            
            for(iPair adjNode : adj.get(node))
            {
                int adjV = adjNode.first;
                int edgeWeight = adjNode.second;
                
                if(distance + edgeWeight < dis[adjV])
                {
                    dis[adjV] = distance + edgeWeight;
                    pq.offer(new Pair(dis[adjV],adjV));
                }
            }
        }
        
        ArrayList<Integer> ans = new ArrayList<>();
        for(int val : dis)
        {
            ans.add(val);
        }
        
        return ans;
        
        
    }
}