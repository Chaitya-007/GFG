//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String line = br.readLine();
            String[] tokens = line.split(" ");

            // Create an ArrayList to store the integers
            ArrayList<Integer> array = new ArrayList<>();

            // Parse the tokens into integers and add to the array
            for (String token : tokens) {
                array.add(Integer.parseInt(token));
            }

            int[] arr = new int[array.size()];
            int idx = 0;
            for (int i : array) arr[idx++] = i;

            System.out.println(new Solution().minJumps(arr));
            // System.out.println("~");
        }
    }
}

// } Driver Code Ends


class Solution {
    static int minJumps(int[] arr) {
        if (arr.length <= 1) {
            return 0;           // If array has only one element, no jumps are needed
        }
        if (arr[0] == 0) {
            return -1;          // If the first element is 0, can't move forward
        }

        int jumps = 0;
        int currentEnd = 0;
        int farthest = 0;

        for (int i = 0; i < arr.length - 1; i++) {
            farthest = Math.max(farthest, i + arr[i]);  // Update the farthest point reachable
            if (i == currentEnd) {                      // Reached the end of the range for the current jump
                jumps++;
                currentEnd = farthest;                  // Update currentEnd to the farthest point reachable
                if (currentEnd >= arr.length - 1) {
                    return jumps;                       // If currentEnd reaches or exceeds the last index, return the jumps
                }
            }
        }
        return -1;
    }
}