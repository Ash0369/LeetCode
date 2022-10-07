int ans=0;
vector<int> dfs(TreeNode *root,int d)
{
    vector<int>p;
    if(root==NULL)
        return p;
    auto left=dfs(root->left,d);
    auto right=dfs(root->right,d);
    
    if(left.size()==0 && right.size()==0)
    {
        p.push_back(1);
        return p;
    }
    
    for(int i=0;i<left.size();i++)
    {
        for(int j=0;j<right.size();j++)
        {
            if(left[i]+right[j] <=d)
                ans++;
        }
    }
    
    for(int i=0;i<left.size();i++)
    {
        p.push_back(left[i]+1);
    }
    
    for(int i=0;i<right.size();i++)
    {
        p.push_back(right[i]+1);
    }
    return p;
}
class Solution 
{
public:
    int countPairs(TreeNode* root, int distance) 
    {
        ans=0;
        dfs(root,distance);
        return ans;
    }
};
