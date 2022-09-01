//Method-1 : 

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


//Method-2 : 

TreeNode *del(TreeNode* &root,int target)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->left==NULL && root->right==NULL)
    {
        if(root->val==target)
        {
            return NULL;
        }
    }    
    root->left=del(root->left,target);
    root->right=del(root->right,target);
    if(root->left==NULL && root->right==NULL && root->val==target)
    {
        root=NULL;
    }
    return root;
}
class Solution 
{
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) 
    {
        return del(root,target);
    }
};
