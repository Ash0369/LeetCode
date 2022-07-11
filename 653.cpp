//Method-1:Space Complexity is O(n) and Time Complexity is O(n)

unordered_map<int,int>mp;

void make_map(TreeNode* root)
{
    if(root==NULL)
    {
        return;
    }
    mp[root->val]++;
    make_map(root->left);
    make_map(root->right);
}

class Solution 
{
public:
    bool findTarget(TreeNode* root, int k) 
    {
        mp.clear();
        make_map(root);
        for(auto x:mp)
        {
            int a=x.first;
            int b=k-a;
            if(mp.find(b)!=mp.end() && a!=b)
            {
                return true;
            }
        }
        return false;
    }
};

//Method-2:Space Complexity is O(n) and Time Complexity is O(n)

vector<int>inorder;
void inorder_traversal(TreeNode* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder_traversal(root->left);
    inorder.push_back(root->val);
    inorder_traversal(root->right);
}
class Solution 
{
public:
    bool findTarget(TreeNode* root, int k) 
    {
        inorder.clear();
        inorder_traversal(root);
        int left=0;
        int right=inorder.size()-1;
        while(right>left)
        {
            if(inorder[left]+inorder[right]==k)
            {
                return true;
            }
            if(inorder[left]+inorder[right]>k)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        return false;
    }
};

//Method-3 O(n) Time Complexity and O(h) Space Complexity

class Solution 
{
public:

    stack<TreeNode*>next;
    stack<TreeNode*>before;
    
    void fill_next(TreeNode* root)
    {
        while(root!=NULL)
        {
            next.push(root);
            root=root->left;
        }
    }

    void fill_before(TreeNode* root)
    {
        while(root!=NULL)
        {
            before.push(root);
            root=root->right;
        }
    }
    bool findTarget(TreeNode* root, int k) 
    {
        next.empty();
        before.empty();

        fill_next(root);
        fill_before(root);

        while(!next.empty() && !before.empty() && (next.top()->val!=before.top()->val))
        {
            TreeNode* a=next.top();
            TreeNode* b=before.top();

            if(a->val+b->val==k)
            {
                return true;
            }
            if((a->val+b->val)<k)
            {
                TreeNode* temp=a;
                next.pop();
                fill_next(temp->right);
            }
            else if((a->val+b->val)>k)
            {
                TreeNode* temp=b;
                before.pop();
                fill_before(temp->left);
            }
        }
        return false;
    }
};
