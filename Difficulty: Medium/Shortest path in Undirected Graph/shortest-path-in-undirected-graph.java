//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            int n = sc.nextInt();
            int m=sc.nextInt();
            int[][] edge = new int[m][2];
            for(int i=0;i<m;i++){
                edge[i][0]=sc.nextInt();
                edge[i][1]=sc.nextInt();
            }
            int src=sc.nextInt();
            Solution obj = new Solution();
            int res[] = obj.shortestPath(edge,n,m,src);
            for(int i=0;i<n;i++){
                System.out.print(res[i]+" ");
            }
            System.out.println();
        }
    }
}

// } Driver Code Ends


class Solution {
    
    public int[] shortestPath(int[][] edges,int n,int m ,int src) {
        // Code here
            ArrayList<ArrayList<Integer>>adjList = new ArrayList<>();
        for(int i = 0;i<n;i++)
        adjList.add(new ArrayList<>());
        
        for(int i = 0;i<m;i++)
        {
            adjList.get(edges[i][0]).add(edges[i][1]);
            adjList.get(edges[i][1]).add(edges[i][0]);
            
        }
        int[]ans = new int[n];
        Arrays.fill(ans,-1);
        boolean[]visited= new boolean[n];
        Queue<Integer>q = new LinkedList<>();
        visited[src] = true;
        q.add(src);
        ans[src] = 0;
        while(!q.isEmpty())
        {
            int u = q.poll();
            for(int v:adjList.get(u))
            {
                if(visited[v]==false)
                {
                    visited[v] = true;
                    q.add(v);
                    ans[v] = ans[u]+1;
                }
            }
        }
        return ans;
    }
}