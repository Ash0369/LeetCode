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
    cs.push_back(candidates[index]);
    combiantion(candidates,target,cs,sum+candidates[index],index+1);
    int temp=candidates[index];
    cs.pop_back();
    while(index<candidates.size() && candidates[index]==temp)
    {
        index++;
    }
    combiantion(candidates,target,cs,sum,index);
}
class Solution 
{
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        result.clear();
        vector<int>cs;
        sort(candidates.begin(),candidates.end());
        combiantion(candidates,target,cs,0,0);
        return result;
    }
};
