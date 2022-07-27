void connect_node(Node* root)
{
    if(root->left==NULL)
    {
        return;
    }
    root->left->next=root->right;
    if(root->next)
    {
        root->right->next=root->next->left;
    }
    connect_node(root->left);
    connect_node(root->right);
    
}
class Solution 
{
public:
    Node* connect(Node* root) 
    {
        if(root==NULL)
        {
            return root;
        }
        connect_node(root);
        return root;
    }
};
