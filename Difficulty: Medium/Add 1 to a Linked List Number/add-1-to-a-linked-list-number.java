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
        
System.out.println("~");
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
    
    public int fun(Node ptr)
    {
        if(ptr == null) return 1;
        
        int carry = fun(ptr.next);
        
        if(ptr.data + carry < 10)
        {
        int sum = ptr.data + carry;
        ptr.data = (sum%10);
            return 0;
        }
        
        ptr.data = 0;
        return 1;
        
        
    }
    
    
    public Node addOne(Node head) {
        // code here.
        int carry = fun(head);
        
        if(carry == 1)
        {
            Node ptr = new Node(1);
            ptr.next = head;
            head = ptr;
            ptr = null;
        }
        
        return head;
        
    }
}
