//{ Driver Code Starts
import java.io.*;
import java.util.*;

class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine().trim()); // Read number of test cases

        // Loop for each test case
        while (t-- > 0) {
            String line = read.readLine().trim(); // Read the array input
            String[] numsStr = line.split(" ");   // Split the input string by spaces
            int[] nums =
                new int[numsStr.length]; // Convert string array to integer array
            for (int i = 0; i < numsStr.length; i++) {
                nums[i] = Integer.parseInt(numsStr[i]);
            }

            int target = Integer.parseInt(read.readLine().trim()); // Read target sum

            Solution ob = new Solution(); // Create an object of Solution class
            System.out.println(
                ob.perfectSum(nums, target)); // Call perfectSum and print the result
            System.out.println("~");          // Call perfectSum and print the result
        }
    }
}
// } Driver Code Ends


class Solution {
    
    
    public int fun(int ind, int target, int[] nums, int[][] dp)
    {
        
        if(ind == nums.length)
        {
        if(target == 0) return 1;
        else return 0;
            
        }
        
        if(dp[ind][target] != -1) return dp[ind][target];
        
        int notpick = fun(ind + 1, target, nums, dp);
        int pick = 0;
        
        if(nums[ind] <= target)
        {
            pick = fun(ind + 1, target - nums[ind], nums, dp);
        }
        
        return dp[ind][target] = pick + notpick;
    }
    
    // Function to calculate the number of subsets with a given sum
    public int perfectSum(int[] nums, int target) {
        // code here
        
        int n = nums.length;
        
        
        int[][] dp = new int[n][target + 1];
        
        for(int i = 0; i < n; i++)
        {
            Arrays.fill(dp[i],-1);
        }
        return fun(0,target,nums,dp);
        
        
        
    }
}