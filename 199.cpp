vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> result;
    deque<TreeNode *> data;
    if (root == NULL)
    {
        result = {};
        return result;
    }
    vector<int> temp = {root->val};
    result.push_back(temp);
    data.push_back(root);
    data.push_back(NULL);
    temp.clear();
    while (!data.empty() && data.size() != 1)
    {
        if (data.front() != NULL)
        {
            if (data.front()->left)
            {
                data.push_back(data.front()->left);
                temp.push_back(data.front()->left->val);
            }
            if (data.front()->right)
            {
                data.push_back(data.front()->right);
                temp.push_back(data.front()->right->val);
            }
            data.pop_front();
        }
        else if (data.front() == NULL)
        {
            data.pop_front();
            data.push_back(NULL);
            result.push_back(temp);
            temp.clear();
        }
    }
    return result;
}
class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<vector<int>>result;
        vector<int>res;
        result=levelOrder(root);
        for(int i=0;i<result.size();i++)
        {
            vector<int>temp;
            temp=result[i];
            res.push_back(temp[temp.size()-1]);
        }
        return res;
    }
};
