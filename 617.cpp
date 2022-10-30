void merge(TreeNode *&root1,TreeNode *&root2)
{
    if(root1==NULL && root2==NULL)
        return;
    if(root1==NULL)
    {
        root1=root2;
        return;
    }
    if(root2==NULL)
        return;
    root1->val+=root2->val;
    merge(root1->left,root2->left);
    merge(root1->right,root2->right);
}
class Solution 
{
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) 
    {
        merge(root1,root2);
        return root1;
    }
};
