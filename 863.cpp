void mark_parent(unordered_map<TreeNode*,TreeNode*>&parent_track,TreeNode* root,TreeNode* target)
{
    deque<TreeNode*>dq;
    dq.push_back(root);
    while(!dq.empty())
    {
        TreeNode* current=dq.front();
        dq.pop_front();
        if(current->left)
        {
            parent_track[current->left]=current;
            dq.push_back(current->left);
        }
        if(current->right)
        {
            parent_track[current->right]=current;
            dq.push_back(current->right);
        }
    }
}
class Solution 
{
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        unordered_map<TreeNode*,TreeNode*>parent_track;
        mark_parent(parent_track,root,target);
        
        unordered_map<TreeNode* ,bool>visited;
        deque<TreeNode*>dq;
        dq.push_back(target);
        visited[target]=true;
        int curr_level=0;
        while(!dq.empty())
        {
            int size=dq.size();
            if(curr_level==k)
            {
                break;//As we reaced.
            }
            else
            {
                curr_level++;//Moving radialy outward
            }

            for(int i=0;i<size;i++)
            {
                TreeNode* current=dq.front();
                dq.pop_front();

                if(current->left &&!visited[current->left])
                {
                    dq.push_back(current->left);
                    visited[current->left]=true;
                }

                if(current->right &&!visited[current->right])
                {
                    dq.push_back(current->right);
                    visited[current->right]=true;
                }

                if(parent_track[current]&&!visited[parent_track[current]])
                {
                    dq.push_back(parent_track[current]);
                    visited[parent_track[current]]=true;
                }
            }
        }
        vector<int>result;
        while(!dq.empty())
        {
            result.push_back(dq.front()->val);
            dq.pop_front();
        }
        return result;

    }
};
