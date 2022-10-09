int sbtree(TreeNode *root,map<int,int>&m,int &f)
{
    if(root==NULL)
        return 0;
    int sum=root->val+sbtree(root->left,m,f)+sbtree(root->right,m,f);
    
    if(m[sum]==f)
    {
        m[sum]+=1;
        f++;
    }
    else
        m[sum]+=1;
    
    return sum;
    
}
class Solution 
{
public:
    vector<int> findFrequentTreeSum(TreeNode* root) 
    {
        int f=0;
        map<int,int>mp;
        sbtree(root,mp,f);
        
        vector<int>res;
        for(auto x:mp)
        {
            if(x.second==f)
                res.push_back(x.first);
        }
        return res;
    }
};
