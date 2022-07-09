bool check_bst(TreeNode* root,long long int start,long long int end)
{
    if(root==NULL)
    {
        return true;
    }
    if(root->val>start && root->val<end)
    {
       bool right=check_bst(root->right,root->val,end);
       bool left=check_bst(root->left,start,root->val);

       if(left && right)
       {
            return true;
       }
    }
    return false;
}
class Solution 
{
public:
    bool isValidBST(TreeNode* root) 
    {
        return check_bst(root,INT64_MIN,INT64_MAX);
    }
};
