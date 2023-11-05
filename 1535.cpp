class Solution 
{
public:
    int getWinner(vector<int>& arr, int k) 
    {
        int n=arr.size();
        int x=arr[0];
        int cnt=0;
        for(int i=1;i<n;i++)
        {
            if(arr[i]>x)
            {
                x=arr[i];
                cnt=1;
                if(cnt==k || cnt==n)
                {
                    return arr[i];
                }
            }
            else
            {
                cnt++;
                if(cnt==k || cnt==n)
                {
                    return x;
                }
            }
        }
        return x;
    }
};
