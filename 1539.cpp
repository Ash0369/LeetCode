class Solution 
{
    public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        int n=arr.size();
        int base=0;
        for(int i=0;i<n;i++)
        {
            int num=arr[i];
            int missing=num-base-1;
            if(missing<k)
            {
                k=k-missing;
            }
            else
            {
                return base+k;
            }
            base=num;
        }
        return base+k;
    }
};
