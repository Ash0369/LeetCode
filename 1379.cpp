//Method-1 :

TreeNode* get(TreeNode* original, TreeNode* cloned, TreeNode* target) 
{
    if(original==NULL && target!=NULL)
    {
        return NULL;
    }
    if(original==target)
    {
        return cloned;
    }
    TreeNode *l=get(original->left,cloned->left,target);
    TreeNode *r=get(original->right,cloned->right,target);
    if(l)
    {
        return l;
    }
    return r;  
}
class Solution 
{
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) 
    {
        return get(original,cloned,target);
    }
};

//Method-2 :

TreeNode* get(TreeNode *cloned,TreeNode *target)
{
    if(cloned==NULL)
    {
        return NULL;
    }
    if(cloned->val==target->val)
    {
        return cloned;
    }
    TreeNode *l=get(cloned->left,target);
    TreeNode *r=get(cloned->right,target);
    if(l)
    {
        return l;
    }
    return r;
}
class Solution 
{
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) 
    {
        return get(cloned,target);
    }
};
