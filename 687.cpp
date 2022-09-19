//Method-1 : 

int ans=1;
int check(TreeNode *&root)
{
    if(root==NULL)
        return 0;
    
    int l=check(root->left);
    int r=check(root->right);
    if(l>=1 && r>=1)
    {
        if(root->val==root->left->val && root->val==root->right->val)
        {
            ans=max(ans,l+r+1);
            return max(l,r)+1;
        }   
    }
    if(l>=1 && root->val==root->left->val)
    {
        ans=max(ans,l+1);
        return l+1;
    }
        
    if(r>=1 && root->val==root->right->val)
    {
        ans=max(ans,r+1);
        return r+1;
    }
    return 1; 
}
class Solution 
{
public:
    int longestUnivaluePath(TreeNode* root) 
    {
        if(root==NULL)
            return 0;
        ans=1;
        return max(ans,check(root))-1;
    }
};


//Method-2 : 

int ans=0;
int check(TreeNode *&root,int value)
{
    if(root==NULL)
        return 0;
    
    int l=check(root->left,root->val);
    int r=check(root->right,root->val);   
    ans=max(ans,l+r);
    
    if(root->val==value)
    {
        return max(l,r)+1;
    }
    return 0;
    
    
}
class Solution 
{
public:
    int longestUnivaluePath(TreeNode* root) 
    {
        ans=0;
        return max(ans,check(root,1001));
    }
};
