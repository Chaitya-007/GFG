//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    
    struct Node* reverse(struct Node* head)
    {
        
        if(!head || !head->next)
        {
            return head;
        }
        
        struct Node* curr = head;
        struct Node* next = head->next;
        struct Node* prev = nullptr;
        
        while(next)
        {
            curr->next = prev;
            prev = curr;
            curr = next;
            next = curr->next;
        }
        
        curr->next = prev;
        
        return curr;
    }
    
    struct Node* addlist(struct Node* l1, struct Node* l2)
    {
        
        if(!l1)
        {
            return l2;
        }
        
        if(!l2)
        {
            return l1;
        }
        
        int carry = 0;
        struct Node* tail = l1;
        struct Node* head = l1;
        
        while(l1 && l2)
        {
            l1->data += l2->data + carry;
            carry = l1->data/10;
            l1->data = l1->data%10;
            tail = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        if(l2 != nullptr)
        {
            tail->next = l2;
            l1 = tail->next;
        }
        
        while(l1)
        {
            l1->data = l1->data + carry;
            carry = l1->data/10;
            l1->data = l1->data%10;
            tail = l1;
            l1 = l1->next;
        }
        
        l1 = tail;
        
        while(carry)
        {
            l1->next = new Node(carry);
            l1 = l1->next;
            carry = l1->data/10;
            l1->data = l1->data%10; 
        }
        
        return head;
    }
    
    
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        // code here
        
        
        
        // struct Node* temp = nullptr;
        while(num1->next && num1->data == 0)
        {
            // temp = num1;
            num1 = num1->next;
        }
        
        // temp->next = nullptr;
        
        while(num2 && num2->data == 0)
        {
            // temp = num2;
            num2 = num2->next;
        }
        
        // temp->next = nullptr;
        
        // if(num1 && num2)
        // {
        //     return 0;
        // }
        
        // if(!num1)
        // {
        //     return num2;
        // }
        
        // if(!num2)
        // {
        //     return num1;
        // }
        
        num1 = reverse(num1);
        
        num2 = reverse(num2);
        
        // struct Node* ans = addlist(num1,num2);
        
        // struct Node* rev = reverse(ans);
        
        // return rev;
        
        return reverse(addlist(num1,num2));
        
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends