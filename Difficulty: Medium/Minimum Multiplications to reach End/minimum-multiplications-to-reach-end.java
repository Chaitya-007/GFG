//{ Driver Code Starts
// Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;

// Position this line where user code will be pasted.

class GFG {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            int n = sc.nextInt();
            int[] a = new int[n];

            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }

            int start = sc.nextInt();
            int end = sc.nextInt();

            Solution ob = new Solution();
            int ans = ob.minimumMultiplications(a, start, end);
            System.out.println(ans);
        
System.out.println("~");
}
    }
}
// } Driver Code Ends


// User function Template for Java

class StepsNum
{
    long steps;
    int num;
    
    public StepsNum(long s,int n)
    {
        this.steps = s;
        this.num = n;
    }
    
    public long getSteps()
    {
        return steps;
    }
    
    public int getNum()
    {
        return num;
    }
}


class Solution {
    
    HashMap<String, Long> dp = new HashMap<>();
    
    public String getString(long start, long end, long cnt)
    {
        String str = String.valueOf(start) + String.valueOf(end) + String.valueOf(cnt);
        return str;
    }
    
    public long fun(long start,long end,long cnt,int[] arr)
    {
        if(start > end)
        {
            return Long.MAX_VALUE;
        }
        
        if(start == end)
        {
            return cnt;
        }
        
        String str = getString(start,end,cnt);
        if(dp.containsKey(str)) return dp.get(str);
        
        long mino = Long.MAX_VALUE;
        
        for(int i = 0; i < arr.length; i++)
        {
            long newStart = (start * (long)arr[i])%100000;
            long path = fun(newStart,end,cnt + 1,arr);
            if(path != Long.MAX_VALUE)
            {
                mino = Math.min(path,mino);
            }
        }
        
         dp.put(str,mino);
         return mino;
    }
    
    int minimumMultiplications(int[] arr, int start, int end) {

        // Your code here
        // long ans = fun((long)start, (long)end, 0, arr);
        // return ans == Long.MAX_VALUE ? -1 : (int)ans;
        
        if(start == end) return 0;
        int mod = (int)1e5;
        
        long[] dist = new long[mod];
        Arrays.fill(dist,Long.MAX_VALUE);
        dist[start] = 0;
        
        Queue<StepsNum> q = new LinkedList<>();
        q.offer(new StepsNum(0,start));
        
        while(!q.isEmpty())
        {
            StepsNum p = q.poll();
            // it's like getting the distance 
            long steps = p.getSteps();
            // it's like getting the node
            int num = p.getNum();
            
           for(int i = 0; i < arr.length; i++)
            {
                // it's like got the adjacent node
                long newNum = (num * (long)arr[i])%100000;
                
                // its like adding the edgewt as 1 every time
                if(steps + 1 < dist[(int)newNum])
                {
                    dist[(int)newNum] = steps + 1;
                
                if(newNum == end)
                {
                    return (int)dist[(int)newNum];
                }
                
                q.offer(new StepsNum(dist[(int)newNum],(int)newNum));
                }
            }
        }
        
        return -1;
        
        
    }
}
