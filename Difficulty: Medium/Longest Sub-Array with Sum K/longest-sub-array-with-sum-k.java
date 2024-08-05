//{ Driver Code Starts
//Initial Template for Java

/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;


class Array {
    
    // Driver code
	public static void main (String[] args) throws IOException{
		// Taking input using buffered reader
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int testcases = Integer.parseInt(br.readLine());
		
		// looping through all testcases
		while(testcases-- > 0){
		    String line = br.readLine();
		    String[] element = line.trim().split("\\s+");
		    int sizeOfArray = Integer.parseInt(element[0]);
		    int K = Integer.parseInt(element[1]);
		    
		    int arr [] = new int[sizeOfArray];
		    
		    line = br.readLine();
		    String[] elements = line.trim().split("\\s+");
		    for(int i = 0;i<sizeOfArray;i++){
		        arr[i] = Integer.parseInt(elements[i]);
		    }
		    
		    Solution obj = new Solution();
		    int res = obj.lenOfLongSubarr(arr, sizeOfArray, K);
		    
		    System.out.println(res);
		}
	}
}



// } Driver Code Ends


//User function Template for Java

class Solution{
    
   
    // Function for finding maximum and value pair
    public static int lenOfLongSubarr (int A[], int N, int K) {
        //Complete the function
        Map<Integer, Integer> mp = new HashMap<Integer, Integer>();
        
        int sum = 0;
        int maxlen = 0;
        
        for(int i = 0; i < N; i++)
        {
            sum += A[i];
            
            if(sum == K)
            {
                maxlen = Math.max(maxlen,i + 1);
            }
            
            int rem = sum - K;
            
            if(mp.containsKey(rem))
            {
                int len = i - mp.get(rem);
                maxlen = Math.max(maxlen,len);
            }
            
            if(!mp.containsKey(sum))
            {
                mp.put(sum, i);
            }
        }
        
        return maxlen;
    }
    
    
}


