//Method-1 : With extra space


int maxf=0;
void dfs(TreeNode *root,map<int,int>&mp)
{
    if(root==NULL)
        return;
    mp[root->val]++;
    maxf=max(maxf,mp[root->val]);
    dfs(root->left,mp);
    dfs(root->right,mp);
}
class Solution 
{
public:
    vector<int> findMode(TreeNode* root) 
    {
        map<int,int>mp;
        vector<int>ans;
        maxf=0;
        dfs(root,mp);
        for(auto x:mp)
        {
            if(x.second==maxf)
                ans.push_back(x.first);
        }
        return ans;
    }
};


//Method-2 in O(1) Space


void inorder(TreeNode *root,vector<int>&ans,int &cnt,int &mx,int &prev)
{
    if(root==NULL)
        return;
    inorder(root->left,ans,cnt,mx,prev);
    if(root->val==prev)
        cnt++;
    else
        cnt=1;
    if(cnt==mx)
        ans.push_back(root->val);
    if(cnt>mx)
    {
        ans.clear();
        ans.push_back(root->val);
        mx=cnt;
    }
    prev=root->val;
    inorder(root->right,ans,cnt,mx,prev);
}
class Solution 
{
public:
    vector<int> findMode(TreeNode* root) 
    {
        vector<int>ans;
        int cnt=0;
        int prev=-1;
        int mx=0;
        inorder(root,ans,cnt,mx,prev);
        return ans;
    }
};
