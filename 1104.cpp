int change(int &n)
{
    n=n>>1;
    int bits=log2(n)+1;
    
    for(int i=0;i<bits-1;i++)//No need to flip MSB
    {
        n=n^(1<<i);
    }
    return n;
}
class Solution 
{
public:
    vector<int> pathInZigZagTree(int label) 
    {
        vector<int>ans;
        ans.push_back(label);
        while(label>1)
        {
            int x=change(label);
            ans.push_back(x);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
