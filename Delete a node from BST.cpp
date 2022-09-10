void deletion(Node *&root,int x)
{
    if(root->data==x)
    {
        if(root->left==NULL && root->right==NULL)
        {
            root=NULL;
        }
        else if(root->left && !root->right)
        {
            root=root->left;
        }
        else if(root->right && !root->left)
        {
            root=root->right;
        }
        else if(root->left && root->right)
        {
            Node *temp=root->right;
            while(temp->left!=NULL)
            {
                temp=temp->left;
            }
            temp->left=root->left;
            root=root->right;
        }
        return;
    }
    
    if(root->data>x)
    {
        if(root->left)
        {
            deletion(root->left,x);
        }
    }
    else if(root->data<x)
    {
        if(root->right)
        {
            deletion(root->right,x);
        }
    }
}
// Function to delete a node from BST.
Node *deleteNode(Node *root, int x) 
{
    
    deletion(root,x);
    return root;
    
}
