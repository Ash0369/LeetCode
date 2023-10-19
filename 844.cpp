class Solution 
{
public:
    bool backspaceCompare(string s, string t) 
    {
        string ans1="";
        for(auto x:s)
        {
            if(x!='#')
            {
                ans1.push_back(x);
            }
            else
            {
                if(ans1.size()>0)
                {
                    ans1.pop_back();
                }
            }
        }
        
        string ans2="";
        for(auto x:t)
        {
            if(x!='#')
            {
                ans2.push_back(x);
            }
            else
            {
                if(ans2.size()>0)
                {
                    ans2.pop_back();
                }
            }
        }
        
        return ans1==ans2;
    }
};
