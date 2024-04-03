//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// A Tree node
struct Node
{
	int data;
	struct Node *left, *right;
};

// Utility function to create a new node
Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return (temp);
}

Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

	// Create the root of the tree
	Node* root = newNode(stoi(ip[0]));

	// Push the root to the queue
	queue<Node*> queue;
	queue.push(root);

	// Starting from the second element
	int i = 1;
	while (!queue.empty() && i < ip.size()) {

		// Get and remove the front of the queue
		Node* currNode = queue.front();
		queue.pop();

		// Get the current node's value from the string
		string currVal = ip[i];

		// If the left child is not null
		if (currVal != "N") {

			// Create the left child for the current node
			currNode->left = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->left);
		}

		// For the right child
		i++;
		if (i >= ip.size())
			break;
		currVal = ip[i];

		// If the right child is not null
		if (currVal != "N") {

			// Create the right child for the current node
			currNode->right = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->right);
		}
		i++;
	}

	return root;
}


// } Driver Code Ends
//User function Template for C++

/*// A Tree node
struct Node
{
	int data;
	struct Node *left, *right;
};*/


class Solution
{
     private:
    //For finding the lowest common ancestor of two nodes in bst
    Node* LCA(Node* root, int &x, int &y){
        if(root == NULL){
            return NULL;
        }
        if(root->data > x && root->data > y){
            return LCA(root->left, x, y);
        }
        if(root->data < x && root->data < y){
            return LCA(root->right, x, y);
        }
        return root;
    }
    
    public:
    
    /*You are required to complete below function */
    int kthCommonAncestor(Node *root, int k,int x, int y)
    {
        // your code goes here
          //We will have to first find the LCA (lowest common ancestor)
        //Then from LCA we will move upwards for kth common ancestor towards root
        //if kth doesn't exist we will return -1
        
        //Finding the lca 
        Node* lca = LCA(root, x, y);
        //If there is no lca, then return null, which is not possible in our case
        //Atleast root will be a lca, will only happen if either x, y doesn't exist in bst
        if(lca == NULL){
            return -1;
        }
        Node* curr = root;
        stack<Node*> st;
        //Transversing the path from root to lca
        while(curr != lca){
            st.push(curr);
            if(curr->data > lca->data){
                curr = curr->left;
            }
            else{
                curr = curr->right;
            }
        }
        st.push(curr);
        //Now stack st has all the nodes from root to lca with lca being on top of the 
        //stac
        while(st.empty() == false && k > 1){
            //k=1 , it means lca is our result,
            //if k > 1, we will pop out the node, move towards upward direction 
            //untill k becomes 1
            st.pop();
            k--;
        }
        // If stack becomes empty, it means we don't have kth common ancestor
        // Because at max, we can have root as a ancestor
        if (st.empty()){
            return -1;
        }
        return st.top()->data;
    }
};



//{ Driver Code Starts.

int main ()
{

	int t;
	cin >> t;
	cin.ignore();

	while (t--)
	{
	
		string inp;
		getline(cin, inp);
		
		int k,x,y;
		cin>>k>>x>>y;
		cin.ignore();

		struct Node* root = buildTree(inp);

        Solution ob;
		int ans = ob.kthCommonAncestor(root,k,x,y);
		cout<<ans<<endl;

	}

	return 0;
}
// } Driver Code Ends