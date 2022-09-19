int ans=1;
int check(TreeNode *root,int &max_value)
{
    if(root==NULL)
        return 0;
    
    int l=check(root->left,max_value);
    int r=check(root->right,max_value);
    max_value=max(max_value,max(l,r));
    if(l>=1 && r>=1)
    {
        if(root->val==root->left->val && root->val==root->right->val)
        {
            ans=max(ans,l+r+1);
            return max(l,r)+1;
        }   
    }
    if(l>=1 && root->val==root->left->val)
    {
        ans=max(ans,l+1);
        return l+1;
    }
        
    if(r>=1 && root->val==root->right->val)
    {
        ans=max(ans,r+1);
        return r+1;
    }

    return 1;
        
}
class Solution 
{
public:
    int longestUnivaluePath(TreeNode* root) 
    {
        if(root==NULL)
            return 0;
        int max_value=0;
        ans=1;
        return max(ans,check(root,max_value))-1;
    }
};
