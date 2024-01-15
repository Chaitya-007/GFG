//{ Driver Code Starts
import java.util.*;
import java.io.*;

public class GFG {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while(t-- > 0)
        {
            int n = scanner.nextInt();
            int total = scanner.nextInt();
            int[] cost = new int[n];
            for (int i = 0; i < n; i++) {
                cost[i] = scanner.nextInt();
            }
            Solution solution = new Solution();
            int result = solution.max_courses(n, total, cost);
            System.out.println(result);
        }
    }
}

// } Driver Code Ends


//User function Template for Java
class Solution {
    public int maxcost(int ind,int total,int cost[],int dp[][]){
        if(ind==cost.length){
            return 0;
        }
        if(dp[ind][total]!=-1)return dp[ind][total];
        int notpick=maxcost(ind+1,total,cost,dp);
        int pick=Integer.MIN_VALUE;
        if(cost[ind]<=total){ 
            int val=total-cost[ind]+(int)(Math.floor(0.9*cost[ind]));
            pick=1+maxcost(ind+1,val,cost,dp);
        }
        return dp[ind][total]=Math.max(notpick,pick);
    }
    public int max_courses(int n, int total, int[] cost) {
        // code here
        int dp[][]=new int[n][total+1];
        for(int i=0;i<n;i++){
            for(int j=0;j<total+1;j++){
                dp[i][j]=-1;
            }
        }
        return maxcost(0,total,cost,dp);
    }
}

