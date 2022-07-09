TreeNode* insertion(TreeNode* root,int value)
{
    if(root==NULL)
    {
        TreeNode* temp=new TreeNode(value);
        return temp;
    }
    if(value>(root->val))
    {
        root->right=insertion(root->right,value);
    }
    else
    {
        root->left=insertion(root->left,value);
    }
    return root;
}
class Solution 
{
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        return insertion(root,val);
    }
};
