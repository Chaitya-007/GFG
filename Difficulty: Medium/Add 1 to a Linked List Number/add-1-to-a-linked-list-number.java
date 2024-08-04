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
    
    public Node reverseList(Node head)
    {
        if(head == null || head.next == null)
        {
            return head;
        }
        
        Node curr = head;
        Node forward = head;
        Node prev = null;
        
        while(curr != null)
        {
            forward = curr.next;
            curr.next = prev;
            prev = curr;
            curr = forward;
        }
        
        return prev;
    }
    
    public Node addOne(Node head) {
        // code here.
        
        // Optimal Solution
        if(head == null)
        {
            return head;
        }
        
        
        Node newHead = reverseList(head);
        
        Node ptr = newHead;
        int carry = 1;
        Node prev = null;
        
        while(ptr != null)
        {
            int sum = ptr.data + carry;
            carry = sum/10;
            ptr.data = sum%10;
            prev = ptr;
            ptr = ptr.next;
        }
        
        if(carry == 1)
        {
            Node temp = new Node(carry);
            prev.next = temp;
        }
        
        head = reverseList(newHead);
        
        
        return head;
        
        
        // Brute Force
        // if(head == null)
        // {
        //     return head;
        // }
        
        // int num = 0;
        
        
        // Node ptr = head;
        
        
        // while(ptr != null)
        // {
        //     num = ptr.data + num*10;
        //     ptr = ptr.next;
        // }
        
        // num = num + 1;
        
        // Node newHead = new Node(-1);
        // Node temp = newHead;
        
        // while(num > 0)
        // {
        //     int rem = num%10;
        //     temp.next = new Node(rem);
        //     temp = temp.next;
        //     num = num/10;
        // }
        
        // Node result = reverseList(newHead.next);
        
        // return result;
        
    }
}
