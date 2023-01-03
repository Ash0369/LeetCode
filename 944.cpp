//Method-1 : 

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


//Method-2 : 


class Solution 
{
public:
    int minDeletionSize(vector<string>& strs) 
    {
        int n=strs[0].size();
        int m=strs.size();
        
        int cnt=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(strs[j][i]<strs[j-1][i])
                {
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};
