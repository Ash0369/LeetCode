vector<vector<int>>result;
void combiantion(int target,vector<int>cs,int sum,int k,int ele,int prev)
{
    if(k==ele && sum==target)
    {
        result.push_back(cs);
        return;
    }
    if(k==ele && sum!=target)
    {
        return;
    }
    if(sum==target && k!=ele)
    {
        return;
    }
    if(prev==9)
    {
        return;
    }
    if(prev>target)
    {
        return;
    }
    cs.push_back(prev+1);
    combiantion(target,cs,sum+prev+1,k,ele+1,prev+1);
    cs.pop_back();
    combiantion(target,cs,sum,k,ele,prev+1);
}
class Solution 
{
public:
    vector<vector<int>> combinationSum3(int k,int n) 
    {
        result.clear();
        vector<int>cs;
        for(int i=1;i<=9;i++)
        {
            cs.push_back(i);
            combiantion(n,cs,i,k,1,i);
            cs.pop_back();
        }
        return result;
    }
};
