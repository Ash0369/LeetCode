class Solution 
{
public:
    int sw(string &s,int k,char c)
    {
        int ans=0;
        int j=0;
        int n=s.size();
        int opp=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=c)
            {
                opp++;
            }
            while(opp>k)
            {
                if(s[j]!=c)
                {
                    opp--;
                }
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
    int maxConsecutiveAnswers(string answerKey, int k) 
    {
        return max(sw(answerKey,k,'T'),sw(answerKey,k,'F'));
    }
};
