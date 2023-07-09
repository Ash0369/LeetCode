class Solution 
{
public:
    int largestVariance(string s) 
    {
        int ans=0;
        for(char a='a';a<='z';a++)
        {
            for(char b='a';b<='z';b++)
            {
                if(a==b)
                {
                    continue;
                }
                // we have 2 pair , now just compare
               
                //Now find maximum sum
                int m=2;
                while(m--)
                {
                    int cnt1=0;
                int cnt2=0;
                for(auto x:s)
                {
                    if(x==a)
                    {
                        cnt1++;
                    }
                    else if(x==b)
                    {
                        cnt2++;
                    }
                    if(cnt2>cnt1)
                    {
                        cnt1=0;
                        cnt2=0;
                    }
                    if(cnt1>0 && cnt2>0)
                    {
                        ans=max(ans,abs(cnt1-cnt2));
                    }
                }
                    reverse(s.begin(),s.end());
                }
            }
        }
        return ans;
    }
};
