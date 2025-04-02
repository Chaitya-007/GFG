//{ Driver Code Starts
import java.io.*;
import java.util.*;

class Sorting {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int g = 0; g < t; g++) {
            String[] str = (br.readLine()).trim().split(" ");
            int arr[] = new int[str.length];
            for (int i = 0; i < str.length; i++) arr[i] = Integer.parseInt(str[i]);
            System.out.println(new Solution().inversionCount(arr));
            System.out.println("~");
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    // Function to count inversions in the array.
    
    public static int merge(int low, int mid, int high, int arr[])
    {
        int left = low;
        int right = mid + 1;
        List<Integer> list = new ArrayList<>();
        
        int cnt = 0;
        
        while(left <= mid && right <= high)
        {
            if(arr[left] <= arr[right])
            {
                list.add(arr[left]);
                left++;
            }
            else
            {
                cnt += (mid - left + 1);
                list.add(arr[right]);
                right++;
            }
        }
        
        while(left <= mid)
        {
            list.add(arr[left]);
            left++;
        }
        
        while(right <= high)
        {
            list.add(arr[right]);
            right++;
        }
        
        for(int i = low; i <= high; i++)
        {
            arr[i] = list.get(i - low);
        }
        
        return cnt;
    }
    
    
    public static int msort(int low, int high, int arr[])
    {
        int cnt = 0;
        
        if(low >= high) return cnt;
        
        int mid = (low + high) >> 1;
        cnt += msort(low, mid, arr);
        cnt+= msort(mid+1, high, arr);
        cnt += merge(low, mid, high, arr);
        return cnt;
    }
    
    
    static int inversionCount(int arr[]) {
        // Your Code Here
        int n = arr.length;
        
        return msort(0, n - 1, arr);
        
    }
}