class Solution 
{
public:
    string convertToTitle(int columnNumber) 
    {
        string ans="";
        while(columnNumber>0)
        {
            int r=columnNumber%26;
            if(r==0)
            {
                ans.push_back('Z');
                columnNumber=columnNumber/26;
                columnNumber--;
            }
            else
            {
                ans.push_back(r-1+'A');
                columnNumber=columnNumber/26;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
