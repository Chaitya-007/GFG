//{ Driver Code Starts
import java.util.Scanner;

class SquartRoot {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t > 0) {
            int a = sc.nextInt();
            Solution obj = new Solution();
            System.out.println(obj.floorSqrt(a));
            t--;
        }
    }
}
// } Driver Code Ends


/*You are required to complete
this function*/

// Function to find square root
// x: element to find square root
class Solution {
    
    public int square(int val)
    {
        return (val*val);
    }
    
    int floorSqrt(int n) {
        // Your code here
        int l = 0;
        int r = n;
        while(l <= r)
        {
            int mid = (l + r)/2;
            int sq = square(mid);
            
            if(sq <= n)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        
        return r;
    }
}
