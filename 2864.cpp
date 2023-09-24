class Solution 
{
public:
    string maximumOddBinaryNumber(string s) 
    {
        int z=0;
        int o=0;
        for(auto x:s)
        {
            if(x=='0')
            {
                z++;
            }
            else{
                o++;
            }
        }
        string ans="";
        ans.push_back('1');
        o--;
        while(z--)
        {
            ans.push_back('0');
        }
        while(o--)
        {
            ans.push_back('1');
            z--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
