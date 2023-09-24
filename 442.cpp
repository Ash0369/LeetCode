class Solution 
{
public:
    vector<int> findDuplicates(vector<int>&vec) 
    {
        int n=vec.size();
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            int ele=abs(vec[i]);
            if(vec[ele-1]<0)
            {
                ans.push_back(ele);
            }
            vec[ele-1]=vec[ele-1]*(-1);
        }
        return ans;
    }
};
