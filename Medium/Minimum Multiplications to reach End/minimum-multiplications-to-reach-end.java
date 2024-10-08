//{ Driver Code Starts
// Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;

// Position this line where user code will be pasted.

class GFG {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            int n = sc.nextInt();
            int[] a = new int[n];

            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }

            int start = sc.nextInt();
            int end = sc.nextInt();

            Solution ob = new Solution();
            int ans = ob.minimumMultiplications(a, start, end);
            System.out.println(ans);
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    int minimumMultiplications(int[] arr, int start, int end) {

        // Your code here
        if(start==end) return 0;
        Queue<Pair> que = new LinkedList<>();
        int vis_ited[] = new int[100000];
        que.add(new Pair(0,start));
        
        while(que.size()>0){
            Pair p = que.remove();
            int steps = p.a;
            int num = p.b;
            
            for(int i=0; i<arr.length; i++){
                long temp = arr[i]*num % 100000;
                int ns = (int)temp;
                if(ns==end) return steps+1;
                if(vis_ited[ns]==0){
                    que.add(new Pair(steps+1,ns));
                    vis_ited[ns] = 1;
                }
            }
        }
        
        return -1;
    }
}

class Pair{
    int a;
    int b;
    Pair(int a, int b){
        this.a = a;
        this.b = b;
    }
    
}
