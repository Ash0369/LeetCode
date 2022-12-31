class Solution 
{
public:
    string largestGoodInteger(string num) 
    {
        int ans=-1;
        int n=num.size();
        for(int i=0;i<n-2;i++)
        {
            if(num[i]==num[i+1] && num[i+1]==num[i+2])
            {
                ans=max(ans,num[i]-'0');
            }
        }
        if(ans==-1)
            return "";
        
        string s;
        s.push_back(ans+'0');
        s.push_back(ans+'0');
        s.push_back(ans+'0');
        return s;
    }
};
