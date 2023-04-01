#define ll long long
class Solution 
{
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) 
    {
        vector<int>vec;
        vector<int>cst(26,0);
        for(int i=0;i<26;i++)
        {
            cst[i]=i+1;
        }
        for(int i=0;i<chars.size();i++)
        {
            cst[int(chars[i])-97]=vals[i];
        }
        for(int i=0;i<s.size();i++)
        {
            vec.push_back(cst[int(s[i])-97]);
        }
        
        ll int mx_till=0;
        ll int mx=0;
        for(int i=0;i<vec.size();i++)
        {
            mx_till=mx_till+vec[i];
            if(mx_till<0)
            {
                mx_till=0;
            }
            mx=max(mx,mx_till);
        }
        return mx;
        
    }
};
