#define ll long long
class merge_sort_tree
{
    public:
    vector<vector<ll int>>data;
    merge_sort_tree(int n)
    {
        data.resize(4*n);
    }
    void merge(vector<ll int>&result,vector<ll int>&left,vector<ll int>&right)
    {
        int i=0;
        int j=0;
        
        while(i<left.size() && j<right.size())
        {
            if(left[i]<=right[j])
            {
                result.push_back(left[i]);
                i++;
            }
            else
            {
                result.push_back(right[j]);
                j++;    
            }
        }
        while(i<left.size())
        {
            result.push_back(left[i]);
            i++;
        }
        while(j<right.size())
        {
            result.push_back(right[j]);
            j++; 
        }
    }
    void build(int left,int right,vector<ll int>&vec,int index=0)
    {
        if(left>right)
        {
            return;
        }
        if(left==right)
        {
            data[index].push_back(vec[left]);
            return;
        }
        ll int mid=(left+right)/2;
        build(left,mid,vec,(2*index)+1);
        build(mid+1,right,vec,(2*index)+2);
        merge(data[index],data[(2*index)+1],data[(2*index)+2]);
    }
    ll int main_query(ll int low,ll int high,ll int qleft,ll int qright,ll int val,int index=0)
    {
        
        if(qleft>qright)
        {
            return 0;
        }
        if(qleft==low && qright==high)
        {
            int position=lower_bound(data[index].begin(),data[index].end(),val)-data[index].begin();
            return (int)data[index].size()-position;
        }
        ll int mid=(low+high)/2;
        ll int left=main_query(low,mid,qleft,min(qright,mid),val,(2*index)+1);
        ll int right=main_query(mid+1,high,max(qleft,mid+1),qright,val,(2*index)+2);
        return left+right;
    }
    ll int query(ll int qleft,ll int qright,ll int val)
    {
        return main_query(0,qright,qleft,qright,val);
    }
};
class Solution 
{
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) 
    {
        int n=nums1.size();
        vector<ll int>vec;
        for(int i=0;i<n;i++)
        {
            vec.push_back(nums1[i]-nums2[i]);
        }
        merge_sort_tree mst(n+2);
        mst.build(0,n-1,vec);
        ll int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=mst.query(i+1,n-1,vec[i]-diff);
        }
        return ans;
    }
};
