//Method-1

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

//Method-2

vector<int>result;
//Checking at childrens of the root.
void nodes_child(TreeNode* target,int k)
{
    if(target==NULL)
    {
        return ;
    }
    if(k<0)
    {
        return;
    }
    if(k==0)
    {
        result.push_back(target->val);
        return;
    }
    else
    {
        nodes_child(target->left,k-1);
        nodes_child(target->right,k-1);
    }

}

//Checking at ancestors

int nodes_ancestors(TreeNode* root,TreeNode* target,int k)
{
    if(root==NULL)
    {
        return -1 ;
    }
    if(root==target)
    {
        nodes_child(target,k); //As we found our target Node so we will print childrens at distance k

        return 0;//As it is target node , so it's distance from target node is 0
    }

    int dl=nodes_ancestors(root->left,target,k); //we are finding distance of target node from our left child of root.

    if(dl!=-1)//We able to find target
    {
        if(dl+1==k)
        {
            //Current node is at k distance as dl is distance of left child and we are adding 1 to it.
            result.push_back(root->val);
        }
        else
        {
            //We will check subtree of ancestor then , as we got target in left subtree so we will check right subtree

            nodes_child(root->right,k-dl-2); 
            //As we already travel distnace dl
            //then 1 unit to root 
            //and 1 unit to right child
            //Net=dl+2
            //So distance left with us k-dl-2

        }
        return 1+dl;//distance of root from target
    }

    //Perform same for right subtree

    int dr=nodes_ancestors(root->right,target,k); //we are finding distance of target node from our right child of root.

    if(dr!=-1)//We able to find target
    {
        if(dr+1==k)
        {
            //Current node is at k distance as dl is distance of right child and we are adding 1 to it.
            result.push_back(root->val);
        }
        else
        {
            //We will check subtree of ancestor then , as we got target in right subtree so we will check left subtree

            nodes_child(root->left,k-dr-2); 
            //As we already travel distnace dr
            //then 1 unit to root 
            //and 1 unit to left child
            //Net=dl+2
            //So distance left with us k-dl-2

        }
        return 1+dr;//distance of root from target
    }

    return -1;


}

class Solution 
{
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        result.clear();
        nodes_ancestors(root,target,k);
        return result;
    }
};
