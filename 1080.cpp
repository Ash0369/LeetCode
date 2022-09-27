bool helper(TreeNode *root,int &limit,int sum)
{
    if(root==NULL)
        return false;
    
    if(root->left==NULL && root->right==NULL)
    {
        int temp=sum+root->val;
        if(temp<limit)
            return false;
        return true;
    }
    
    bool l=helper(root->left,limit,sum+root->val);
    bool r=helper(root->right,limit,sum+root->val);
    
    if(l && r)
        return true;
    
    if(!l)
        root->left=NULL;
    if(!r)
        root->right=NULL;
    if(!l && !r)
    {
        return false;
    }
    return true;
}
class Solution 
{
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) 
    {
        auto res=helper(root,limit,0);
        if(res)
            return root;
        return NULL;
    }
};
