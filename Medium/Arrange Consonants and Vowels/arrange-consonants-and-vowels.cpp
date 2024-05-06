//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printlist(Node *head) {
    if (head == NULL)
        return;
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void append(struct Node **headRef, char data) {
    struct Node *new_node = new Node(data);
    struct Node *last = *headRef;

    if (*headRef == NULL) {
        *headRef = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}


// } Driver Code Ends
/*
Structure of the node of the linked list is as
struct Node
{
    char data;
    struct Node *next;

    Node(char x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    // task is to complete this function
    // function should return head to the list after making
    // necessary arrangements
    struct Node* arrangeCV(Node* head) {
         // Code here
        // struct Node* left = head;
        // struct Node* right = head->next;
        // struct Node* prev = head;
        
        // while(right != nullptr)
        // {
        //     if(right->data == 'a' || right->data == 'e' || right->data == 'i' || right->data == 'o' || right->data == 'u')
        //     {
        //         struct Node* temp = left->next;
        //         struct Node* ptr = new Node(right->data);
        //         left->next = ptr;
        //         ptr->next = temp;
        //         left = left->next;
                
        //         prev->next = right->next;
        //     }
        //     else
        //     {
        //         prev = right;
        //     }
            
        //     right = right->next;
        // }
        
        // M-2
        vector<char> cons;
        vector<char> vowel;
        
        struct Node* ptr = head;
        
        while(ptr != nullptr)
        {
            if(ptr->data == 'a' || ptr->data == 'e' || ptr->data == 'i' || ptr->data == 'o' || ptr->data == 'u')
            {
                vowel.emplace_back(ptr->data);
            }
            else
            {
                cons.emplace_back(ptr->data);
            }
            
            ptr = ptr->next;
        }
        
        struct Node* newhead = new Node('z');
        ptr = newhead;
        
        if(vowel.size() > 0)
        {
            
        for(int i = 0; i < vowel.size(); i++)
        {
            ptr->next = new Node(vowel[i]);
            ptr = ptr->next;
            
        }
        
        }
        
        if(cons.size() > 0)
        {
            for(int i = 0; i < cons.size(); i++)
            {
                ptr->next = new Node(cons[i]);
                ptr = ptr->next;
            }
        }
        
        newhead = newhead->next;
        
        return newhead;
        
        
    }
};


//{ Driver Code Starts.

// task is to complete this function
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        char tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            append(&head, tmp);
        }
        Solution obj;
        head = obj.arrangeCV(head);
        printlist(head);
    }
    return 0;
}

// } Driver Code Ends