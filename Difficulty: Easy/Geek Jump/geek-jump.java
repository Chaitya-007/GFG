//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG{
    public static void main(String args[]) throws IOException{
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while(t-->0){
            int N=sc.nextInt();
            int []arr=new int[N];
            for(int i=0;i<N;i++){
                arr[i]=sc.nextInt();
                
            }
            Solution obj=new Solution();
            int res=obj.minimumEnergy(arr,N);
            System.out.println(res);
            
        
System.out.println("~");
}
    }
}


// } Driver Code Ends


//User function Template for Java

class Solution{
    
    
    public int fun(int ind,int[] arr,int[] dp)
    {
        if(ind == 0)
        {
            return 0;
        }
        
        if(dp[ind] != -1) return dp[ind];
        
        int right = Integer.MAX_VALUE;
        int left = Integer.MAX_VALUE;
        
        if(ind - 1 >= 0)
        {
            left = Math.abs(arr[ind] - arr[ind-1]) + fun(ind - 1, arr,dp);
        }
        
        if(ind - 2 >= 0)
        {
            right = Math.abs(arr[ind] - arr[ind-2]) + fun(ind - 2, arr,dp);
        }
        
        return dp[ind] = Math.min(left,right);
    }
    
    
    public int minimumEnergy(int arr[],int N){
        //code here
        int[] dp = new int[N+1];
        Arrays.fill(dp,-1);
        return fun(N-1,arr,dp);
    }
}