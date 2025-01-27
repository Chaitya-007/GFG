//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int N = sc.nextInt();

            Solution ob = new Solution();
            int ans = ob.setBit(N);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends


// User function Template for Java
class Solution {
    static int setBit(int n) {
        // code here
        for(int i = 0; i < 31; i++)
        {
            if( (n & (1<<i)) == 0)
            {
                n = (n | (1<<i));
                break;
            }
        }
        
        return n;
    }
}