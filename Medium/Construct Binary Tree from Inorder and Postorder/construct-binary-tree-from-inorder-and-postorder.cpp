//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution
{
    public:
    
    Node* solve(int in[],int post[], int instart, int inend, int poststart, int postend)
    {
        if(instart>inend)
        {
            return nullptr;
        }
        
        if(instart == inend)
        {
            return new Node(in[instart]);
        }
        
        Node* root = new Node(post[postend]);
        int index = -1;
        
        for(int i = instart; i <= inend; i++)
        {
            if(in[i] == post[postend])
            {
                index = i;
                break;
            }
        }
        
        int left = index - instart;
        int right = inend - index;
        
        root->left = solve(in, post, instart, index - 1, poststart, poststart + left - 1);
        root->right = solve(in, post, index + 1, inend, postend - right, postend - 1);
        
        return root;
    }

    //Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int in[], int post[], int n) {
        // Your code here
        return solve(in, post, 0, n-1, 0, n-1);
    }
};


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends