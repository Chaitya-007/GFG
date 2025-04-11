//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

class DriverClass {
    public static void main(String args[]) throws IOException {

        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String str[] = read.readLine().trim().split(" ");
            int V = Integer.parseInt(str[0]);
            int E = Integer.parseInt(str[1]);

            // ArrayList<ArrayList<Integer>> edges = new ArrayList<>();
            int[][] edges = new int[E][3];

            int i = 0;
            for (i = 0; i < E; i++) {
                String S[] = read.readLine().trim().split(" ");
                int u = Integer.parseInt(S[0]);
                int v = Integer.parseInt(S[1]);
                int w = Integer.parseInt(S[2]);
                // ArrayList<Integer> t1 = new ArrayList<>();
                // t1.add(u);
                // t1.add(v);
                // t1.add(w);
                // edges.add(t1);
                edges[i][0] = u;
                edges[i][1] = v;
                edges[i][2] = w;
            }

            int S = Integer.parseInt(read.readLine());

            Solution ob = new Solution();

            int[] ptr = ob.bellmanFord(V, edges, S);

            for (i = 0; i < ptr.length; i++) System.out.print(ptr[i] + " ");
            System.out.println();
        }
    }
}
// } Driver Code Ends


// User function Template for Java

/*   Function to implement Bellman Ford
 *   edges: 2D array which represents the graph
 *   src: source vertex
 *   V: number of vertices
 */
class Solution {
    static int[] bellmanFord(int V, int[][] edges, int src) {
        // Write your code here
        int[] dis = new int[V];
        Arrays.fill(dis,(int)1e8);
        dis[src] = 0;
        
        for(int t = 0; t < V; t++)
        {
            for(int i = 0; i < edges.length; i++)
            {
                int u = edges[i][0];
                int v = edges[i][1];
                int w = edges[i][2];
                
                if(dis[u] != (int)1e8 && dis[u] + w < dis[v])
                {
                    dis[v] = dis[u] + w;
                }
            }
        }
        
        for(int i = 0; i < edges.length; i++)
        {
                int u = edges[i][0];
                int v = edges[i][1];
                int w = edges[i][2];
                
                if(dis[u] != (int)1e8 && dis[u] + w < dis[v])
                {
                    int[] ans = {-1};
                    return ans;
                }
            
        }
        
        return dis;
    }
}
