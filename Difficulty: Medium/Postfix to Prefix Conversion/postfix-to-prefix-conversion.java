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
            sc.nextLine();
            String s = sc.next();
            Solution obj = new Solution();
            String ans = obj.postToPre(s);
            System.out.println(ans);
        
System.out.println("~");
}
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    static String postToPre(String post_exp) {
        // code here
        Stack<String> st = new Stack<String>();
        for(char ch : post_exp.toCharArray())
        {
            if ( ('A' <= ch && ch <= 'Z') || ('a' <= ch && ch <= 'z') || ('0' <= ch && ch <= '9') )
            {
                StringBuilder sb = new StringBuilder("");
                sb.append(ch);
                st.push(sb.toString());
            }
            else
            {
                StringBuilder t1 = new StringBuilder(st.peek());
                st.pop();
                StringBuilder t2 = new StringBuilder(st.peek());
                st.pop();
                
                StringBuilder res = new StringBuilder("");
                res.append(ch);
                res.append(t2.toString());
                res.append(t1.toString());
                st.push(res.toString());
            }
        }
        
        return st.peek();
    }
}
