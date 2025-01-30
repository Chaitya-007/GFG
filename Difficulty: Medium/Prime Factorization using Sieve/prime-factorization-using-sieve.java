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
            obj.sieve();
            List<Integer> ans = obj.findPrimeFactors(n);
            for (int e : ans) {
                System.out.print(e + " ");
            }
            System.out.println();
        
System.out.println("~");
}
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    // You must implement this function
    static void sieve() {}

    static List<Integer> findPrimeFactors(int N) {
        // code here
        
        List<Integer> list = new ArrayList<Integer>();
        
        int[] prime = new int[N + 1];
        Arrays.fill(prime,1);
        
        prime[0] = 0;
        prime[1] = 0;
        
        for(int i = 2; i*i <= N; i++)
        {
            if(prime[i] == 1)
            {
                for(int j = i*i; j <= N; j = j + i)
                {
                    prime[j] = 0;
                }
            }
        }
        
        for(int i = 2; i * i <= N; i++)
        {
            if(prime[i] == 1)
            {
                if(N%i == 0)
                {
                    
                while(N%i == 0)
                {
                list.add(i);
                    N = N/i;
                }
                }
            }
        }
        
        if(N != 1) list.add(N);
        
        return list;
    }
}
