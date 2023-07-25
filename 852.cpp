class Solution 
{
public:
    int peakIndexInMountainArray(vector<int>& arr) 
    {
        int n=arr.size();
        int left=0;
        int right=n-1;
        int ans=right;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(mid==0)
            {
                if(arr[mid]>arr[mid+1])
                {
                    return mid;
                }
                return mid+1;
            }
            if(mid==n-1)
            {
                if(arr[mid]>arr[mid-1])
                {
                    return mid;
                }
                return mid-1;
            }
            if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1])
            {
                ans=mid;
                break;
            }
            else if(arr[mid-1]>arr[mid])
            {
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        return ans;
    }
};
