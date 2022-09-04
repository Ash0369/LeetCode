//Method-1 : 

bool check(TreeNode *root,int value)
{
    if(root==NULL)
    {
        return true;
    }
    bool a=check(root->left,value);
    bool b=check(root->right,value);
    
    if(root->val==value && a && b)
    {
        return true;
    }
    return false;
}
class Solution 
{
public:
    bool isUnivalTree(TreeNode* root) 
    {
        if(root==NULL)
        {
            return true;
        }
        return check(root,root->val);
    }
};

//Method-2 : 

void check(TreeNode *root,set<int>&st)
{
    if(root==NULL)
    {
        return;
    }
    check(root->left,st);
    check(root->right,st);
    
    st.insert(root->val);
}
class Solution 
{
public:
    bool isUnivalTree(TreeNode* root) 
    {
        if(root==NULL)
        {
            return true;
        }
        set<int>st;
        check(root,st);
        if(st.size()==1)
        {
            return true;
        }
        return false;
    }
};
