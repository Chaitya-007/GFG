//{ Driver Code Starts
//Initial template for JAVA

import java.lang.*;
import java.io.*;
import java.util.*;


// } Driver Code Ends
//User function template for JAVA

class Solution
{
    //Function to check if a string is Pangram or not.
    public static boolean checkPangram  (String s) {
        // your code here
        HashSet<Character> set = new HashSet<Character>();
        for(int i = 0; i < s.length(); i++)
        {
            if(set.size() > 26)
            {
                return true;
            }
            
            if (( 'a' <= s.charAt(i) && s.charAt(i) <= 'z') || ( 'A' <= s.charAt(i) && s.charAt(i) <= 'Z') )
            {
                char ch = s.charAt(i);
               if(( 'a' <= s.charAt(i) && s.charAt(i) <= 'z'))
               {
                    ch = (char)(s.charAt(i) - 32);
               }
                set.add(ch);
            }
            
            
        }
        
        // System.out.println(set.size());
        
        if(set.size() == 26)
        {
            return true;
        }
        
        return false;
    }
}

//{ Driver Code Starts.

class GFG
 {
	public static void main (String[] args) throws IOException
	 {
	  BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	  int t=Integer.parseInt(br.readLine());
	  while(t-->0)
	  {
	    String s=br.readLine().trim();
	    
	    System.out.println(new Solution().checkPangram (s)==true?1:0);
	  }
	  
	 }
}
// } Driver Code Ends