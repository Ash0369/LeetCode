int check(TreeNode *root,int val)
{
    if(root==NULL)
        return -1;
    if(root->val!=val)
        return root->val;
    int l=check(root->left,val);
    int r=check(root->right,val);
    if(l==-1)
        return r;
    if(r==-1)
        return l;
    return min(l,r);
}
class Solution 
{
public:
    int findSecondMinimumValue(TreeNode* root) 
    {
        int val=root->val;
        int a=check(root->left,val);
        int b=check(root->right,val);
        
        if(a==-1)
            return b;
        if(b==-1)
            return a;
        return min(a,b);
    }
};
