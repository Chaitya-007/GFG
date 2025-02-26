//{ Driver Code Starts
import java.io.*;
import java.util.*;

class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            // First array input (arr)
            String[] str1 = br.readLine().trim().split(
                " "); // Read the first line and split by spaces
            int n = str1.length;
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] =
                    Integer.parseInt(str1[i]); // Convert each element to an integer
            }

            // Second array input (dep)
            String[] str2 = br.readLine().trim().split(
                " "); // Read the second line and split by spaces
            int m = str2.length;
            int[] dep = new int[m];
            for (int i = 0; i < m; i++) {
                dep[i] =
                    Integer.parseInt(str2[i]); // Convert each element to an integer
            }

            Solution obj = new Solution();
            System.out.println(obj.findPlatform(arr, dep));
            System.out.println("~");
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    static int findPlatform(int arr[], int dep[]) {
        // add your code here
        
        // T.C -> O(2*N) + O(2*NlogN)
        // S.C -> O(1) // we are distorting the given array
        
        Arrays.sort(arr); // O(NlogN)
        Arrays.sort(dep); // O(NlogN)
        
        int n = arr.length;
        
        int i = 0;
        int j = 0;
        
        int cnt = 0;
        int maxCnt = 0;
        
        while(i < n) // O(2*N)
        {
            if(arr[i] <= dep[j])
            {
                cnt++;
                i++;
            }
            else
            {
                cnt--;
                j++;
            }
            
            maxCnt = Math.max(maxCnt,cnt);
        }
        
        return maxCnt;
    }
}
