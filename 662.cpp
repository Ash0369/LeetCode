class Solution 
{
public:
    int widthOfBinaryTree(TreeNode* root) 
    {
        deque<pair<long long int,TreeNode*>>dq;
        dq.push_back(make_pair(0,root));
        // dq.push_back(make_pair(0,NULL));

        long long int ans=INT_MIN;

        while(!dq.empty())
        {
            int n=dq.size();

            long long int start=dq.front().first;
            long long int end=dq.back().first;
            ans=max(ans,end-start);

            long long int min_at_level=dq.front().first;
            for(int i=0;i<n;i++)
            {
                TreeNode *temp=dq.front().second;
                long long int index=dq.front().first-min_at_level+1;
                if(temp->left)
                {
                    dq.push_back(make_pair((2*index)+1,temp->left));
                }
                if(temp->right)
                {
                    dq.push_back(make_pair((2*index)+2,temp->right));
                }
                dq.pop_front();
            }

        }
        return ans+1;
    }
    
};
