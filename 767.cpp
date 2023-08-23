class Solution 
{
public:
    string reorganizeString(string s) 
    {
        int n=s.size();
        map<char,int>mp;
        for(auto x:s)mp[x]++;
        
        string ans(n,'a');
        int mx=0;
        char c;
        for(auto x:mp)
        {
            if(x.second>mx)
            {
                mx=x.second;
                c=x.first;
            }
        }
        int i=0;
        while(mx>0)
        {
            
            if(i>=n) return "";
            ans[i]=c;
            mx--;
            i=i+2;
        }
        for(auto x:mp)
        {
            if(x.first!=c)
            {
                int p=x.second;
                while(p--)
                {
                    if(i>=n) i=1;
                    ans[i]=x.first;
                    i=i+2;
                    
                }
            }
        }
        return ans;
    }
};
