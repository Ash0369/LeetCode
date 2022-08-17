class Solution 
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        if(root==NULL)
        {
            return {};
        }
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<vector<int>>result;
        vector<int>temp;
        int k=1;
        while(!q.empty() && !(q.size()==1 && temp.empty()))
        {
            if(q.front()==NULL)
            {
                q.pop();
                if(k%2==0)
                {
                    reverse(temp.begin(),temp.end());
                }
        
                result.push_back(temp);
                q.push(NULL);
                temp.clear();
                k++;
                continue;
            }
            temp.push_back(q.front()->val);
            if(q.front()->left!=NULL)
            {
                q.push(q.front()->left);
            }
            if(q.front()->right!=NULL)
            {
                q.push(q.front()->right);
            }
            q.pop();
        }
        return result;
    }
};
