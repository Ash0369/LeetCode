class Solution 
{
public:
    int minDeletionSize(vector<string>& strs) 
    {
        int n=strs[0].size();
        vector<char>vec[n];
        
        for(auto x:strs)
        {
            for(int i=0;i<n;i++)
            {
                vec[i].push_back(x[i]);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(!is_sorted(vec[i].begin(),vec[i].end()))
                cnt++;
        }
        return cnt;
    }
};
