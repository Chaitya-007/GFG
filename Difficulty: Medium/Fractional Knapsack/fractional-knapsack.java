//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GfG {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());

        while (t-- > 0) {
            // Read values array
            String[] valueInput = br.readLine().trim().split(" ");
            List<Integer> values = new ArrayList<>();
            for (String s : valueInput) {
                values.add(Integer.parseInt(s));
            }

            // Read weights array
            String[] weightInput = br.readLine().trim().split(" ");
            List<Integer> weights = new ArrayList<>();
            for (String s : weightInput) {
                weights.add(Integer.parseInt(s));
            }

            // Read the knapsack capacity
            int w = Integer.parseInt(br.readLine().trim());

            // Call fractionalKnapsack function and print result
            System.out.println(String.format(
                "%.6f", new Solution().fractionalKnapsack(values, weights, w)));
            System.out.println("~");
        }
    }
}

// } Driver Code Ends


// User function Template for Java


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
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(List<Integer> val, List<Integer> wt, int capacity) {
        // code here
        
        List<Pair<Integer, Integer> > list = new ArrayList<>();
        
        for(int i = 0; i < wt.size(); i++)
        {
            list.add(new Pair<>(wt.get(i),val.get(i)));
        }
        
        Comparator<Pair<Integer, Integer> > comparator = (p1,p2) ->
        {
            
            double r1 = (double)p1.getValue()/ p1.getKey();
            double r2 = (double)p2.getValue()/ p2.getKey();
            
            return Double.compare(r2, r1);

            // Returns negative if ratio1 < ratio2
            // Returns 0 if ratio1 == ratio2
            // Returns positive if ratio1 > ratio2
        };
        
        Collections.sort(list, comparator);
        
        // for(int i = wt.size() - 1; i >= 1; i--)
        // {
        //     int pass = 0;
        //     for(int j = 0; j <= i - 1; j++)
        //     {
        //         if(wt.get(j) > wt.get(j+1))
        //         {
        //             Integer temp = wt.get(j);
        //             wt.set(j,wt.get(j+1));
        //             wt.set(j+1,temp);
                    
        //             Integer temp2 = val.get(j);
        //             val.set(j,val.get(j+1));
        //             val.set(j+1,temp2);
                    
        //             pass = 1;
                    
        //         }
        //     }
            
        //     if(pass == 0)
        //     {
        //         break;
        //     }
        // }
        
        //     System.out.print("Weight = ");
        // for(int i = 0; i < wt.size(); i++)
        // {
        //     System.out.print(wt.get(i) + " ");
        // }
        // System.out.println();
        
        //     System.out.print("Value = ");
        // for(int i = 0; i < wt.size(); i++)
        // {
        //     System.out.print(val.get(i) + " ");
        // }
        
        int sum = 0;
        double price = 0;
        for(int i = 0; i < val.size(); i++)
        {
            Integer weight = list.get(i).getKey();
            Integer cost = list.get(i).getValue();
            
            // if(sum + wt.get(i) <= capacity)
            if(sum + weight <= capacity)
            {
                // price += (double)(val.get(i)/wt.get(i))*wt.get(i); 
                price += ((double)cost/weight)*weight;
                // sum += wt.get(i);
                sum += weight;
            }
            else
            {
                // price += (double)(val.get(i)/wt.get(i))*(capacity - sum);
                price += ((double)cost/weight)*(capacity - sum);
                break;
            }
            
        }
        
        return price;
    }
}