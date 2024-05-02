//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next, *prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};


// } Driver Code Ends

/* Structure of the node of the list is as
struct Node
{
    int data;
    struct Node *next, *prev;
    Node (int x){
        data = x;
        next = prev = NULL;
    }
};
*/

// void merge(vector<int> &vec, int left, int mid, int high)
// {
//     int left = low;
//     int right = mid + 1;
//     vector<int> temp;
    
//     while(left <= mid && right <= high)
//     {
//         if(vec[left] <= vec[right])
//         {
//             temp.emplace_back(vec[left]);
//             left++;
//         }
//         else
//         {
//             temp.emplace_back(vec[right]);
//             right++;
//         }
//     }
    
//     while(left <= mid)
//     {
//         temp.emplace_back(vec[left]);
//         left++;
//     }
    
//     while(right <= high)
//     {
//         temp.emplace_back(vec[right]);
//         right++;
//     }
    
//     for(int i = low ; i <= high; i++)
//     {
//         vec[i] = temp[i - low];
//     }
// }

// void mergesort(vector<int> &vec, int left, int high)
// {
//     if(low >= high)
//     {
//         return;
//     }
    
//     int mid = (low + high)/2;
//     mergesort(vec,left,mid);
//     mergesort(vec,mid+1,high);
//     merge(vec,left,mid,high);
// }

// class Solution {
//   public:
//     // Function to sort the given doubly linked list using Merge Sort.
//     struct Node *sortDoubly(struct Node *head) {
//         // Your code here
//         vector<int> vec;
        
//         struct Node *p = head;
        
//         while(p != nullptr)
//         {
//             vec.emplace_back(p->data);
//             p = p->next;
//         }
        
//         int n = vec.size();
        
//         void mergesort(vec,0,n-1);
//     }
// };

class Solution {
  public:
  
  struct Node* merge(struct Node* first, struct Node* second)
  {
      if(!first)
      {
          return second;
      }
      
      if(!second)
      {
          return first;
      }
      
      if(first->data < second->data)
      {
          first->next = merge(first->next,second);
          first->next->prev = first;
          first->prev = nullptr;
          
          return first;
      }
      
      else
      {
          second->next = merge(first,second->next);
          second->next->prev = second;
          second->prev = nullptr;
          
          return second;
      }
  }
   
    struct Node* getMid(struct Node* head)
    {
        struct Node* fast = head;
        struct Node* slow = head;
        
        while(fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        // will return the mid of next split
        struct Node* temp = slow->next;
        slow->next = nullptr;
        
        return temp;
        
    }
    // Function to sort the given doubly linked list using Merge Sort.
    struct Node *sortDoubly(struct Node *head) {
        
        if(!head || !head->next)
        {
            return head;
        }
        
        struct Node* mid = getMid(head);
        head = sortDoubly(head);
        mid = sortDoubly(mid);
        
        return merge(head,mid);
    }
};


//{ Driver Code Starts.

void insert(struct Node **head, int data) {
    struct Node *temp = new Node(data);
    if (!(*head))
        (*head) = temp;
    else {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}

void print(struct Node *head) {
    struct Node *temp = head;
    while (head) {
        cout << head->data << ' ';
        temp = head;
        head = head->next;
    }
    cout << endl;
    while (temp) {
        cout << temp->data << ' ';
        temp = temp->prev;
    }
    cout << endl;
}

// Utility function to swap two integers
void swap(int *A, int *B) {
    int temp = *A;
    *A = *B;
    *B = temp;
}

// Driver program
int main(void) {
    long test;
    cin >> test;
    while (test--) {
        int n, tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            insert(&head, tmp);
        }
        Solution ob;
        head = ob.sortDoubly(head);
        print(head);
    }
    return 0;
}

// } Driver Code Ends