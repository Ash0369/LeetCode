class Solution 
{
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) 
    {
        int low=1;
        int high=1000;
        vector<vector<int>>ans;
        while(high>0 && low<=1000)
        {
            int res=customfunction.f(low,high);
            if(res==z)
            {
                ans.push_back({low,high});
                low++;
                high--;
            }
            else if(res>z)
                high--;
            else
                low++;
        }
        return ans;
    }
};
