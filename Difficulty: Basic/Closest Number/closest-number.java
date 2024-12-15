//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            int N = Integer.parseInt(read.readLine());
            int M = Integer.parseInt(read.readLine());

            Solution ob = new Solution();
            System.out.println(ob.closestNumber(N, M));

            System.out.println("~");
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    static int closestNumber(int n, int m) {
        // code here
        if(n > 0)
        {
            int rem = n%Math.abs(m);
            int next_rem = Math.abs(m) - rem;
            
            if(rem == next_rem)
            {
                return n + next_rem;
            }
            else if(rem < next_rem)
            {
                return n - rem;
            }
            return n + next_rem;
        }
        else if(n < 0)
        {
            int rem = Math.abs(n)%Math.abs(m);
            int next_rem = Math.abs(m) - rem;
            
            if(rem == next_rem)
            {
                return n - rem;
            }
            else if(rem < next_rem)
            {
                return n + rem;
            }
            return n - next_rem;
            
        }
        
        return n;
    }
};