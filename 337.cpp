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
