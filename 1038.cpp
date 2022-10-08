void sum(TreeNode *root,int &value)
{
    if(root==NULL)
    {
        return;
    }
    sum(root->right,value);
    root->val=root->val+value;
    value=root->val;
    sum(root->left,value);
}
class Solution 
{
public:
    TreeNode* bstToGst(TreeNode* root) 
    {
        int a=0;
        TreeNode *dummy=root;
        sum(dummy,a);
        return root;
    }
};
