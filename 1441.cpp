class Solution 
{
public:
    vector<string> buildArray(vector<int>& target, int n) 
    {
        vector<string>ans;
        int j=0;
        for(int i=1;i<=n;i++)
        {
            if(j==target.size())
            {
                break;
            }
            ans.push_back("Push");
            if(target[j]==i)
            {
                j++;
                continue;
            }
            else{
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};
