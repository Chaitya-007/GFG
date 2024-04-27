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
    struct Node* merge(struct Node *left, struct Node *right){
        struct Node *ans = NULL;
        if(left->data < right->data){
            ans = left;
            left = left->next;
        }else{
            ans = right;
            right = right->next;
        }
        
        struct Node *tail = ans;
        while(left != NULL && right != NULL){
            if(left->data < right->data){
                struct Node *x = left;
                tail->next = x;
                x->prev = tail;
                tail = tail->next;
                left = left->next;
            }else{
                struct Node *x = right;
                tail->next = x;
                x->prev = tail;
                tail = tail->next;
                right = right->next;
            }
        }
        while(left != NULL){
            struct Node *x = left;
            tail->next = x;
            x->prev = tail;
            tail = tail->next;
            left = left->next;
        }
        while(right != NULL){
            struct Node *x = right;
            tail->next = x;
            x->prev = tail;
            tail = tail->next;
            right = right->next;
        }
        
        tail->next = NULL;
        return ans;
    }
  
    struct Node* mergesort(struct Node* head, int n){
        if(n <= 1)
            return head;
        
        int mid = (n-1)/2;
        int curr = 0;
        struct Node *temp1 = head;
        while(curr < mid){
            temp1 = temp1->next;
            curr++;
        }
        
        struct Node *temp2 = temp1->next;
        temp1->next = NULL;
        temp2->prev = NULL;
        
        struct Node *left = mergesort(head, mid+1);
        struct Node *right = mergesort(temp2, n-mid-1);
        
        return merge(left, right);
    }
    
    // Function to sort the given doubly linked list using Merge Sort.
    struct Node *sortDoubly(struct Node *head) {
        int n = 0;
        struct Node *temp = head;
        while(temp != NULL){
            n++;
            temp = temp->next;
        }
        return mergesort(head, n);
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