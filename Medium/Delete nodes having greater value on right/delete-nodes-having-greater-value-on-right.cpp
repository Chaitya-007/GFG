//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node *compute(Node *head)
    {
        // your code goes here
        
        // MY CODE IS IN SUBMISSION
            head = rev(head);
            Node* p = head;
            
            while (p != nullptr && p->next != nullptr) {
                if (p->data > p->next->data) {
                    p->next = p->next->next;
                } else {
                    p = p->next;
                }
            }
            
            return rev(head);
    }
        
        Node* rev(Node* head) 
        {
        Node* previous = nullptr;
        Node* next = nullptr;
        
        while (head != nullptr) {
            next = head->next;
            head->next = previous;
            previous = head;
            head = next;
        }
        
        return previous;
        }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends