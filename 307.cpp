class NumArray 
{
public:
    int n;
    vector<int>seg;
    void build(int index,int low,int high,vector<int>&seg,vector<int>&nums)
    {
        if(low==high)
        {
            seg[index]=nums[low];
            return;
        }
        int mid=(low+high)/2;
        build(2*index+1,low,mid,seg,nums);
        build(2*index+2,mid+1,high,seg,nums);
        
        seg[index]=seg[2*index+1]+seg[2*index+2];
    }
    void updatesg(int index,int low,int high,vector<int>&seg,int &i,int &val)
    {
        if(low==high)
        {
            seg[index]=val;
            return;
        }
        int mid=(low+high)/2;
        if(i>mid)
        {
            updatesg(2*index+2,mid+1,high,seg,i,val);
        }
        else
        {
            updatesg(2*index+1,low,mid,seg,i,val);
        }
        
        seg[index]=seg[2*index+1]+seg[2*index+2];
    }
    
    int query(int index,int low,int high,vector<int>&seg,int &l,int &r)
    {
        if(high<l || r<low)
        {
            return 0;
        }
        if(low>=l && high<=r)
        {
            return seg[index];
        }
        int mid=(low+high)/2;
        int left=query(2*index+1,low,mid,seg,l,r);
        int right=query(2*index+2,mid+1,high,seg,l,r);
        return left+right;
    }
    NumArray(vector<int>& nums) 
    {
        n=nums.size();
        seg.resize(4*n);
        build(0,0,n-1,seg,nums);
    }
    
    void update(int index, int val) 
    {
        updatesg(0,0,n-1,seg,index,val);
    }
    
    int sumRange(int left, int right) 
    {
        return query(0,0,n-1,seg,left,right);
    }        
};
