vector<TreeNode*> generate(int start,int end)
{
    if(start==end)
    {
        return {new TreeNode(start)};
    }
    if(start>end)
        return {NULL};
    
    vector<TreeNode*>res;
    for(int i=start;i<=end;i++)
    {
        vector<TreeNode*>left=generate(start,i-1);
        vector<TreeNode*>right=generate(i+1,end);
        
        for(auto l:left)
        {
            for(auto r:right)
            {
                res.push_back(new TreeNode(i,l,r));
            }
        }
    }
    return res;  
}
class Solution 
{
public:
    vector<TreeNode*> generateTrees(int n) 
    {
        return generate(1,n);
    }
};
