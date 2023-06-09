int ans=0;
vector<int> merge(vector<int>&a,vector<int>&b)
{
    int n1=a.size();
    int n2=b.size();
    int i=0;
    int j=0;
    int iter=0;
    for(int k=0;k<n1;k++)
    {
        while(iter<n2 && a[k]>(2LL*b[iter]))
        {
            iter++;
        }
        ans+=iter;
    }
    vector<int>v;
    while(i<n1 && j<n2)
    {
        if(a[i]>b[j])
        {
            v.push_back(b[j]);
            j++;
        }
        else
        {
            v.push_back(a[i]);
            i++;
        }
    }
    while(i<n1)
    {
        v.push_back(a[i]);
        i++;
    }
    while(j<n2)
    {
        v.push_back(b[j]);
        j++;
    }
    
    return v;
}
vector<int> merge_sort(vector<int>&a,int left,int right)
{
    
    if(left==right)
    {
        return {a[left]};
    }
    int mid=(left+right)/2;
    auto a1=merge_sort(a,left,mid);
    auto b=merge_sort(a,mid+1,right);
    return merge(a1,b);
}
class Solution 
{
public:
    int reversePairs(vector<int>& nums) 
    {
        ans=0;
        int n=nums.size();
        merge_sort(nums,0,n-1);
        return ans;
    }
};
