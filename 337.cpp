//Method-1 : 

#define ma make_pair 
int cash(TreeNode *root,int status, map<pair<TreeNode*,int>,int>&mp)
{
    if(root==NULL)
        return 0;

    if(mp.find(ma(root,status))==mp.end())
    {
        int l=0,l1=0,lw=0;
        if(status==0)
        {
            l=root->val+cash(root->left,1,mp)+cash(root->right,1,mp);
            l1=cash(root->left,0,mp)+cash(root->right,0,mp);
            l=max(l,l1);
        }
        else
        {
            lw=cash(root->left,0,mp)+cash(root->right,0,mp);
        }
        
        mp[ma(root,status)]=max(l,lw);
    }
    return mp[ma(root,status)];
    
}

class Solution 
{
public:
    int rob(TreeNode* root) 
    {
        map<pair<TreeNode*,int>,int>mp;
        return cash(root,0,mp);
    }
};


//Method-2 : 

#define ma make_pair 
int cash(TreeNode *root,int status, map<pair<TreeNode*,int>,int>&mp)
{
    if(root==NULL)
        return 0;

    if(mp.find(ma(root,status))==mp.end())
    {
        int l=0,l1=0,lw=0;
        if(status==0)
        {
            l=root->val+cash(root->left,1,mp)+cash(root->right,1,mp);
        }
        lw=cash(root->left,0,mp)+cash(root->right,0,mp);
        
        mp[ma(root,status)]=max(l,lw);
    }
    return mp[ma(root,status)];
}

class Solution 
{
public:
    int rob(TreeNode* root) 
    {
        map<pair<TreeNode*,int>,int>mp;
        return cash(root,0,mp);
    }
};


//Method-3 : 

int cash(TreeNode *root,map<TreeNode*,int>&mp)
{
    if(root==NULL)
        return 0;

    if(mp.find(root)==mp.end())
    {
        int ans_include=root->val;
        if(root->left)
            ans_include+=cash(root->left->left,mp)+cash(root->left->right,mp);
        
        if(root->right)
            ans_include+=cash(root->right->left,mp)+cash(root->right->right,mp);
        
        int ans_not_include=cash(root->left,mp)+cash(root->right,mp);
        
        mp[root]=max(ans_include,ans_not_include);
    }
    return mp[root];
}

class Solution 
{
public:
    int rob(TreeNode* root) 
    {
        map<TreeNode*,int>mp;
        return cash(root,mp);
    }
};
