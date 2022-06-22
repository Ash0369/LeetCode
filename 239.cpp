class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        vector<int>vec;
        multiset<int>wind;
        int n=nums.size();
        int max_num=INT_MIN;
        for(int i=0;i<k;i++)
        {
            wind.insert(nums[i]);
        }
        vec.push_back(*(wind.rbegin())); //rbegin() gives pointer at last element(which is maximum) of the set 
        int drop=0;
        for(int i=k;i<n;i++)
        {
            auto pos=wind.find(nums[drop]);
            wind.erase(pos);
            drop++;
            wind.insert(nums[i]);

            vec.push_back(*(wind.rbegin()));
        }

        return vec;
        
    }
};
