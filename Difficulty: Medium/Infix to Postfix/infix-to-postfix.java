//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

class GFG {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            System.out.println(new Solution().infixToPostfix(br.readLine().trim()));

            System.out.println("~");
        }
    }
}
// } Driver Code Ends


class Solution {
    // Function to convert an infix expression to a postfix expression.
    
    public static int priority(char ch)
    {
        if(ch == '^') return 3;
        else if(ch == '*' || ch == '/') return 2;
        else if(ch == '-' || ch == '+') return 1;
        return -1;
    }
    
    
    public static String infixToPostfix(String s) {
        // Your code here
        
        int n = s.length();
        Stack<Character> st = new Stack<Character>();
        StringBuilder sb = new StringBuilder("");
        
        for(char ch : s.toCharArray())
        {
            if ( ('A' <= ch && ch <= 'Z') || ('a' <= ch && ch <= 'z') || ('0' <= ch && ch <= '9') )
            {
                sb.append(ch);
            }
            else if(ch == '(')
            {
                st.push(ch);
            }
            else if(ch == ')')
            {
                while(!st.isEmpty() && st.peek() != '(')
                {
                    sb.append(st.peek());
                    st.pop();
                }
                
                st.pop();
            }
            else
            {
                while(!st.isEmpty() && priority(ch) <= priority(st.peek()))
                {
                    sb.append(st.peek());
                    st.pop();
                }
                
                st.push(ch);
            }
        }
        
        while(!st.isEmpty())
        {
            sb.append(st.peek());
            st.pop();
        }
        
        return sb.toString();
    }
}