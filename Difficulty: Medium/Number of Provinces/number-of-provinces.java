//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            int V = Integer.parseInt(read.readLine());
            
            ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
            
            for(int i=0; i<V; i++)
            {
                String S[] = read.readLine().split(" ");
                ArrayList<Integer> temp = new ArrayList<>();
                for(int j=0; j<V; j++)
                    temp.add(Integer.parseInt(S[j]));
                adj.add(temp);
            }

            Solution ob = new Solution();
            System.out.println(ob.numProvinces(adj,V));
        
System.out.println("~");
}
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution {
    
    public static void bfs(int node,List<List<Integer>> list,boolean[] vis)
    {
        Queue<Integer> q = new LinkedList<>();
        
        q.offer(node);
        vis[node] = true;
        
        while(!q.isEmpty())
        {
            int getNode = q.peek();
            q.poll();
            
            for(Integer val : list.get(getNode))
            {
                if(!vis[val])
                {
                    vis[val] = true;
                    q.offer(val);
                }
            }
            
        }
        
    }
    
    static int numProvinces(ArrayList<ArrayList<Integer>> adj, int V) {
        // code here
        List<List<Integer>> list = new ArrayList<>();
        
        for(int i = 0; i <= V; i++)
        {
            list.add(new ArrayList<Integer>());
        }
        
       
        
        for(int i = 0; i < V; i++)
        {
            for(int j = 0; j < V; j++)
            {
                if(i != j && adj.get(i).get(j) == 1)
                {
                    int u = i + 1;
                    int v = j + 1;
                    list.get(u).add(v);
                    list.get(v).add(u);
                }
            }
        }
        
        boolean[] vis = new boolean[V+1];
        
        int cnt = 0;
        
        for(int i = 1; i <= V; i++)
        {
            if(!vis[i])
            {
                cnt++;
                bfs(i,list,vis);
            }
        }
        
        return cnt;
        
    }
};