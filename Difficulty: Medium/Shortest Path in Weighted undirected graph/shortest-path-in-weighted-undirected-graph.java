//{ Driver Code Starts
import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br;
    static PrintWriter ot;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        ot = new PrintWriter(System.out);

        int t = Integer.parseInt(br.readLine().trim());

        while (t-- > 0) {
            String s[] = br.readLine().trim().split(" ");
            int n = Integer.parseInt(s[0]), m = Integer.parseInt(s[1]);
            int edges[][] = new int[m][3];
            for (int i = 0; i < m; i++) {
                s = br.readLine().trim().split(" ");
                edges[i][0] = Integer.parseInt(s[0]);
                edges[i][1] = Integer.parseInt(s[1]);
                edges[i][2] = Integer.parseInt(s[2]);
            }

            List<Integer> list = new Solution().shortestPath(n, m, edges);

            ot.println(list.get(0));
            if (list.get(0) != -1 && !check(list, edges)) ot.println(-1);
        }
        ot.close();
    }

    static boolean check(List<Integer> list, int edges[][]) {
        Set<Integer> hs = new HashSet<>();
        Map<Integer, Map<Integer, Integer>> hm = new HashMap<>();
        for (int i = 1; i < list.size(); i++) hs.add(list.get(i));
        for (int x[] : edges) {
            if (hs.contains(x[0]) || hs.contains(x[1])) {
                if (!hm.containsKey(x[0])) hm.put(x[0], new HashMap<>());
                if (!hm.containsKey(x[1])) hm.put(x[1], new HashMap<>());
                hm.get(x[0]).put(x[1], x[2]);
                hm.get(x[1]).put(x[0], x[2]);
            }
        }
        int sum = 0;
        for (int i = 1; i < list.size() - 1; i++) {
            if (!hm.containsKey(list.get(i)) ||
                !hm.get(list.get(i)).containsKey(list.get(i + 1)))
                return false;
            sum += hm.get(list.get(i)).get(list.get(i + 1));
        }
        return sum == list.get(0);
    }
}

// } Driver Code Ends


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
    
    public NodeAndDis(int d, int n)
    {
        this.node = n;
        this.dis = d;
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
    public List<Integer> shortestPath(int n, int m, int edges[][]) {
        //  Code Here.
        
        List<List<Pair>> adj = new ArrayList<>();
        
        for(int i = 0; i <= n; i++)
        {
            adj.add(new ArrayList<>());
        }
        
        for(int i = 0; i < m; i++)
        {
            adj.get(edges[i][0]).add(new Pair(edges[i][1],edges[i][2]));
            adj.get(edges[i][1]).add(new Pair(edges[i][0],edges[i][2]));
        }
        
        Comparator<NodeAndDis> cmp = (p,q) ->
        {
            if(p.getDis() == q.getDis())
            {
                return Integer.compare(p.getNode(),q.getNode());
            }
            
            return Integer.compare(p.getDis(),q.getDis());
        };
        
        
        PriorityQueue<NodeAndDis> pq = new PriorityQueue<>(cmp);
        
        pq.offer(new NodeAndDis(0,1));
        int[] dis = new int[n+1];
        Arrays.fill(dis,Integer.MAX_VALUE);
        dis[1] = 0;
        
        int[] parent = new int[n+1];
        for(int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
        
        while(!pq.isEmpty())
        {
            int node = pq.peek().getNode();
            int distance = pq.peek().getDis();
            pq.poll();
            
            for(Pair p : adj.get(node))
            {
                int adjv = p.getV();
                int edgeWt = p.getW();
                
                if(distance + edgeWt < dis[adjv])
                {
                    dis[adjv] = distance + edgeWt;
                    parent[adjv] = node;
                    pq.offer(new NodeAndDis(dis[adjv],adjv));
                }
            }
        }
        
        if(dis[n] == Integer.MAX_VALUE) 
        {
            
            return new ArrayList<>(Arrays.asList(-1));
        }
        
        List<Integer> ans = new ArrayList<>();
        
        int wt = 0;
        int node = n;
        
        while(parent[node] != node)
        {
            ans.add(node);
            node = parent[node];
        }
        
        ans.add(node);
        ans.add(dis[n]);
        
        Collections.reverse(ans);
        
        return ans;
        
        
        
    }
}