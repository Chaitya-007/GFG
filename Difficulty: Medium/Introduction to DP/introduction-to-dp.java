//{ Driver Code Starts
// Initial Template for Java

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
            Solution obj = new Solution();
            long topDownans = obj.topDown(n);
            long bottomUpans = obj.bottomUp(n);
            if (topDownans != bottomUpans)
                System.out.println(-1);
            else
                System.out.println(topDownans);
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    
    static final int mod = 1000000007;
    
    public static long fib(int n, long[] dp)
    {
        if(n <= 1)
        {
            return n;
        }
        
        if(dp[n] != -1)
        {
            return dp[n];
        }
        
        return dp[n] = (fib(n-1,dp) + fib(n-2,dp))%mod;
    }

    static long topDown(int n) {
        // code here
        long[] dp = new long[n+1];
        Arrays.fill(dp,-1);
        
        long result = fib(n,dp);
        
        return result;
        
    }

    static long bottomUp(int n) {
        // code here
        long prev = 1;
        long prev2 = 0;
        
        for(long i = 2; i <= n; i++)
        {
            long curr = (prev + prev2)%mod;
            prev2 = prev;
            prev = curr;
        }
        
        return prev;
    }
}
