//{ Driver Code Starts
// Initial Template for Java
import java.util.*;


// } Driver Code Ends

// User function Template for Java
class Solution {
    public String findOrder(String[] words) {
        // code here
        List<List<Integer>> adj = new ArrayList<>();
        
        int n = words.length;
        int k = 0;
        int maxInd = 0;
        
        // HashSet<Character> set = new HashSet<>();
        HashMap<Character, List<Character> > adjMap = new HashMap<>();
        HashMap<Character, Integer> indegree = new HashMap<>();
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0;  j < words[i].length(); j++)
            {
                // set.add(words[i].charAt(j));
                List<Character> list = new ArrayList<>();
                adjMap.put(words[i].charAt(j),list);
                indegree.put(words[i].charAt(j),0);
            }
        }
        
        // k = set.size();
        
        // for(int i = 0; i < k; i++)
        // {
        //     adj.add(new ArrayList<>());
        // }
        
        
        for(int i = 0; i < n - 1; i++)
        {
            StringBuilder sb1 = new StringBuilder(words[i]);
            StringBuilder sb2 = new StringBuilder(words[i + 1]);
            int len = Math.min(sb1.length(),sb2.length());
            boolean flag = true;
            
            for(int j = 0; j < len; j++)
            {
                if(sb1.charAt(j) != sb2.charAt(j))
                {
                    flag = false;
                    char key = sb1.charAt(j);
                    char val = sb2.charAt(j);
                   
                    List<Character> l = new ArrayList<>(adjMap.get(key));
                    l.add(val);
                    adjMap.put(key,l);
                    indegree.put(val, indegree.get(val) + 1);
                    break;
                }
            }
            
            if(flag)
            {
                if(sb1.length() > sb2.length())
                {
                    return "";
                }
            }
            
        }
        
        
        Queue<Character> q = new LinkedList<>();
        
        for(Map.Entry<Character,Integer> e : indegree.entrySet())
        {
            if(e.getValue() == 0)
            {
                q.offer(e.getKey());
            }
        }
        
        List<Character> ans = new ArrayList<>();
        StringBuilder sb = new StringBuilder("");
        
        while(!q.isEmpty())
        {
            char node = q.peek();
            // ans.add(node);
            sb.append(node);
            q.poll();
            
            for(Character adjNode : adjMap.get(node))
            {
                if(indegree.get(adjNode) > 0)
                {
                    // indegree.get(adjNode) -= 1;
                    indegree.put(adjNode, indegree.get(adjNode) - 1);
                    if(indegree.get(adjNode) == 0)
                    {
                        q.offer(adjNode);
                    }
                }
            }
        }
        
        if(sb.length() < adjMap.size())
        {
            return "";
        }
        
        
    
        
        return sb.toString();
    }
}


//{ Driver Code Starts.

public class GFG {
    private static boolean validate(String[] original, String order) {
        Map<Character, Integer> mp = new HashMap<>();
        for (String word : original) {
            for (char ch : word.toCharArray()) {
                mp.put(ch, 1);
            }
        }
        for (char ch : order.toCharArray()) {
            if (!mp.containsKey(ch)) {
                return false;
            }
            mp.remove(ch);
        }
        if (!mp.isEmpty()) {
            return false;
        }

        Map<Character, Integer> indexMap = new HashMap<>();
        for (int i = 0; i < order.length(); i++) {
            indexMap.put(order.charAt(i), i);
        }

        for (int i = 0; i < original.length - 1; i++) {
            String a = original[i];
            String b = original[i + 1];
            int k = 0, n = a.length(), m = b.length();

            while (k < n && k < m && a.charAt(k) == b.charAt(k)) {
                k++;
            }

            if (k < n && k < m &&
                indexMap.get(a.charAt(k)) > indexMap.get(b.charAt(k))) {
                return false;
            }
            if (k != n && k == m) {
                return false;
            }
        }

        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine()); // Number of test cases

        while (t-- > 0) {
            String[] words = sc.nextLine().split(" ");
            String[] original = Arrays.copyOf(words, words.length);

            Solution ob = new Solution();
            String order = ob.findOrder(words);

            if (order.isEmpty()) {
                System.out.println("\"\"");
            } else {
                System.out.println(validate(original, order) ? "true" : "false");
            }
            System.out.println("~");
        }

        sc.close();
    }
}

// } Driver Code Ends