bool check_sametree(TreeNode *root1,TreeNode *root2)
{
    if(root1==NULL && root2==NULL)
    {
        return true;
    }
    if(root1==NULL || root2==NULL)
    {
        return false;
    }
    if(root1->val!=root2->val)
    {
        return false;
    }
    bool a=check_sametree(root1->left,root2->right);
    bool b=check_sametree(root1->right,root2->left);
    return a&b;

}
class Solution 
{
public:
    bool isSymmetric(TreeNode* root) 
    {
        if(root==NULL)
        {
            return true;
        }
        return check_sametree(root->left,root->right);
    }
};
