//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;
class GfG
{
    public static void main(String args[])
        {
            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
            while(t-->0)
                {
                    int n = sc.nextInt();
                    int Arr[] = new int[n];
                    for(int i = 0;i<n;i++)
                        Arr[i] = sc.nextInt();
                    Solution ob = new Solution();
                    System.out.println(ob.maxSumIS(Arr,n));
                }
        }
}    
// } Driver Code Ends


//User function Template for Java

class Solution
{
public int maxSumIS(int arr[], int n) {
        int[] dp = new int[n];
        int[] hash = new int[n];
        // Initialize dp array with the values of the input array arr
        for (int i = 0; i < n; i++) {
            dp[i] = arr[i];
            hash[i] = -1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j] && dp[i] < dp[j] + arr[i]) {
                    dp[i] = dp[j] + arr[i];
                    hash[i] = j;
                }
            }
        }
        // int maxValueInd = 0;
        int maxValue = 0;
        for (int i = 0; i < n; i++) {
            if (maxValue < dp[i]) {
                maxValue = dp[i];
                // maxValueInd = i;
            }
        }
        // int ans = 0;
        // while (maxValueInd != -1) {
        //     ans += arr[maxValueInd];
        //     maxValueInd = hash[maxValueInd];
        // }
        return maxValue;
    }  
}