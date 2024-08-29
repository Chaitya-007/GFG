//{ Driver Code Starts
//Initial Template for Java
import java.io.*;
import java.util.*;

class GFG
{
    public static void main(String args[])throws IOException
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0)
        {
            int N=sc.nextInt();
			
            Solution ob = new Solution();
            int ans  = ob.sumOfDivisors(N);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends


//User function Template for Java
class Solution{
    
    public static int sumDiv(int N)
    {
         int sum = 0;
        for(int i = 1; i <= Math.sqrt(N); i++)
        {
            if(N%i == 0)
            {
                sum += i;
                
                if(N/i != i)
                {
                    sum += (N/i);
                }
            }
        }
        
        return sum;
    }
    static int sumOfDivisors(int N){
        // code here
        int sum = 0;
        for(int i = 1; i <= Math.sqrt(N); i++)
        {
            if(N%i == 0)
            {
                sum += sumDiv(i);
                
                if(N/i != i)
                {
                    sum += sumDiv((N/i));
                }
            }
        }
        
        return sum;
    }
}