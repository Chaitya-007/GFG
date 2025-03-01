//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;
import java.lang.*;

class GFG{
    public static void main(String args[])throws IOException
    {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while(t-- > 0){
            int N = Integer.parseInt(read.readLine());
            String input_line[] = read.readLine().trim().split("\\s+");
            int pages[]= new int[N];
            for(int i = 0; i < N; i++)
                pages[i] = Integer.parseInt(input_line[i]);
            int C = Integer.parseInt(read.readLine());

            Solution ob = new Solution();
            System.out.println(ob.pageFaults(N, C, pages));
        
System.out.println("~");
}
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution{
    static int pageFaults(int N, int C, int pages[]){
        // code here
        HashMap<Integer, Integer> map = new HashMap<>();
        
        int pf = 0;
        
        
        
       
        
        for(int i = 0; i < N; i++)
        {
            if(map.containsKey(pages[i]))
            {
                map.put(pages[i],i);
            }
            else
            {
                if(map.size() != C)
                {
                    map.put(pages[i],i);
                }
                else
                {
                    
                // int ind = i - 1;
                // HashSet<Integer> hset = new HashSet<Integer>();
                // while(ind >= 0 && hset.size() != C)
                // {
                //     hset.add(pages[ind]);
                //     ind--;
                // }
                
                // ind++;
                
                // int ele = pages[ind];
                // map.remove(ele);
                // map.put(pages[i],i);
                
                int mino = N;
                int ele = -1;
                for(Map.Entry<Integer, Integer> e : map.entrySet())
                {
                    if(mino > e.getValue())
                    {
                        ele = e.getKey();
                        mino = e.getValue();
                    }
                }
                
                map.remove(ele);
                map.put(pages[i],i);
                
                }
                
                pf++;
                
            }
            
        }
        
        return pf;
    }
}