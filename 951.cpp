bool check(TreeNode *&root1,TreeNode *&root2)
{
    if(root1==NULL && root2==NULL)
        return true;
    if(root1==NULL || root2==NULL)
        return false;
    if(root1->val==root2->val)
    {
        if(check(root1->left,root2->left) && check(root1->right,root2->right))
            return true;
        swap(root1->left,root1->right);
        if(check(root1->left,root2->left) && check(root1->right,root2->right))
            return true;
    }
    return false;
}
class Solution 
{
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) 
    {
        return check(root1,root2);
    }
};
