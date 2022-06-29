class Solution 
{
public:
    int maxArea(vector<int>& height) 
    {
        int left=0;
        int n=height.size();
        int right=n-1;
        int max_area=0;
        while(left<right)
        {
            int max_h=min(height[left],height[right]);
            int area=max_h*(right-left);
            if(area>max_area)
            {
                max_area=area;
            }
            if(height[right]>=height[left])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return max_area;
    }
};
