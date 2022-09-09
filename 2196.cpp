//Method-1 :

void make_tree(TreeNode *root,map<int,vector<pair<int,int>>>&mp)
{
    if(root==NULL)
        return;
    
    for(int i=0;i<mp[root->val].size();i++)
    {
        int l=mp[root->val][i].second;
        int d=mp[root->val][i].first;
        
        TreeNode *temp=new TreeNode(d);
        
        if(l==1)
            root->left=temp;
        else
            root->right=temp;
    }
    
    make_tree(root->left,mp);
    make_tree(root->right,mp);
    
}
class Solution 
{
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) 
    {
        set<int>parent;
        set<int>child;
        map<int,vector<pair<int,int>>>mp;
        for(auto x:descriptions)
        {
            parent.insert(x[0]);
            child.insert(x[1]);
            mp[x[0]].push_back(make_pair(x[1],x[2]));
        }
        TreeNode *root=new TreeNode(-1);
        for(auto x:parent)
        {
            if(child.find(x)==child.end())
            {
                root->val=(x);
                break;
            }
        }
        make_tree(root,mp);
        return root;
    }
};


//Method-2 :

class Solution 
{
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) 
    {
        unordered_set<int>pat;
        unordered_set<int>chd;
        unordered_map<int,TreeNode *>mp;
        for(auto x:descriptions)
        {
            TreeNode *parent;
            if(mp.find(x[0])==mp.end())
            {
                TreeNode *node=new TreeNode(x[0]);
                mp[x[0]]=node;
            }
            
            TreeNode *child;
            if(mp.find(x[1])==mp.end())
            {
                TreeNode *node=new TreeNode(x[1]);
                mp[x[1]]=node;
            }
            parent=mp[x[0]];
            child=mp[x[1]];
            if(x[2]==1)
                parent->left=child;
            else
                parent->right=child;
            
            pat.insert(x[0]);
            chd.insert(x[1]);
        }
        for(auto x:pat)
        {
            if(chd.find(x)==chd.end())
                return mp[x];
        }
        return NULL;
    }
};
