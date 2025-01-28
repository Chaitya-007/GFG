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
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        
        for(int val : Arr)
        {
            map.put(val, map.getOrDefault(val,0) + 1);
        }
        
        int[] arr = new int[2];
        int ind = 0;
        
        for(Map.Entry<Integer, Integer> e : map.entrySet())
        {
            if ( (e.getValue() & 1) == 1)
            {
                arr[ind] = e.getKey();
                ind++;
            }
        }
        
        // Arrays.sort(arr, Collections.reverseOrder());
        if(arr[0] < arr[1])
        {
            int temp = arr[0];
            arr[0] = arr[1];
            arr[1] = temp;
        }
        
        return arr;
    }
}