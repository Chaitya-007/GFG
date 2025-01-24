//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GfG {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            String s = sc.next();
            int k = sc.nextInt();
            System.out.println(new Solution().countSubstr(s, k));

            System.out.println("~");
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    
    int kthMost(String s, int k)
    {
        int l = 0;
        int r = 0;
        int cnt = 0;
        int n = s.length();
        HashMap<Character, Integer> map = new HashMap<Character, Integer>();
        
        while(r < n)
        {
            map.put(s.charAt(r), map.getOrDefault(s.charAt(r),0) + 1);
            
            if(map.size() > k)
            {
                while(map.size() > k)
                {
                    map.put(s.charAt(l), map.get(s.charAt(l)) - 1);
                    if(map.get(s.charAt(l)) == 0)
                    {
                        map.remove(s.charAt(l));
                    }
                    l++;
                }
            }
            
                int len = r - l + 1;
                cnt+=len;
            r++;
        }
        
        return cnt;
    }
    
    int countSubstr(String s, int k) {
        // your code here
        
        return kthMost(s,k) - kthMost(s,k-1);
    }
}