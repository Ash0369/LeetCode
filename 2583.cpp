#define ll long long
class Solution 
{
public:
    long long kthLargestLevelSum(TreeNode* root, int k) 
    {
        vector<ll int>sum;
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        while(!q.empty())
        {
            int sz=q.size();
            sum.push_back(0);
            while(sz--)
            {
                sum[level]+=q.front()->val;
                TreeNode *node=q.front();
                q.pop();
                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
            }
            level++;
        }
        if(sum.size()<k)
        {
            return -1;
        }
        sort(sum.begin(),sum.end(),greater<ll int>());
        return sum[k-1];
        
    }
};
