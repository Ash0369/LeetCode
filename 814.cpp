//Method-1 : 

bool prun(TreeNode* &root)
{
    if(root==NULL)
    {
        return false;
    }
    bool a=prun(root->left);
    bool b=prun(root->right);
    
    if(!a)
    {
        root->left=NULL;
    }
    if(!b)
    {
        root->right=NULL;
    }
    
    if(a|b)
    {
        return true;
    }
    if(root->val==1)
    {
        return true;
    }
    return false;
}
class Solution 
{
public:
    TreeNode* pruneTree(TreeNode* root) 
    {
        bool a=prun(root);
        if(!a)
        {
            return NULL;
        }
        return root;
    }
};


//Method-2 : 


TreeNode* prun(TreeNode* &root)
{
    if(root==NULL)
    {
        return NULL;
    }
    root->left=prun(root->left);
    root->right=prun(root->right);
    if(root->left==NULL && root->right==NULL && root->val!=1)
    {
        return NULL;
    }
    return root;
}
class Solution 
{
public:
    TreeNode* pruneTree(TreeNode* root) 
    {
        return prun(root);
    }
};
