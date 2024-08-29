//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main(String[] args) throws IOException
	{
	        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int t =
            Integer.parseInt(br.readLine().trim()); // Inputting the testcases
        while(t-->0)
        {
            int n = Integer.parseInt(br.readLine().trim());
            int a[] = new int[n];
            String inputLine[] = br.readLine().trim().split(" ");
            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(inputLine[i]);
            }
            
            Solution obj = new Solution();
            System.out.println(obj.maxOnes(a, n));
            
        }
	}
}
// } Driver Code Ends


//User function Template for Java


class Solution {

    public static int maxOnes(int a[], int n) {
        // Your code goes here
        int cnt_one = 0;
        for(int num : a)
        {
            if(num == 1)
            {
                cnt_one++;
            }
        }
        
        int maxi = 0;
        int sum = 0;
        
        int[] arr = new int[n];
        
        for(int i = 0; i < n; i++)
        {
            if(a[i] == 1)
            {
                arr[i] = -1;
            }
            else
            {
                arr[i] = 1;
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            sum += arr[i];
            maxi = Math.max(sum,maxi);
            if(sum < 0)
            sum = 0;
        }
        
        return maxi + cnt_one;
    }
}
