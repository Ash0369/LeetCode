class Solution 
{
public:
    string shortestBeautifulSubstring(string s, int k) 
    {
        int n=s.size();
        string ans="2";
        int left=0;
        int cnt=0;
        for(int right=0;right<n;right++)
        {
            if(s[right]=='1')
            {
                cnt++;
            }
            while(cnt>k)
            {
                if(s[left]=='1')
                {
                    cnt--;
                }
                left++;
            }
            while(cnt==k && s[left]=='0')
            {
                left++;
            }
            if(cnt==k)
            {
                string temp="";
                for(int i=left;i<=right;i++)
                {
                    temp.push_back(s[i]);
                }
                if(ans[0]=='2')
                {
                     ans=temp;
                }
                else if(temp.size()<ans.size())
                {
                    ans=temp;
                }
                else if(temp.size()==ans.size())
                {
                    if(temp<ans)
                    {
                        ans=temp;
                    }
                }
            }
        }
        if(ans[0]=='2')
        {
            ans.pop_back();
        }
        return ans;
    }
};
