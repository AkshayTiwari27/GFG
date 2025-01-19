//{ Driver Code Starts
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

Node *constructTree (int [], int );

void printInorder (Node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
	

}

int main ()
{   
    int t,n;
   scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int post[n];
        for(int i=0;i<n;i++)
        scanf("%d",&post[i]);

    Node* root = constructTree(post, n);

	printInorder(root);
    printf("\n");

cout << "~" << "\n";
}
	return 0;
}

// } Driver Code Ends


/*struct Node
{
	int data;
	Node *left, *right;
};*/

    Node* createTree(int post[],int size,int & index,int lower,int upper){
        if(index<0|| post[index]<lower|| post[index]>upper) return NULL;
        
        Node* root=new Node(post[index--]);
        root->right=createTree(post,size,index,root->data,upper);
        root->left=createTree(post,size,index,lower,root->data);
        
        return root;
    }
    Node *constructTree (int post[], int size)
    {
        //code here
        int index=size-1;
        return createTree(post,size,index,INT_MIN,INT_MAX);
    
    
    }