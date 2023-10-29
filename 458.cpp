class Solution 
{
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) 
    {
        int t=minutesToTest/minutesToDie;
        
        int ans=0;
        int av=1;
        
        while(av<buckets)
        {
            av=av*(t+1);
            ans++;
        }
        return ans;
    }
};
