//{ Driver Code Starts
import java.io.*;
import java.util.*;

class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}

class GfG {
    public static void printList(Node node) {
        while (node != null) {
            System.out.print(node.data);
            node = node.next;
        }
        System.out.println();
    }

    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String str[] = read.readLine().trim().split(" ");
            int n = str.length;
            Node head = new Node(Integer.parseInt(str[0]));
            Node tail = head;
            for (int i = 1; i < n; i++) {
                tail.next = new Node(Integer.parseInt(str[i]));
                tail = tail.next;
            }
            Solution obj = new Solution();
            head = obj.addOne(head);
            printList(head);
        }
    }
}
// } Driver Code Ends


/*
class Node{
    int data;
    Node next;

    Node(int x){
        data = x;
        next = null;
    }
}
*/

class Solution {
      public int fun(Node temp)
    {
        if(temp == null) return 1;
        
        int carry = fun(temp.next);
        
        if((temp.data + carry) < 10 )
        {
            temp.data = temp.data + carry;
           return 0;
        }
        
        temp.data = 0;
        return carry;
    }
    
    public Node addOne(Node head) {
        // code here.
        int carry = fun(head);
        if(carry == 1)
        {
            Node temp = new Node(carry);
            temp.next = head;
            head = temp;
        }
        
        return head;
    }
}
