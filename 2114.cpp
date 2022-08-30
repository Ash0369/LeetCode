//Method-1 :

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

//Method-2 : 

class Solution 
{
public:
    int mostWordsFound(vector<string>& sentences) 
    {
        int res=INT_MIN;
        for(auto const x:sentences)
        {
            int n;
            n=count(x.begin(),x.end(),' ');
            res=max(res,n);
        }
        return res+1;
    }
};
