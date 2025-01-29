//{ Driver Code Starts


import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            int N = Integer.parseInt(br.readLine().trim());
            Solution ob = new Solution();
            int[] ans = ob.AllPrimeFactors(N);
            for(int i = 0; i < ans.length; i++)
                System.out.print(ans[i] + " ");
            System.out.println();
        }
    }
}

// } Driver Code Ends




class Solution
{
    public int[] AllPrimeFactors(int N)
    {
        // code here
        List<Integer> list = new ArrayList<Integer>();
        // int cnt = 0;
        
        for(int i = 1; i <= Math.sqrt(N); i++)
        {
            if(N%i == 0)
            {
                list.add(i);
                if(N/i != i)
                {
                    list.add(N/i);
                }
            }
        }
        
        List<Integer> result = new ArrayList<Integer>();
        
        for(Integer val : list)
        {
            int cnt = 0;
            for(int i = 1; i <= Math.sqrt(val); i++)
            {
                if(val%i == 0)
                {
                    cnt++;
                    if(val/i != i)
                    {
                        cnt++;
                    }
                }
                
                if(cnt > 2)
                {
                    break;
                }
            }
            
            if(cnt == 2)
            {
                result.add(val);
            }
        }
        
        int[] arr = new int[result.size()];
        for(int i = 0; i < arr.length; i++)
        {
            arr[i] = result.get(i);
        }
        
        return arr;
    }
}