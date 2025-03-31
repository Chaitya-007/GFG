//{ Driver Code Starts
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());

        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());      // Number of vertices
            String[] arrInput = br.readLine().trim().split(" "); // Input for edges

            List<int[]> edges = new ArrayList<>();
            for (int i = 0; i < arrInput.length; i += 2) {
                int u = Integer.parseInt(arrInput[i]);
                int v = Integer.parseInt(arrInput[i + 1]);
                edges.add(new int[] {u, v});
            }

            int m = Integer.parseInt(br.readLine().trim()); // Number of colors

            Solution sol = new Solution();
            System.out.println(sol.graphColoring(n, edges, m) ? "true" : "false");
            System.out.println("~");
        }
    }
}

// } Driver Code Ends


class Solution {
    
    public boolean isPossible(int node, int[] color, int col, List<List<Integer>> adjList)
    {
        
            for(int val : adjList.get(node))
            {
              if(color[val] == col) return false;
                
            }
        
        return true;
    }
    
    public boolean fun(int node, int m, int v, List<List<Integer>> adjList, int[] color)
    {
        if(node == v)
        {
            return true;
        }
        
        for(int col = 1; col <= m; col++)
        {
            if(isPossible(node, color, col, adjList))
            {
                
            color[node] = col;
            
            if(fun(node + 1, m , v, adjList, color))
            {
                return true;
            }
            
            color[node] = 0;
            
            }
        }
        
        return false;
    }
    
        
    
    boolean graphColoring(int v, List<int[]> edges, int m) {
        // code here
        
        
        List<List<Integer>> adjList = new ArrayList<>();
        
        for(int i = 0; i < v; i++)
        {
            adjList.add(new ArrayList<>());
        }
        
        for(int[] arr : edges)
        {
            int a = arr[0];
            int b = arr[1];
            
            adjList.get(a).add(b);
            adjList.get(b).add(a);
        }
        
        int[] color = new int[v];
        return fun(0,m,v,adjList,color);
    }
}