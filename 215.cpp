//Method-1 : 

class Solution 
{
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int>pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
        }
        while(k>1)
        {
            k--;
            pq.pop();
        }
        return pq.top();

    }
};


//Method-2 : 

int indx;
int quick(vector<int>&arr,int l,int r)
{
   
    int grt=l;
    int pivot=arr[r];
    for(int i=l;i<r;i++)
    {
        if(arr[i]>pivot)
        {
            continue;
        }
        swap(arr[i],arr[grt]);
        grt++;
    }
    swap(arr[r],arr[grt]);
    if(indx==grt)
    {
        return arr[indx];
    }
    else if(indx>grt)
    {
        return quick(arr,grt+1,r);
    }
    return quick(arr,l,grt-1);
}
class Solution 
{
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        indx=nums.size()-k;
        return quick(nums,0,nums.size()-1);
    }
};
