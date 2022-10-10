class Solution 
{
public:
    vector<int> largestValues(TreeNode* root) 
    {
        if(root==NULL)
            return {};
        queue<TreeNode*>q;
        q.push(root);
        
        vector<int>result;
        
        while(!q.empty())
        {
            int k=q.size();
            int val=INT_MIN;
            for(int i=0;i<k;i++)
            {
                auto x=q.front();
                q.pop();
                val=max(x->val,val);
                if(x->left)
                    q.push(x->left);
                if(x->right)
                    q.push(x->right);
            }
            result.push_back(val);
        }
        return result;
    }
};
