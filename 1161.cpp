//Method-1 : BFS

class Solution 
{
public:
    int maxLevelSum(TreeNode* root) 
    {
        queue<TreeNode*>q;
        q.push(root);
        int minimal=INT_MIN;
        int level;
        int x=0;
        while(!q.empty())
        {
            int k=q.size();
            int sum=0;
            x++;
            for(int i=0;i<k;i++)
            {
                auto top=q.front();
                sum=sum+top->val;
                q.pop();
                if(top->left)
                    q.push(top->left);
                if(top->right)
                    q.push(top->right);
                
            }
            if(sum>minimal)
            {
                minimal=sum;
                level=x;
            }
            
        }
        return level;
    }
};
