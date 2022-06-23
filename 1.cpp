//Method -1 O(n*n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int>res;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int a=nums[i];
            for(int j=i+1;j<n;j++)
            {
                int b=nums[j];
                if((a+b)==target)
                {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
        return res;
    }
};

//Method 2 O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int>res;
        int n=nums.size();
        map<int,int>Hash;
        for(int i=0;i<n;i++)
        {
            int a =nums[i];
            int b=target-a;
            if(Hash.find(b)==Hash.end())
            {
                Hash.insert({a,i});
            }
            else
            {
                res.push_back(i);
                res.push_back(Hash[b]);
                return res;

            }
        }
        return res;

    }
};
