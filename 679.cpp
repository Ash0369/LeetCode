vector<double>compute(double x,double y)
{
    return {x+y,x-y,y-x,x*y,x/y,y/x};
}

bool calc(vector<double>&v)
{
    if(v.size()==1)
        return abs(v[0]-24)<=0.1;
    
    for(int i=0;i<v.size();i++)
    {
        for(int j=i+1;j<v.size();j++)
        {
            double n1=v[i];
            double n2=v[j];
            
            vector<double>nxt;
            
            for(auto x:compute(n1,n2))
            {
                nxt.clear();
                nxt.push_back(x);
                for(int k=0;k<v.size();k++)
                {
                    if(k!=i && k!=j)
                        nxt.push_back(v[k]);
                }
                
                if(calc(nxt))
                    return true;
            }
        }
    }
    
    return false;
}
class Solution 
{
public:
    bool judgePoint24(vector<int>& cards) 
    {
        vector<double>arr(cards.begin(),cards.end());
        return calc(arr);
    }
};
