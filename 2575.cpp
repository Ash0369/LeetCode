class Solution 
{
public:
    vector<int> divisibilityArray(string word, int m) 
    {
        int n=word.size();
        vector<int>ans(n,0);
        long long int r=0;
        for(int i=0;i<n;i++)
        {
            int val=word[i]-'0';
            r=(r*10)%m;
            r=(r+val)%m;
            if(r==0)
            {
                ans[i]=1;
            }
        }
        return ans;
    }
};
