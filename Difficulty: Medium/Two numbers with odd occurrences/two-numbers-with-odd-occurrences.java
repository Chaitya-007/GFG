//{ Driver Code Starts
//Initial Template for Java
import java.io.*;
import java.util.*;

class GFG{
    public static void main(String args[])throws IOException
    {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while(t-- > 0)
        {
            int N = Integer.parseInt(read.readLine());
            String input_line[] = read.readLine().trim().split("\\s+");
            int Arr[]= new int[N];
            for(int i = 0; i < N; i++)
                Arr[i] = Integer.parseInt(input_line[i]);
            
            Solution ob = new Solution();
            int[] ans = ob.twoOddNum(Arr,N);
            for(int i = 0; i < ans.length; i++)
            {
                System.out.print(ans[i] + " ");
            }
            System.out.println();
        
System.out.println("~");
}
    }
}
// } Driver Code Ends


//User function Template for Java

//User function Template for Java
class Solution
{
    public int[] twoOddNum(int Arr[], int N)
    {
        // code here
        long xor = 0;
        
        for(int val : Arr)
        {
            xor ^= val;
        }
        
        int rightMost = ((int)(xor & (xor - 1))) ^ (int)xor;
        
        int b1 = 0;
        int b2 = 0;
        
        for(int val : Arr)
        {
            if((rightMost & val) != 0)
            {
                b1 ^= val;
            }
            else
            {
                b2 ^= val;
            }
        }
        
        int[] arr = new int[2];
        
        if(b1 > b2)
        {
            arr[0] = b1;
            arr[1] = b2;
        }
        else
        {
            arr[0] = b2;
            arr[1] = b1;
        }
        
        return arr;
    }
}