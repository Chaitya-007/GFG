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
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution {
    
    public static void dfs(int node, int[] vis, ArrayList<ArrayList<Integer>> adjLs)
    {
        vis[node] = 1;
        
        for(Integer it : adjLs.get(node))
        {
            if(vis[it] != 1)
            {
                dfs(it,vis,adjLs);
            }
        }
        
    }
    
    static int numProvinces(ArrayList<ArrayList<Integer>> adj, int V) {
        // code here
        ArrayList<ArrayList<Integer>> adjLs = new ArrayList<>();
        for(int i = 0; i <= V; i++)
        {
            adjLs.add(new ArrayList<Integer>());
        }
        
        for(int i = 0; i < adj.size(); i++)
        {
            for(int j = 0; j < adj.get(i).size(); j++)
            {
                if(i != j && adj.get(i).get(j) == 1)
                {
                    int u = i + 1;
                    int v = j + 1;
                    adjLs.get(u).add(v);
                    adjLs.get(v).add(u);
                }
            }
        }
        
        int[] vis = new int[V + 1];
        Arrays.fill(vis,0);
        int cnt = 0;
        
        for(int node = 1; node <= V; node++)
        {
            if(vis[node] != 1)
            {
                dfs(node,vis,adjLs);
                cnt++;
            }
        }
        
        return cnt;
    }
};