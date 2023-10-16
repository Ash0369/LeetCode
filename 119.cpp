class Solution 
{
public:
    vector<int> getRow(int r) 
    {
        if(r==0)
        {
            return {1};
        }
        else if(r==1)
        {
            return {1,1};
        }
        else
        {
            vector<int>c={1,2,1};
            r=r-2;
            while(r>0)
            {
                vector<int>t;
                t.push_back(1);
                int z=c.size();
                for(int i=0;i<z-1;i++)
                {
                    t.push_back(c[i]+c[i+1]);
                }
                t.push_back(1);
                r--;
                c=t;
            }
            return c;
        }
    }
};
