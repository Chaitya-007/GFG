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
            String ans = obj.postToInfix(s);
            System.out.println(ans);
        
System.out.println("~");
}
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    static String postToInfix(String exp) {
        // code here
        Stack<String> st = new Stack<String>();
        
        for(char ch : exp.toCharArray())
        {
            if ( ('A' <= ch && ch <= 'Z') || ('a' <= ch && ch <= 'z' ) || ('0' <= ch && ch <= '9') )
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
                res.append('(');
                res.append(t2);
                res.append(ch);
                res.append(t1);
                res.append(')');
                
                st.push(res.toString());
            }
        }
        
        return st.peek();
    }
}
