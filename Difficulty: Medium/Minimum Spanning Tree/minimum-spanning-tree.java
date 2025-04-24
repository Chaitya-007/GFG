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


class Disjoint
{
    List<Integer> size = new ArrayList<>();
    List<Integer> parent = new ArrayList<>();
    
    public Disjoint(int n)
    {
        for(int i = 0; i < n; i++)
        {
            size.add(1);
            parent.add(i);
        }
    }
    
    public int findUpar(int node)
    {
        if(node == parent.get(node))
        {
            return node;
        }
        
        int updPar = findUpar(parent.get(node));
        parent.set(node,updPar);
        return updPar;
    }
    
    public void unionBySize(int u,int v)
    {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        
        if(ulp_u == ulp_v) return;
        if(size.get(ulp_u) < size.get(ulp_v))
        {
            parent.set(ulp_u,ulp_v);
            size.set( ulp_v, size.get(ulp_v) + size.get(ulp_u) );
        }
        else
        {
            parent.set(ulp_v,ulp_u);
            size.set( ulp_u, size.get(ulp_u) + size.get(ulp_v) );
        }
    }
}

class CustomNode
{
    int u;
    int v;
    int w;
    
    public CustomNode(int w,int u,int v)
    {
        this.u = u;
        this.v = v;
        this.w = w;
    }
    
    public int getU()
    {
        return u;
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
        
        Disjoint ds = new Disjoint(V);
        int sum = 0;
        List<CustomNode> list = new ArrayList<>();
        
        for(int u = 0; u < V; u++)
        {
            for(int[] edge : adj.get(u))
            {
                int v = edge[0];
                int w = edge[1];
                
                list.add(new CustomNode(w,u,v));
            }
        }
        
        
        Comparator<CustomNode> cmp = (p,q) -> 
        {
          return Integer.compare(p.getW(),q.getW());  
        };
        
        Collections.sort(list,cmp);
        
        for(CustomNode p : list)
        {
            int u = p.getU();
            int v = p.getV();
            int w = p.getW();
            
            if(ds.findUpar(u) == ds.findUpar(v))
            {
                continue;
            }
            else 
            {
                ds.unionBySize(u,v);
                sum += w;
            }
        }
        
        return sum;
    }
}