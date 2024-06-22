//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;
import java.util.regex.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String S = read.readLine();
            Solution ob = new Solution();
            System.out.println(ob.ExtractNumber(S));
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    long ExtractNumber(String sentence) {
        // code here
         int n = sentence.length();
        long max = 0,curr = 0;
        int i = 0;
        boolean containsNine;
    
        while (i < n) {
            char c = sentence.charAt(i);
            if (Character.isDigit(c)) {
                curr = 0;
                containsNine = false;
                while (i < n && Character.isDigit(sentence.charAt(i))) {
                    if (sentence.charAt(i) == '9') {
                        containsNine = true;
                    }
                    curr = curr * 10 + (sentence.charAt(i) - '0');
                    i++;
                }
                if (!containsNine) {
                    max = Math.max(max, curr);
                }
            } else {
                i++;
            }
        }
        return max==0?-1:max;
    }
}