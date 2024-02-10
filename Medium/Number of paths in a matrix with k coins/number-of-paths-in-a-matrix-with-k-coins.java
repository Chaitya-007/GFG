//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG
{
    public static void main(String args[])throws IOException
    {
        
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while(t-- > 0)
        {
            
            int  k = Integer.parseInt(read.readLine());
            int  n = Integer.parseInt(read.readLine());
            int arr[][] = new int[n][n];
            String input_line1[] = read.readLine().trim().split("\\s+");
            int c = 0;
            for(int i=0;i<n;i++){
                for(int j = 0;j<n;j++){
                    arr[i][j] = Integer.parseInt(input_line1[c]);
                    c++;
                }
            }
            Solution obj = new Solution();
            System.out.println(obj.numberOfPath(n, k, arr));
        }
    }
}

// } Driver Code Ends


//User function Template for Java

class Solution {
    long count= 0;
    long numberOfPath(int n, int k, int [][]arr) {
        // code here
        
        check(0,0,k,arr,n,0);
        return count;
    }
    
    void check(int i,int j,int k,int arr[][],int n,int sum) {
        if(i>=n||j>=n) {
            return;
        }
        sum+=arr[i][j];
        if(sum>k) {
            return;
        }
        
        if(i ==n-1 && j==n-1 && sum==k) {
            count++;
        }
        check(i+1,j,k,arr,n,sum);
        check(i,j+1,k,arr,n,sum);
    }
}