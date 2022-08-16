//Method-1 : 

class Solution 
{
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
       
        vector<vector<int>>result;
        deque<TreeNode*>data;
        if(root==NULL)
        {
            result={};
            return result;
        }
        vector<int>temp={root->val};
        result.push_back(temp);
        data.push_back(root);
        data.push_back(NULL);
        temp.clear();
        while(!data.empty() && data.size()!=1)
        {
            if(data.front()!=NULL)
            {
                if(data.front()->left)
                {
                    data.push_back(data.front()->left);
                    temp.push_back(data.front()->left->val);
                }

                if(data.front()->right)
                {
                    data.push_back(data.front()->right);
                    temp.push_back(data.front()->right->val);
                }

                data.pop_front();
            }
            else if(data.front()==NULL)
            {
                data.pop_front();
                data.push_back(NULL);
                result.push_back(temp);
                temp.clear();
            }
        }
        return result;
    }
};


//Method-2 : 

class Solution 
{
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if(root==NULL)
        {
            return {};
        }
        vector<vector<int>>result;
        vector<int>level;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty() && (!level.empty() || q.size()!=1))
        {
            if(q.front()==NULL)
            {
                q.pop();
                q.push(NULL);
                result.push_back(level);
                level.clear();
                continue;
            }
            if(q.front()->left!=NULL)
            {
                q.push(q.front()->left);
            }
            if(q.front()->right!=NULL)
            {
                q.push(q.front()->right);
            }
            level.push_back(q.front()->val);
            q.pop();
        }
        return result;
    }
};
