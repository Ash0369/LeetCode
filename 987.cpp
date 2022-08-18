void fill_map(TreeNode* root,map<int,map<int,multiset<int>>>&mp,int index,int level)
{
    if(root==NULL)
    {
        return;
    }
    mp[index][level].insert(root->val);

    if(root->right)
    {
        fill_map(root->right,mp,index+1,level+1);
    }
    if(root->left)
    {
        fill_map(root->left,mp,index-1,level+1);
    }
}
class Solution 
{
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        map<int,map<int,multiset<int>>>mp;
        fill_map(root,mp,0,0);
        vector<vector<int>>result;
        vector<int>temp;

        for(auto x:mp)
        {
            for(auto y:x.second)
            {
                for(auto z:y.second)
                {
                    temp.push_back(z);
                }
            }
            result.push_back(temp);
            temp.clear();
        }
        return result;
    }
};
