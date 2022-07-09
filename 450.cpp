TreeNode* delete_node(TreeNode* root,int key)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->val==key)
    {
        TreeNode* left=root->left;
        TreeNode* right=root->right;
        root=right;
        if(right)
        {
            while(right->left!=NULL)
            {
                right=right->left;
            }
            right->left=left;
        }
        else
        {
            root=left;
        }   
    }
    else if(root->val>key)
    {
        root->left=delete_node(root->left,key);
    }
    else
    {
        root->right=delete_node(root->right,key);
        
    }
    return root;
}
class Solution 
{
public:
    TreeNode* deleteNode(TreeNode* &root, int key) 
    {
        return delete_node(root,key);
    }
};
