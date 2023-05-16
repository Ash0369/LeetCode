bool check(vector<int>& derived,int inti)
{
    int n=derived.size();
    vector<int>vec(n);
    vec[0]=inti;
    for(int i=0;i<n-1;i++)
    {
        if(derived[i]==1)
        {
            if(vec[i]==0)
            {
                vec[i+1]=1;
            }
            else
            {
                vec[i+1]=0;
            }
            
        }
        else
        {
            if(vec[i]==0)
            {
                vec[i+1]=0;
            }
            else
            {
                vec[i+1]=1;
            }
        }
    }
    if((vec[0]^vec[n-1])==derived[n-1])
    {
        return true;
    }
    return false;
}
class Solution 
{
public:
    bool doesValidArrayExist(vector<int>& derived) 
    {
        return check(derived,0)|check(derived,1);
    }
};
