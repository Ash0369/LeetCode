//Method-1 : 

class Solution 
{
public:
    long long int ans=0;
    void dfs(TreeNode *root,long long int target)
    {
        if(root==NULL)
            return;
        
        if(root->val==target)
            ans++;
        
        dfs(root->left,target-root->val);
        dfs(root->right,target-root->val);
    }
    int pathSum(TreeNode* root, int targetSum) 
    {
        if(!root)
            return 0;
        dfs(root,targetSum);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);        
        return ans;
    }
};


//Method-2 : 

class Solution 
{
public:
    long long int ans=0;
    unordered_map<long long int ,int>mp;
    void dfs(TreeNode *root,int target,long long int sum)
    {
        if(root==NULL)
            return;
        
        sum=sum+root->val;
        if(sum==target)
            ans++;
        if(mp.find(sum-target)!=mp.end())
            ans=ans+mp[sum-target];
        mp[sum]++;
        dfs(root->left,target,sum);
        dfs(root->right,target,sum);
        
        mp[sum]--;
    }
    int pathSum(TreeNode* root, int targetSum) 
    {
        dfs(root,targetSum,0);        
        return ans;
    }
};
