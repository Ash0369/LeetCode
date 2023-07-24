class Solution 
{
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) 
    {
        vector<string>ans;
        string prev="";
        for(auto x:words)
        {
            for(auto y:x)
            {
                if(y==separator)
                {
                    if(prev.size()>0)
                    {
                        ans.push_back(prev);
                        prev="";
                    }
                }
                else
                {
                    prev.push_back(y);
                }
            }
             if(prev.size()!=0)
                    {
                        ans.push_back(prev);
                        prev="";
                    }
        }
        
        return ans;
    }
};
