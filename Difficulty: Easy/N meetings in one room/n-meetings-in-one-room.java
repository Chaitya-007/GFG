//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());

        while (t-- > 0) {
            String line1 = br.readLine();
            String[] a1 = line1.trim().split("\\s+");
            int n = a1.length;
            int a[] = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(a1[i]);
            }

            String line2 = br.readLine();
            String[] a2 = line2.trim().split("\\s+");
            n = a2.length;
            int b[] = new int[n];
            for (int i = 0; i < n; i++) {
                b[i] = Integer.parseInt(a2[i]);
            }

            int ans = new Solution().maxMeetings(a, b);
            System.out.println(ans);
            System.out.println("~");
        }
    }
}

// } Driver Code Ends



class Pair<K,V>
{
    private K key;
    private V value;
    
    Pair(K key, V value)
    {
        this.key = key;
        this.value = value;
    }
    
    public K getKey()
    {
        return key;
    }
    
    public V getValue()
    {
        return value;
    }
}

class Solution {
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    public int maxMeetings(int start[], int end[]) {
        // add your code here
        
        List<Pair<Integer, Integer> > list = new ArrayList<>();
        
        int n = start.length;
        
        for(int i = 0; i < n; i++)
        {
            list.add(new Pair<>(start[i], end[i]));
        }
        
        Comparator<Pair<Integer, Integer> > comp = (p1,p2) -> 
        {
          return Integer.compare(p1.getValue(), p2.getValue());  
        };
        
        Collections.sort(list, comp);
        
        int cnt = 1;
        
        for(int i = 1, j = 0; i < n; i++)
        {
            if(list.get(i).getKey() > list.get(j).getValue())
            // if(start[i] > end[j])
            {
                j = i;
                cnt++;
            }
        }
        
        return cnt;
    }
}
