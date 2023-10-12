/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */


class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        int left=1;
        int right=n-2;
        int ans;
        vector<int>arr(n+1,-1);
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(arr[mid]==-1)
            {
                arr[mid]=mountainArr.get(mid);
            }
            if(arr[mid-1]==-1)
            {
                arr[mid-1]=mountainArr.get(mid-1);
            }
            if(arr[mid+1]==-1)
            {
                arr[mid+1]=mountainArr.get(mid+1);
            }
            if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1])
            {
                ans=mid;
                break;
            }
            if(arr[mid-1]>arr[mid] && arr[mid]>arr[mid+1])
            {
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        //cout<<ans<<endl;
        int index=n+1;
        if(arr[ans]==target)
        {
            index=ans;
        }
        
        //search in left
        
        left=0;
        right=ans-1;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(arr[mid]==-1)
            {
                arr[mid]=mountainArr.get(mid);
            }
            
            if(arr[mid]==target)
            {
                index=min(index,mid);
                right=mid-1;
            }
            else if(target>arr[mid])
            {
                left=mid+1;
                
            }
            else{
                right=mid-1;
            }
        }
        left=ans+1;
        right=n-1;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(arr[mid]==-1)
            {
                arr[mid]=mountainArr.get(mid);
            }
            
            if(arr[mid]==target)
            {
                index=min(index,mid);
                right=mid-1;
            }
            else if(target>arr[mid])
            {
                right=mid-1;
                
                
            }
            else{
                left=mid+1;
            }
        }
        if(index>=n)
        {
            return -1;
        }
        return index;
    }
};
