TreeNode *trim(TreeNode *root,int low,int high)
{
    if(root==NULL)
        return NULL;
    
    root->left=trim(root->left,low,high);
    root->right=trim(root->right,low,high);
    
    if(root->val>high)
    {
        return root->left;
    }
    if(root->val<low)
    {
        return root->right;
    }
    return root;
}
class Solution 
{
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) 
    {
        return trim(root,low,high);
    }
};
