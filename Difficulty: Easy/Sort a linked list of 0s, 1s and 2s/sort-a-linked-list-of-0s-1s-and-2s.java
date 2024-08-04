//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.lang.*;
import java.util.*;

class Node {
    int data;
    Node next;

    Node(int key) {
        data = key;
        next = null;
    }
}

public class Driverclass {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int t = Integer.parseInt(in.readLine().trim());

        while (t-- > 0) {
            int n = Integer.parseInt(in.readLine().trim());
            String s[] = in.readLine().trim().split(" ");
            Node head = new Node(Integer.parseInt(s[0]));
            Node tail = head;
            for (int i = 1; i < n; i++) {
                tail.next = new Node(Integer.parseInt(s[i]));
                tail = tail.next;
            }

            head = new Solution().segregate(head);
            printList(head, out);
            out.println();
        }
        out.close();
    }

    public static void printList(Node head, PrintWriter out) {
        if (head == null) return;

        Node temp = head;
        while (temp != null) {
            out.print(temp.data + " ");
            temp = temp.next;
        }
    }
}
// } Driver Code Ends


// User function Template for Java

/*
class Node
{
    int data;
    Node next;
    Node(int data)
    {
        this.data = data;
        next = null;
    }
}
*/
class Solution {
    // Function to sort a linked list of 0s, 1s and 2s.
    static Node segregate(Node head) {
        // add your code here
        if(head == null || head.next == null)
        {
            return head;
        }
        
        int cnt0 = 0;
        int cnt1 = 0;
        int cnt2 = 0;
        
        Node ptr = head;
        while(ptr != null)
        {
            if(ptr.data == 0)
            {
                cnt0++;
            }
            else if(ptr.data == 1)
            {
                cnt1++;
            }
            else
            {
                cnt2++;
            }
            
            ptr = ptr.next;
        }
        
        ptr = head;
        
        while(ptr != null)
        {
            if(cnt0 != 0)
            {
                ptr.data = 0;
                cnt0--;
            }
            else if(cnt1 != 0)
            {
                ptr.data = 1;
                cnt1--;
            }
            else if(cnt2 != 0)
            {
                ptr.data = 2;
                cnt2--;
            }
            ptr = ptr.next;
        }
        
        return head;
    }
}
