int ans=INT_MAX;
TreeNode *prevp=NULL;
void check(TreeNode *root)
{
    if(!root)
        return;
    check(root->left);
    if(prevp==NULL)
        prevp=root;
    else
        ans=min(ans,abs(root->val-prevp->val));
    prevp=root;
    check(root->right);
    
}
class Solution 
{
public:
    int getMinimumDifference(TreeNode* root) 
    {
        ans=INT_MAX;
        prevp=NULL;
        check(root);
        return ans;
    }
};
