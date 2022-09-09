//Method-1 : 

class Solution 
{
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>>result;
        for(int i=0;i<numRows;i++)
        {
            if(i==0)
            {
                result.push_back({1});
                continue;
            }
            else
            {
                vector<int>temp;
                for(int j=0;j<=i;j++)
                {
                    int a,b;
                    if(j-1<0)
                    {
                        a=0;
                    }
                    else
                    {
                        a=result[i-1][j-1];
                    }
                    if(j>=result[i-1].size())
                    {
                        b=0;
                    }
                    else
                    {
                        b=result[i-1][j];
                    }
                    temp.push_back(a+b);
                }
                result.push_back(temp);
            }
        }
        return result;
    }
};


//Method-2 : 

class Solution 
{
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>>result;
        for(int i=0;i<numRows;i++)
        {
           
            vector<int>temp(i+1,1);
            for(int j=1;j<i;j++)
            {
                int a=result[i-1][j-1];
                int b=result[i-1][j];
                temp[j]=(a+b);
            }
            result.push_back(temp);
        }
        return result;
    }
};
