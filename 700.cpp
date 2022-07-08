TreeNode* BST(TreeNode* root,int value)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->val==value)
    {
        return root;
    }
    if(root->val>value)
    {
        return BST(root->left,value);
    }
    
    return BST(root->right,value);
    
}
class Solution 
{
public:
    TreeNode* searchBST(TreeNode* root, int val) 
    {
        TreeNode* temp=BST(root,val);
        return temp;

    }
};
