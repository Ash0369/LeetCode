class Solution 
{
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) 
    {
        sort(arr.begin(),arr.end());
        int start=0;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            if(arr[i]<=(start+1))
            {
                
            }
            else{
                arr[i]=start+1;
            }
            start=arr[i];
        }
        return arr[n-1];
    }
};
