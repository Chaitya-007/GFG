//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.lang.*;
import java.util.*;


// } Driver Code Ends
// User function Template for Java

class Solution {
    
    public int fun(int ind, int k, int[] arr,int[] dp)
    {
        if(ind == 0)
        {
            return 0;
        }
        
        if(dp[ind] != -1) return dp[ind];
        
        int result = Integer.MAX_VALUE;
        
        for(int val = 1; val <= k; val++)
        {
            int energy = Integer.MAX_VALUE;
            
            if(ind - val >= 0)
            {
                energy = Math.abs(arr[ind] - arr[ind-val]) + fun(ind - val,k,arr,dp);
            }
            
            result = Math.min(energy,result);
        }
        
        return dp[ind] = result;
    }
    
    public int minimizeCost(int k, int arr[]) {
        // code here
        int n = arr.length;
        int[] dp = new int[n];
        Arrays.fill(dp,-1);
        return fun(n-1,k,arr,dp);
    }
}


//{ Driver Code Starts.

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int k = Integer.parseInt(br.readLine());
            String line = br.readLine();
            String[] tokens = line.split(" ");

            // Create an ArrayList to store the integers
            ArrayList<Integer> array = new ArrayList<>();

            // Parse the tokens into integers and add to the array
            for (String token : tokens) {
                array.add(Integer.parseInt(token));
            }

            int[] arr = new int[array.size()];
            int idx = 0;
            for (int i : array) arr[idx++] = i;
            Solution obj = new Solution();
            int res = obj.minimizeCost(k, arr);

            System.out.println(res);

            System.out.println("~");
        }
    }
}
// } Driver Code Ends