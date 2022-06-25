class Solution {
public:
    int countAsterisks(string s)
    {
        int n=s.length();
        int count=0;
        int bar=0;
        for(int i=0;i<n;i++)
        {
            char c=s[i];
            if(c=='|')
            {
                bar++;
            }
            else if(c=='*')
            {
                if(bar%2==0)
                {
                    count++;
                }
            }
        }
        return count;
    }
};
