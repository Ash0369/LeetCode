class Solution 
{
public:
    int mostWordsFound(vector<string>& sentences) 
    {
        int count=INT_MIN;
        for(auto x:sentences)
        {
            int c=0;
            for(int i=0;i<x.length();i++)
            {
                if(x[i]==' ')
                {
                    c++;
                }
            }
            count=max(count,c);
        }
        return count+1;
    }
};
