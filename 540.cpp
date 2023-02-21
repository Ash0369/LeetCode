class Solution 
{
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        int n=nums.size();
        if(n==1)
        {
            return nums[0];
        }
        int left=0;
        int right=n-1;
        while(left<=right)
        {
            int mid=(left+right)/2;
            int ele=nums[mid];
            bool l=true;
            bool r=true;
            
            if(mid-1>=0 && nums[mid-1]==ele)
            {
                l=false;
            }
            if(mid+1<n && nums[mid+1]==ele)
            {
                r=false;
            }
            if(l==true && r==true)
            {
                return ele;
            }
            if(l==false)
            {
                if(mid%2==0)
                {
                    right=mid-1;
                }
                else
                {
                    left=mid+1;
                }
            }
            else if(r==false)
            {
                if(mid%2==0)
                {
                    left=mid+1;
                }
                else
                {
                    right=mid-1;
                }
            }
        }
        return -1;
    }
};
