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
            String ans = obj.preToInfix(s);
            System.out.println(ans);
        
System.out.println("~");
}
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    static String preToInfix(String pre_exp) {
        // code here
        int n = pre_exp.length();
        Stack<String> st = new Stack<String>();
        
        for(int i = n - 1; i >= 0; i--)
        {
            char ch = pre_exp.charAt(i);
            
            if ( ('A' <= ch && ch <= 'Z') || ('a' <= ch && ch <= 'z') || ('0' <= ch && ch <= '9') )
            {
             StringBuilder sb = new StringBuilder("");
             sb.append(ch);
             st.push(sb.toString());
            }
            else
            {
                StringBuilder res = new StringBuilder("");
                StringBuilder t1 = new StringBuilder(st.peek());
                st.pop();
                StringBuilder t2 = new StringBuilder(st.peek());
                st.pop();
                res.append("(");
                res.append(t1.toString());
                res.append(ch);
                res.append(t2.toString());
                res.append(")");
                st.push(res.toString());
            }
        }
        
        return st.peek();
    }
}
