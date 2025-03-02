//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

class Job {
    int id, profit, deadline;

    Job(int x, int y, int z) {
        this.id = x;
        this.deadline = y;
        this.profit = z;
    }
}

class GfG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());
        while (t-- > 0) {
            String[] jobIDStrings = sc.nextLine().split(" ");
            String[] deadlineStrings = sc.nextLine().split(" ");
            String[] profitStrings = sc.nextLine().split(" ");

            // Convert the input strings to integer arrays
            int[] jobIDs = new int[jobIDStrings.length];
            int[] deadlines = new int[deadlineStrings.length];
            int[] profits = new int[profitStrings.length];

            for (int i = 0; i < jobIDStrings.length; i++) {
                jobIDs[i] = Integer.parseInt(jobIDStrings[i]);
                deadlines[i] = Integer.parseInt(deadlineStrings[i]);
                profits[i] = Integer.parseInt(profitStrings[i]);
            }
            Solution obj = new Solution();
            ArrayList<Integer> ans = obj.JobSequencing(jobIDs, deadlines, profits);
            System.out.println(ans.get(0) + " " + ans.get(1));
            System.out.println("~");
        }
    }
}
// } Driver Code Ends


class Pair<K, V>
{
    private K profit;
    private V dedline;
    
    Pair(K profit, V dedline)
    {
        this.profit = profit;
        this.dedline = dedline;
    }
    
    public K getProfit()
    {
        return profit;
    }
    
    public V getDeadline()
    {
        return dedline;
    }
}


class Disjoint
{
    int[] parent;
    
    public Disjoint(int n)
    {
        parent = new int[n+1];
        for(int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    
    public int findPar(int x)
    {
        if(x == parent[x])
        {
            return x;
        }
        
        return parent[x] = findPar(parent[x]);
    }
    
    public void union(int x, int y)
    {
        parent[x] = y;
    }
    
}

class Solution {

    public ArrayList<Integer> JobSequencing(int[] id, int[] deadline, int[] profit) {
        // code here..
        
        // T.C -> o(NlogN) + O(N * maxDeadline)
        // S.C -> O(N)
        
        List<Pair<Integer, Integer> > list = new ArrayList<>();
        int n = id.length;
        
        int maxo = 0;
        
        for(int val : deadline)
        {
            maxo = Math.max(maxo,val);
        }
        
        // int[] res = new int[maxo+1];
        // Arrays.fill(res,0);
        
        Disjoint ds = new Disjoint(maxo);
        
        
        for(int i = 0; i < n; i++)
        {
            list.add(new Pair<>(profit[i],deadline[i]));
        }
        
        Comparator<Pair<Integer, Integer>> comp = (p1,p2) -> 
        {
          return Integer.compare(p2.getProfit(), p1.getProfit());  
        };
        
        Collections.sort(list,comp);
        
        int cnt = 0;
        int sum = 0;
        
        // for(int i = n - 1; i >= 0; i--)
        // {
        //     int pf = list.get(i).getValue();
        //     int dd = list.get(i).getKey();
            
        //     while(dd != 0 && res[dd] != 0)
        //     {
        //         dd--;
        //     }
            
        //     if(dd != 0) 
        //     {
        //         cnt++;
        //         res[dd] = pf;
        //         sum += pf;
        //     }
        // }
        
        
        for(int i = 0; i < n; i++)
        {
            int dd = list.get(i).getDeadline();
            int pf = list.get(i).getProfit();
            
            int availableSlot = ds.findPar(dd);
            
            if(availableSlot > 0)
            {
                cnt++;
                sum += pf;
                
                ds.union(availableSlot, ds.findPar(availableSlot - 1));
            }
        }
        
        ArrayList<Integer> ans = new ArrayList<Integer>();
        
        ans.add(cnt);
        ans.add(sum);
        
        return ans;
        
    }
}
