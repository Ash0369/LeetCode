//Method-1 : 

int max_ans=0;
int longest(TreeNode *root,char drxn)
{
    if(root==NULL)
        return 0;
    if(drxn=='A')
    {
        int a=longest(root->left,'L');
        int b=longest(root->right,'R');
        
        max_ans=max(max_ans,max(a,b));
        return max(a,b);
    }
    else if(drxn=='L')
    {
        int p=longest(root->right,'R');
        int a=longest(root->left,'L');
        int ans=p+1;
        max_ans=max(ans,max_ans);
        max_ans=max(max_ans,a);
        return ans;
    }
   
    int p=longest(root->left,'L');
    int a=longest(root->right,'R');
    
    int ans=p+1;
    max_ans=max(ans,max_ans);
    max_ans=max(max_ans,a);
    return ans;
    
}
class Solution 
{
public:
    int longestZigZag(TreeNode* root) 
    {
        max_ans=0;
        longest(root,'A');
        return max_ans;
    }
};


//Method-2 : 

int max_ans=0;
void longest(TreeNode *root,int l,int r)
{
    if(root==NULL)
        return;
    max_ans=max(max_ans,l);
    max_ans=max(max_ans,r);
    
    longest(root->left,0,l+1);
    longest(root->right,r+1,0);
    
}
class Solution 
{
public:
    int longestZigZag(TreeNode* root) 
    {
        max_ans=0;
        int l=0;
        int r=0;
        longest(root,l,r);
        return max_ans;
    }
};


//Method-3 : By DP

int max_ans=0;
int longest(TreeNode *root,char drxn, map<pair<TreeNode*,char>,int>&mp)
{
    if(root==NULL)
        return 0;
    if(mp.find(make_pair(root,drxn))==mp.end())
    {
        if(drxn=='A')
        {
            int a=longest(root->left,'L',mp);
            int b=longest(root->right,'R',mp);
            
            max_ans=max(max_ans,max(a,b));
            return mp[make_pair(root,drxn)]=max(a,b);
        }
        else if(drxn=='L')
        {
            int p=longest(root->right,'R',mp);
            int a=longest(root->left,'L',mp);
            int ans=p+1;
            max_ans=max(ans,max_ans);
            max_ans=max(max_ans,a);
            return mp[make_pair(root,drxn)]=ans;
        }
       
        int p=longest(root->left,'L',mp);
        int a=longest(root->right,'R',mp);
        
        int ans=p+1;
        max_ans=max(ans,max_ans);
        max_ans=max(max_ans,a);
        return mp[make_pair(root,drxn)]=ans;
    }
    return mp[make_pair(root,drxn)];
    
}
class Solution 
{
public:
    int longestZigZag(TreeNode* root) 
    {
        max_ans=0;
        map<pair<TreeNode*,char>,int>mp;
        longest(root,'A',mp);
        return max_ans;
    }
};
