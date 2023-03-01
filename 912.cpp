//Method-1 : Quick Sort Give TLE


int perform(vector<int>&nums,int low,int high)
{
    int pivot=nums[low];
    int i=low;
    int j=high;
    
    while(i<j)
    {
        while(i<high && nums[i]<=pivot)
        {
            i++;
        }
        while(j>low && nums[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            swap(nums[i],nums[j]);
        }
    }
    swap(nums[j],nums[low]);
    return j;
}
void quick_sort(vector<int>&nums,int low,int high)
{
    if(low>=high)
    {
        return;
    }
    int partion_index=perform(nums,low,high);
    quick_sort(nums,low,partion_index-1);
    quick_sort(nums,partion_index+1,high);
}
class Solution 
{
public:
    vector<int>sortArray(vector<int>&nums) 
    {
        quick_sort(nums,0,nums.size()-1);
        return nums;
    }
};


//Method-2 : Merge Sort


void merge(vector<int>&nums,int low,int mid,int high)
{
    vector<int>temp;
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high)
    {
        if(nums[left]<=nums[right])
        {
            temp.push_back(nums[left]);
            left++;
        }
        else if(nums[left]>nums[right])
        {
            temp.push_back(nums[right]);
            right++;
        }
    }
    while(left<=mid)
    {
        temp.push_back(nums[left]);
        left++;
    }
    while(right<=high)
    {
        temp.push_back(nums[right]);
        right++;
    }
    int index=0;
    for(int i=low;i<=high;i++)
    {
        nums[i]=temp[index];
        index++;
    }
}
void merge_sort(vector<int>&nums,int low,int high)
{
    if(low>=high)
    {
        return;
    }
    int mid=(low+high)/2;
    merge_sort(nums,low,mid);
    merge_sort(nums,mid+1,high);
    merge(nums,low,mid,high);
}
class Solution 
{
public:
    vector<int>sortArray(vector<int>&nums) 
    {
        merge_sort(nums,0,nums.size()-1);
        return nums;
    }
};
