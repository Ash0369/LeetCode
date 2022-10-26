//Method-1 : DFS

void dfs(TreeNode*left,TreeNode *right,int level)
{
    if(left==NULL && right==NULL)
        return;
    if(level%2==0)
    {
        swap(left->val,right->val);
    }
    dfs(left->left,right->right,level+1);
    dfs(left->right,right->left,level+1);
}
class Solution 
{
public:
    TreeNode* reverseOddLevels(TreeNode* root) 
    {
        dfs(root->left,root->right,0);
        return root;
    }
};
