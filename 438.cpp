//Method-1 : 

int match(vector<int>&dp,vector<int>&curr)
{
    bool a=true;
    for(int i=0;i<26;i++)
    {
        if(curr[i]>dp[i])
        {
            return -1;
        }
        if(curr[i]<dp[i])
        {
            a=false;
        }
    }
    if(a==false)
        return 0;
    return 1;
}
class Solution 
{
public:
    vector<int> findAnagrams(string s, string p) 
    {
        vector<int>ans;
        vector<int>dp(26,0);
        for(int i=0;i<p.size();i++)
        {
            dp[int(p[i])-97]++;
        }
        vector<int>curr(26,0);
        int left=0;
        for(int i=0;i<s.size();i++)
        {
            if(dp[int(s[i])-97]==0)
            {
                left=i+1;
                curr.clear();
                curr.resize(26,0);
                continue;
            }
            curr[int(s[i])-97]++;
            int a=match(dp,curr);
            if(a==0)
            {
                continue;
            }
            while(left<=i && match(dp,curr)==-1)
            {
                curr[int(s[left])-97]--;
                left++;
                continue;
            }
            while(left<=i && match(dp,curr)==1)
            {
                ans.emplace_back(left);
                curr[int(s[left])-97]--;
                left++;
            }
        }
        return ans;
    }
};

//Method-2 : 

class Solution 
{
public:
    vector<int> findAnagrams(string s, string p) 
    {
        vector<int>ans;
        vector<int>dp(26,0);
        vector<int>curr(26,0);
        if(s.size()<p.size())
        {
            return {};
        }
        for(int i=0;i<p.size();i++)
        {
            dp[p[i]-'a']++;
            curr[s[i]-'a']++;
        }
        if(dp==curr)
        {
            ans.emplace_back(0);
        }
        for(int i=p.size();i<s.size();i++)
        {
            curr[s[i-p.size()]-'a']--;
            curr[s[i]-'a']++;
            
            if(curr==dp)
            {
                ans.emplace_back(i-p.size()+1);
            }
        }
        return ans;
    }
};
