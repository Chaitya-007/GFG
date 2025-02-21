//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t;
        t = sc.nextInt();
        sc.nextLine(); // Consume the newline character

        while (t-- > 0) {
            String line = sc.nextLine();
            String[] tokens = line.split(" ");

            // Create an ArrayList to store the integers
            ArrayList<Integer> array = new ArrayList<>();

            // Parse the tokens into integers and add to the array
            for (String token : tokens) {
                array.add(Integer.parseInt(token));
            }

            // Convert ArrayList to array
            Integer[] arr = new Integer[array.size()];
            array.toArray(arr);

            Solution ob = new Solution();

            // Call totalFruits method and print result
            Integer ans = ob.totalElements(arr);
            System.out.println(ans);

            System.out.println("~");
        }
        sc.close();
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    public static int totalElements(Integer[] arr) {
        // code here
        
        // T.C -> O(N*2)*O(1)
        // S.C -> O(N)
        int n = arr.length;
        
        int maxlen = 0;
        
        for(int i = 0; i < n; i++)
        {
            HashSet<Integer> set = new HashSet<Integer>();
            
            for(int j = i; j < n; j++)
            {
                set.add(arr[j]);
                if(set.size() > 2)
                {
                    break;
                }
                else
                {
                    int len = j - i + 1;
                    maxlen = Math.max(len,maxlen);
                }
            }
        }
        
        return maxlen;
    }
}