//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.math.*;
import java.io.*;

class GFG {
  public static void main(String[] args) throws IOException {
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    while (T-- > 0) {
      int n = sc.nextInt();
      int a[] = new int[n];
      for(int i=0;i<n;i++){
        a[i]=sc.nextInt();
      }
      int q = sc.nextInt();
      int ind[]=new int[q]; 
      for(int i=0;i<q;i++) ind[i]=sc.nextInt();
      Solution obj = new Solution();
      int ans[] = obj.count_NGEs(n,a,q,ind);
      for(int e : ans)
      System.out.print(e+" ");
      System.out.println();
    
System.out.println("~");
}
  }
}

// } Driver Code Ends


//User function Template for Java

class Solution {
  public static int[] count_NGEs(int N, int arr[], int queries, int indices[]) {
    // code here
    Stack<Integer> asc = new Stack<>();
    Stack<Integer> dsc = new Stack<>();
    int[] count = new int[N];
    int[] ans = new int[queries];
    
        for(int i = N - 1; i >= 0; i--)
        {
            while(!asc.isEmpty() && arr[i] >= asc.peek())
            {
                dsc.push(asc.peek());
                asc.pop();
            }
            
            dsc.push(arr[i]);
            
            count[i] = asc.size();
            
            while(!dsc.isEmpty())
            {
                asc.push(dsc.peek());
                dsc.pop();
            }
        }
        
        int i = 0;
        
        for(int val : indices)
        {
            ans[i] = count[val];
            i++;
        }
        
        return ans;
        
     
  }
}
     