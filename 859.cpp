class Solution 
{
public:
    bool buddyStrings(string s, string goal) 
    {
        int cnt=0;
        map<char,int>mp;
        bool ava=false;
        if(s.size()!=goal.size())
        {
            return 0;
        }
        int x=-1;
        int n=s.size();
        
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
            if(mp[s[i]]==2)
            {
                ava=true;
            }
            if(s[i]!=goal[i])
            {
                if(x==-1)
                {
                    x=i;
                }
                else
                {
                    swap(s[i],s[x]);
                    if(s==goal)
                    {
                        return true;
                    }
                    return false;
                }
            }
        }
        return ava && x==-1;
    }
};
