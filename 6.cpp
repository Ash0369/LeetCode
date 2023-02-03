//Method-1 : 

class Solution 
{
public:
    string convert(string s, int numRows) 
    {
        string ans="";
        int n=s.size();
        vector<vector<int>>dp(numRows);
        int iter=0;
        for(int j=0;j<s.size();j++)
        {
            if(iter%2==0)
            {
                for(int i=0;i<numRows;i++)
                {
                    if(j>=s.size())
                        break;
                    dp[i].push_back(j);
                    j++;
                }
            }
            else
            {
                for(int i=numRows-2;i>0;i--)
                {
                    if(j>=s.size())
                        break;
                    dp[i].push_back(j);
                    j++;
                }
            }  
            j--;
            iter++;
        }
        for(auto x:dp)
        {
            for(auto y:x)
            {
                ans.push_back(s[y]);
            }
        }
        return ans;
    }
};


//Method-2 : Better speed

class Solution 
{
public:
    string convert(string s, int numRows) 
    {
        string ans="";
        int n=s.size();
        vector<string>dp(numRows);
        int iter=0;
        for(int j=0;j<s.size();j++)
        {
            if(iter%2==0)
            {
                for(int i=0;i<numRows;i++)
                {
                    if(j>=s.size())
                        break;
                    dp[i].push_back(s[j]);
                    j++;
                }
            }
            else
            {
                for(int i=numRows-2;i>0;i--)
                {
                    if(j>=s.size())
                        break;
                    dp[i].push_back(s[j]);
                    j++;
                }
            }  
            j--;
            iter++;
        }
        for(auto x:dp)
        {
            ans+=x;
        }
        return ans;
    }
};
