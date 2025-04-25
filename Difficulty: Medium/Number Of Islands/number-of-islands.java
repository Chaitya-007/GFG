//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;


// } Driver Code Ends

// User function Template for Java

class Disjoint
{
    List<Integer> parent = new ArrayList<>();
    List<Integer> size = new ArrayList<>();

    public Disjoint(int n)
    {
        for(int i = 0; i < n; i++)
        {
            parent.add(i);
            size.add(1);
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

        if(size.get(ulp_u) < size.get(ulp_v))
        {
            parent.set(ulp_u,ulp_v);
            size.set(ulp_v, size.get(ulp_u) + size.get(ulp_v));
        }
        else
        {
            parent.set(ulp_v,ulp_u);
            size.set(ulp_u, size.get(ulp_v) + size.get(ulp_u));
        }
    }
}

class Solution {

    public List<Integer> numOfIslands(int rows, int cols, int[][] operators) {
        // Your code here
        Disjoint ds = new Disjoint(rows*cols);
    
        int[][] vis = new int[rows][cols];
        
        List<Integer> ans = new ArrayList<>();
        
        int cnt = 0;
        
        int[] delRow = {-1,0,1,0};
        int[] delCol = {0,1,0,-1};
        
        for(int i = 0; i < operators.length; i++)
        {
            int r = operators[i][0];
            int c = operators[i][1];
            
            if(vis[r][c] == 1) 
            {
                ans.add(cnt);
                continue;
            }
            
            int node = r*cols + c;
            vis[r][c] = 1;
            cnt++;
            
            for(int j = 0; j < 4; j++)
            {
                int nrow = r + delRow[j];
                int ncol = c + delCol[j];
                int currnode = (nrow * cols) + ncol;
                
                if(nrow >= 0 && nrow < rows && ncol >= 0 && ncol < cols && vis[nrow][ncol] == 1 && ds.findUpar(node) != ds.findUpar(currnode))
                {
                    cnt--;
                    ds.unionBySize(node,currnode);
                }
            }
            
            ans.add(cnt);
        }
        
        return ans;
    }
}


//{ Driver Code Starts.

class GFG {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int  k= sc.nextInt();
            int[][] a = new int[k][2];
            for(int i=0;i<k;i++){
            
                a[i][0] = sc.nextInt();
                a[i][1] = sc.nextInt();
            }
            
            Solution obj = new Solution();
            List<Integer> ans = obj.numOfIslands(n,m,a);
           
            for(int i:ans){
                System.out.print(i+" ");
            }
            System.out.println();
        
System.out.println("~");
}
    }
}

// } Driver Code Ends