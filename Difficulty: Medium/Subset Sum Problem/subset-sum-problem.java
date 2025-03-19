//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {

            String input_line[] = read.readLine().trim().split("\\s+");
            int N = input_line.length;
            int arr[] = new int[N];
            for (int i = 0; i < N; i++) arr[i] = Integer.parseInt(input_line[i]);
            int sum = Integer.parseInt(read.readLine());

            Solution ob = new Solution();
            if (ob.isSubsetSum(arr, sum))
                System.out.println("true");
            else
                System.out.println("false");

            System.out.println("~");
        }
    }
}

// } Driver Code Ends


class Solution {
    
    public static boolean fun(int ind, int[] arr, int target)
    {
        if(target == 0) return true;
        if(ind == 0)
        {
            return arr[ind] == target;
        }
        
        boolean notpick = fun(ind - 1, arr, target);
        boolean pick = false;
        
        if(arr[ind] <= target)
        {
            pick = fun(ind - 1, arr, target - arr[ind]);
        }
        
        return pick | notpick;
    }
    
    public static boolean funMemo(int ind, int[] arr, int target, boolean[][] dp)
    {
        if(target == 0) return true;
        if(ind == 0)
        {
            return arr[ind] == target;
        }
        
        if(dp[ind][target]) return dp[ind][target];
        
        boolean notpick = funMemo(ind - 1, arr, target, dp);
        boolean pick = false;
        
        if(arr[ind] <= target)
        {
            pick = funMemo(ind - 1, arr, target - arr[ind],dp);
        }
        
        return dp[ind][target] = pick | notpick;
    }

    static Boolean isSubsetSum(int arr[], int sum) {
        // code here
        int n = arr.length;
        // return fun(n-1,arr,sum);
        boolean[][] dp = new boolean[n][sum+1];
        
        // return funMemo(n-1,arr,sum,dp);
        
        for(int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }
        
        for(int target = 1; target <= sum; target++)
        {
            dp[0][target] = (arr[0] == target);
        }
        
        for(int ind = 1; ind < n; ind++)
        {
            for(int target = 1; target <= sum; target++)
            {
            
                boolean notpick = dp[ind - 1][target];
                boolean pick = false;
                
                if(arr[ind] <= target)
                {
                    pick = dp[ind - 1][target - arr[ind]];
                }
                
                    
                 dp[ind][target] = pick | notpick;
                
                
                
            }
        }
        
        return dp[n-1][sum];
        
    }
}