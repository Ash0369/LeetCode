int count(TreeNode* root,int max_in_path)
{
    if(root==NULL)
    {
        return 0;
    }
    
    int temp=max(root->val,max_in_path);
    int a=0;
    int b=0;
    if(root->left)
    {
        a=count(root->left,temp);
    }
    if(root->right)
    {
        b=count(root->right,temp);
    }
    if(root->val>=max_in_path)
    {
        return a+b+1;
    }
    return a+b;
}
class Solution 
{
public:
    int goodNodes(TreeNode* root) 
    {
        return count(root,INT_MIN);
    }
};
