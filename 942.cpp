//Method-1 : 

class Solution 
{
public:
    vector<int> diStringMatch(string s) 
    {
        vector<int>ans(s.length()+1,0);
        int cnt=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='D')
            {
                cnt++;
            }
        }
        ans[0]=cnt;
        int low=cnt-1;
        int high=cnt+1;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='I')
                ans[i+1]=high++;
            else
                ans[i+1]=low--;
        }
        return ans;
    }
};

//Method-2 : 

class Solution 
{
public:
    vector<int> diStringMatch(string s) 
    {
        vector<int>ans(s.length()+1,0);
        int low=0;
        int high=s.size();
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='I')
                ans[i]=low++;
            else
                ans[i]=high--;
        }
        ans[s.size()]=high;
        //ans[s.size()]=low; will also work
        return ans;
    }
};
