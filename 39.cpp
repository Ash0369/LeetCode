vector<vector<int>>result;
void combiantion(vector<int>&candidates,int target,vector<int>cs,int sum,int index)
{
    if(sum>target)
    {
        return;
    }
    if(index>=candidates.size() && sum!=target)
    {
        return;
    }
    if(sum==target)
    {
        result.push_back(cs);
        return;
    }
    int a=(target-sum)/candidates[index];
    for(int i=1;i<=a;i++)
    {
        cs.push_back(candidates[index]);
        combiantion(candidates,target,cs,sum+(i*candidates[index]),index+1);
    }
    for(int i=1;i<=a;i++)
    {
        cs.pop_back();
    }
    combiantion(candidates,target,cs,sum,index+1);
}
class Solution 
{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        result.clear();
        vector<int>cs;
        combiantion(candidates,target,cs,0,0);
        return result;
    }
};
