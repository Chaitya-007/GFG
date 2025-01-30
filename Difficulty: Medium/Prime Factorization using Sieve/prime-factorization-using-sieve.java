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
        // if(N < 2) return 0;
        List<Integer> list = new ArrayList<Integer>();
        int[] prime = new int[N + 1];
        for(int i = 0; i <= N; i++)
        {
            prime[i] = i;
        }
        
        for(int i = 2; i*i <= N; i++)
        {
            if(prime[i] == i)
            {
                for(int j = i * i; j <= N; j = j + i)
                {
                    // Very importatnt codition, it check whether
                    if(prime[j] == j)
                    {
                    prime[j] = i;
                        
                    }
                }
            }
        }
        
        // for(int val : prime) System.out.print(val + " ");
        
        while(N != 1)
        {
            list.add(prime[N]);
            N = N/prime[N];
        }
        
        return list;
        
    }
}
