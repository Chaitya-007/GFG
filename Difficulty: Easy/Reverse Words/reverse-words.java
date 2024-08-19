//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;
class GFG {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t > 0) {
            String s = sc.next();
            Solution obj = new Solution();
            System.out.println(obj.reverseWords(s));
            t--;
        }
    }
}

// } Driver Code Ends



class Solution 
{
    //Function to reverse words in a given string.
    String reverseWords(String S)
    {
        // code here 
        int n = S.length();
        int i = 0;
        char[] chstr = S.toCharArray();
        // System.out.println(chstr);
        for(; i < n; i++)
        {
            if(S.charAt(i) != '.')
            {
                break;
            }
        }
        
        StringBuilder sb = new StringBuilder();
        String result = "";
        
        for(; i < n; i++)
        {
            if(chstr[i] != '.')
            {
                sb.append(chstr[i]);
            }
            else
            {
                if(sb.length() != 0)
                {
                    sb.reverse();
                    result = result + sb.toString() + '.';
                    sb.setLength(0);
                }
            }
        }
        
        if(sb.length() != 0)
        {
            sb.reverse();
            result += sb.toString();
            sb.setLength(0);
        }
        
        sb.append(result);
        sb.reverse();
        
        return sb.toString();
    }
}