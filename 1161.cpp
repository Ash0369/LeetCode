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


//Method-2 : DFS

class Solution 
{
public:
    int sum[100];
    int mx_level=0;
    void dfs(TreeNode *root,int level)
    {
      
        mx_level=max(mx_level,level);
        sum[level]=sum[level]+root->val;
        if(root->left) dfs(root->left,level+1);
        if(root->right) dfs(root->right,level+1);
    }
    int maxLevelSum(TreeNode* root) 
    {
        int level=0;
        int val=INT_MIN;
        dfs(root,0);
        for(int i=0;i<=mx_level;i++)
        {
            if(sum[i]>val)
            {
                val=sum[i];
                level=i;
            }
        }
        return level+1;
    }
};
