//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    
Node* solve(int in[], int pre[], int n, int &index, int inorderstart, int inorderend, map<int, queue<int>>& mp) {
    if (index >= n || inorderstart > inorderend)
        return NULL;

    int element = pre[index++];
    Node* node = new Node(element);

    if (!mp[element].empty()) {
        int pos = mp[element].front();
        mp[element].pop();

        node->left = solve(in, pre, n, index, inorderstart, pos - 1, mp);
        node->right = solve(in, pre, n, index, pos + 1, inorderend, mp);
    } else {
        node->left = NULL;
        node->right = NULL;
    }
    
    return node;
}

    
    Node* buildTree(int in[],int pre[], int n)
    {
        int index=0;
        map<int,queue<int>>mp;
        for(int i=0;i<n;i++){
            mp[in[i]].push(i);
        }
        
        Node* ans=solve(in,pre,n,index,0,n-1,mp);
        return ans;
    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends