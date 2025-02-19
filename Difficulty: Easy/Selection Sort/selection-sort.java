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
        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            String arr[] = br.readLine().split(" ");
            int a[] = new int[arr.length];

            for (int i = 0; i < arr.length; i++) {
                a[i] = Integer.parseInt(arr[i]);
            }

            Solution obj = new Solution();
            obj.selectionSort(a);

            IntArray.print(a);
            System.out.println("~");
        }
    }
}

// } Driver Code Ends


class Solution {
    void selectionSort(int[] arr) {
        // code here
        int n = arr.length;
        
        for(int i = 0; i <= n - 2; i++)
        {
            // Consider the first guy to be minimum
            int mini = i;
            for(int j = i; j <= n - 1; j++)
            {
                // If current element is less than the element that I cosidered to be minimum
                if(arr[j] < arr[mini])
                {
                    mini = j;
                }
            }
            
            int temp = arr[i];
            arr[i] = arr[mini];
            arr[mini] = temp;
        }
        
        return ;
    }
}