class Solution 
{
public:
    int minCostToMoveChips(vector<int>& position) 
    {
        //We can either place all coin at a odd index or a even index and cost will be
        //Same for all odd and same for all even.
        int n=position.size();
        int odd=0;
        int even=0;
        for(int i=0;i<n;i++)
        {
            if(position[i]%2==0)
                even++;
            else
                odd++;
        }
        if(even>odd)
            return odd;
        return even;
    }
};
