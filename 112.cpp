//Method-1 : DFS

bool path(TreeNode *root,int target)
{
    if(root==NULL)
        return false;
    if(root->left==NULL && root->right==NULL)
    {
        if(target==root->val)
            return true;
        return false;
    }
    bool l=path(root->left,target-root->val);
    if(l)
        return true;
    
    return path(root->right,target-root->val);
    
    
}
class Solution 
{
public:
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        return path(root,targetSum);
    }
};
