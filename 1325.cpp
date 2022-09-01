bool del(TreeNode* &root,int target)
{
    if(root==NULL)
    {
        return true;
    }
    if(root->left==NULL && root->right==NULL)
    {
        if(root->val==target)
        {
            return true;
        }
        return false;
    }
    
    
    
    bool a=del(root->left,target);
    bool b=del(root->right,target);
    
    if(a)
    {
        root->left=NULL;
    }
    if(b)
    {
        root->right=NULL;
    }
    if(a && b)
    {
        if(root->val==target)
        {
            return true;
        }
    }
    return false;
    
}
class Solution 
{
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) 
    {
        bool a=del(root,target);
        if(a)
        {
            return NULL;
        }
        return root;
    }
};
