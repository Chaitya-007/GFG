//{ Driver Code Starts
//Initial Template for Java

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
      List<String> ans = obj.generateBinaryStrings(n);
      for(String s : ans) System.out.print(s+" ");
      System.out.println();
    
System.out.println("~");
}
  }
}

// } Driver Code Ends


//User function Template for Java

class Solution {
    
    public static void fun(int ind, int prev, StringBuilder sb, List<String> ans, int n)
    {
        if(ind == n)
        {
            if(sb.length() != 0)
            {
                ans.add(new String(sb.toString()));
            }
            
            return;
        }
        
        for(int i = 0; i <= 1; i++)
        {
            if(i == 1 && prev == 1)
            {
                
            }
            else
            {
                sb.append((char)(i + '0'));
                fun(ind + 1, i, sb, ans, n);
                sb.deleteCharAt(sb.length() - 1);
            }
        }
    }
    
  public static List<String> generateBinaryStrings(int n) {
    // code here
    List<String> ans = new ArrayList<>();
    StringBuilder sb = new StringBuilder("");
    fun(0,0,sb,ans,n);
    return ans;

  }
}
     
     