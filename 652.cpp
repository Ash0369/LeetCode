unordered_map<string,vector<TreeNode*>>mp;
string dup(TreeNode *root)
{
    if(root==NULL)
        return "";
    string l=dup(root->left);
    string r=dup(root->right);
    
    string temp="";
    temp=temp+to_string(root->val)+"-"+l+"-"+r;
    mp[temp].push_back(root);
    return temp;
}
class Solution 
{
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
    {
        mp.clear();
        vector<TreeNode*>res;
        dup(root);
        for(auto x:mp)
        {
            if(x.second.size()>1)
            {
                res.push_back(x.second[0]);
            }
        }
        return res;
    }
};
