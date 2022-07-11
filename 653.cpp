//Space Complexity is O(n) and Time Complexity is O(n)

unordered_map<int,int>mp;

void make_map(TreeNode* root)
{
    if(root==NULL)
    {
        return;
    }
    mp[root->val]++;
    make_map(root->left);
    make_map(root->right);
}

class Solution 
{
public:
    bool findTarget(TreeNode* root, int k) 
    {
        mp.clear();
        make_map(root);
        for(auto x:mp)
        {
            int a=x.first;
            int b=k-a;
            if(mp.find(b)!=mp.end() && a!=b)
            {
                return true;
            }
        }
        return false;
    }
};
