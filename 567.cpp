bool check( vector<int>&dp)
{
    for(int i=0;i<26;i++)
    {
        if(dp[i]>0)
        {
            return false;
        }
    }
    return true;
}
class Solution 
{
public:
    bool checkInclusion(string s1, string s2) 
    {
        vector<int>dp1(26,0);//Curr frequency
        vector<int>dp2(26,0);//Actual frequency
        
        for(int i=0;i<s1.length();i++)
        {
            int x=int(s1[i])-97;
            dp1[x]++;
            dp2[x]++;
        }
        int left=0;
        int right=0;
        for(right=0;right<s2.size();right++)
        {
            int x=int(s2[right])-97;
            if(dp1[x]==0)
            {
                while(left<right && dp1[x]==0)
                {
                    int y=int(s2[left])-97;
                    if(dp2[y]>dp1[y])
                    {
                        dp1[y]++;
                    }
                    left++; 
                }
                if(left==right)
                {
                    continue;
                }
            }
            dp1[x]--;
            if(check(dp1))
                return true;  
        }
        return false;
    }
};
