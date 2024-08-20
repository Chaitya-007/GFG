//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.lang.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int N = sc.nextInt();
            int[] arr = new int[N];
            for (int i = 0; i < N; i++) {
                arr[i] = sc.nextInt();
            }
            Solution obj = new Solution();
            ArrayList<Integer> ans = obj.longestIncreasingSubsequence(N, arr);
            for (int i = 0; i < ans.size(); i++) {
                System.out.print(ans.get(i) + " ");
            }
            System.out.println();
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    public ArrayList<Integer> longestIncreasingSubsequence(int n, int arr[]) {
        // Code here
         int[] dp = new int[n];
        Arrays.fill(dp,1);
        
        int[] hash = new int[n];
        int maxi = 1;
        int lastIndex = 0;
        
        for(int i = 0; i < n; i++)
        {
            hash[i] = i;
            for(int prev = 0; prev < i; prev++)
            {
                if(arr[prev] < arr[i] && 1 + dp[prev] > dp[i])
                {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            
            if(dp[i] > maxi)
            {
                maxi = dp[i];
                lastIndex = i;
            }
        }
        
        ArrayList<Integer> list = new ArrayList<Integer>();
        list.add(arr[lastIndex]);
        
        while(hash[lastIndex] != lastIndex)
        {
            lastIndex = hash[lastIndex];
            list.add(arr[lastIndex]);
        }
        
        Collections.reverse(list);
        return list;
    }
}
