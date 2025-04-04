//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;


// } Driver Code Ends
//User function Template for Java

class Solution{
    
    public static int nearestPower(int num)
    {
        int pow = (int)(Math.log(num)/Math.log(2));
        return pow;
    }
    
    //Function to return sum of count of set bits in the integers from 1 to n.
    public static int countSetBits(int n){
    
        // Your code here
        if(n == 0)
        {
            return 0;
        }
        int x = nearestPower(n);
        int stBits = (1<<(x-1))*x;
        int nextBits = (n - (1<<x) + 1);
        return stBits + nextBits + countSetBits(n - (1<<x));
        
        
    }
}

//{ Driver Code Starts.

// Driver code
class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();//testcases
		int x, n;
		while(t-->0) {
	        n = sc.nextInt();//input n

		    Solution obj = new Solution();

		    System.out.println(obj.countSetBits(n));//calling countSetBits() method
		
System.out.println("~");
}
	}
}

// } Driver Code Ends