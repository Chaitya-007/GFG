//{ Driver Code Starts
import java.io.*;
import java.util.*;

class IntArray {
    public static int[] input(BufferedReader br, int n) throws IOException {
        String[] s = br.readLine().trim().split(" ");
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = Integer.parseInt(s[i]);

        return a;
    }

    public static void print(int[] a) {
        for (int e : a) System.out.print(e + " ");
        System.out.println();
    }

    public static void print(ArrayList<Integer> a) {
        for (int e : a) System.out.print(e + " ");
        System.out.println();
    }
}

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while (t-- > 0) {

            int n;
            n = Integer.parseInt(br.readLine());

            int[] arr = IntArray.input(br, n);

            Solution obj = new Solution();
            ArrayList<Integer> res = obj.duplicates(arr);

            IntArray.print(res);
        }
    }
}

// } Driver Code Ends



class Solution {
    public static ArrayList<Integer> duplicates(int[] arr) {
        // code here
        int n = arr.length;
        int[] temp = new int[n];
        Arrays.fill(temp,0);
        
        for(int i = 0; i < n ; i++)
        {
            temp[arr[i]] = temp[arr[i]] + 1;
        }
        
        ArrayList<Integer> list = new ArrayList<Integer>();
        
        for(int i = 0; i < n; i++)
        {
            if(temp[i] > 1)
            {
                list.add(i);
            }
        }
        
        if(list.isEmpty())
        {
            list.add(-1);
        }
        
        return list;
    }
}
