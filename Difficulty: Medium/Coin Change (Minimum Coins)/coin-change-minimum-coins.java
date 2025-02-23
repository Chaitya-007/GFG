//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.lang.*;
import java.util.*;


// } Driver Code Ends
class Solution {
        
    public int fun(int ind,int coins[], int sum)
    {
        
        if(ind == 0)
        {
            if(sum%coins[0] == 0)
            {
                return (sum/coins[0]);
            }
            else
            {
                return (int)(1e9);
            }
        }
        
        int notpick = fun(ind - 1,coins,sum);
        int pick = Integer.MAX_VALUE;
        
        if(coins[ind] <= sum)
        {
            pick = 1 + fun(ind,coins,sum - coins[ind]);
        }
        
        
      return Math.min(pick,notpick);
        
    }
    
     public int funmemo(int ind,int coins[], int sum,int[][] dp)
    {
        // if(sum == 0) return 0;
        if(ind == 0)
        {
            if(sum%coins[0] == 0)
            {
                return (sum/coins[0]);
            }
            else
            {
                return (int)(1e9);
            }
        }
        
        if(dp[ind][sum] != -1) return dp[ind][sum];
        
        int notpick = funmemo(ind - 1,coins,sum,dp);
        // int pick = Integer.MAX_VALUE;
        int pick = Integer.MAX_VALUE;
        
        if(coins[ind] <= sum)
        {
            pick = 1 + funmemo(ind,coins,sum - coins[ind],dp);
        }
        
        
      return dp[ind][sum] = Math.min(pick,notpick);
        
    }

    public int minCoins(int coins[], int sum) {
        // Your code goes here
        int n = coins.length;
        
    //   int ans = fun(n-1,coins,sum);
    //   if(ans == 1e9) return -1;
    //   return ans;
       
    //   int[][] dp = new int[n][sum+1];
       
    //   for(int i = 0; i < n; i++)
    //   {
    //       Arrays.fill(dp[i],-1);
    //   }
    
       
    //   int ans = funmemo(n-1,coins,sum,dp);
    //   if(ans >= 1e9) return -1;
    //   int[][] dp = new int[n][sum+1];
       
    //   for(int i = 0; i < n; i++)
    //   {
    //       Arrays.fill(dp[i],0);
    //   }
    
     
        
    //     for(int j = 0; j <= sum; j++)
    //     {
             
    //         if(j%coins[0] == 0)
    //         {
    //             dp[0][j] = (j/coins[0]);
    //         }
    //         else
    //         {
    //             dp[0][j] = (int)(1e9);
    //         }
    //     }
        
    //     for(int ind = 1; ind < n; ind++)
    //     {
    //         for(int j = 0; j <= sum; j++)
    //         {
    //     int notpick = dp[ind - 1][j];
    //     // int pick = Integer.MAX_VALUE;
    //     int pick = Integer.MAX_VALUE;
        
    //     if(coins[ind] <= j)
    //     {
    //         pick = 1 + dp[ind][j - coins[ind]];
    //     }
         
    //      dp[ind][j] = Math.min(pick,notpick);
                
    //         }
    //     }
    
    if(coins[0] == 0 && sum > 0)
    {
        return -1;
    }
        
        int[] prev = new int[sum+1];
        int[] curr = new int[sum+1];
        
        for(int j = 0; j <= sum; j++)
        {
            
              if(j%coins[0] == 0)
            {
                prev[j] = (j/coins[0]);
            }
            else
            {
                prev[j] = (int)(1e9);
            }
        }
        
        for(int ind = 1; ind < n; ind++)
        {
            for(int j = 0; j <= sum; j++)
            {
        int notpick = prev[j];
        // int pick = Integer.MAX_VALUE;
        int pick = Integer.MAX_VALUE;
        
        if(coins[ind] <= j)
        {
            pick = 1 + curr[j - coins[ind]];
        }
         
         curr[j] = Math.min(pick,notpick);
                
            }
            
            int[] temp = prev;
            prev = curr;
            curr = temp;
        }
       int ans = prev[sum];
       
       if (ans >= 1e9) return -1;
       return ans;
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
            int res = obj.minCoins(arr, k);

            System.out.println(res);

            System.out.println("~");
        }
    }
}

// } Driver Code Ends