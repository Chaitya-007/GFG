//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};


void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    
    *tail_ref = new_node;
}


// } Driver Code Ends
/* Link list Node 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/

/*You are required to complete this method*/

/* Function to get the middle of the linked list*/
/*K will always be in range */

class Solution {
    public:
    Node* deleteK(Node *head,int k){
      //Your code here
      
    //   struct Node* ptr = head;
    //   int totsize = 0;
       
    //   while(ptr != nullptr)
    //   {
    //       totsize++;
    //       ptr = ptr->next;
    //   }
       
    //   int cnt = 1;
    //   int rem = k - 1;
       
    //   while(cnt <= totsize)
    //   {
    //       if(cnt%k == rem)
    //       {
    //           cnt++;
    //           ptr->next = ptr->next->next;
    //       }
           
    //       cnt++;
    //       ptr = ptr->next;
    //   }
       
    //   return head;
    
    if(k == 1)
    {
        return nullptr;
    }
    
    struct Node* temp = head;
    struct Node* prev = nullptr;
    int cnt = 0;
    
    while(temp != nullptr)
    {
        cnt++;
        
        if(cnt == k)
        {
            prev->next = temp->next;
            cnt = 0;
        }
        
        else
        {
            // when we will be deleting then we don't want to point prev to the node to be deleted
            prev = temp;
        }
        
        temp = temp->next;
    }
    
    return head;
    
    }
};


//{ Driver Code Starts.

/* Driver program to test above function*/
int main()
{
  int T,i,n,l;
    cin>>T;
    while(T--){
    struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
        int K;
        cin>>K;
        Solution obj;
        Node *res = obj.deleteK(head,K);
        Node *temp = res;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends