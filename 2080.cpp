class info
{
    public:
    map<int,int>mp;
};
class RangeFreqQuery 
{
public:
    info seg[4*100000];
    int n;
    void build_tree(vector<int>& arr,int low,int high,int index)
    {
        if(low==high)
        {
            
            seg[index].mp[arr[low]]=seg[index].mp[arr[low]]+1;
            
            return;
        }
        int mid=(low+high)/2;
        build_tree(arr,low,mid,2*index+1);
        build_tree(arr,mid+1,high,2*index+2);
        
        for(auto x:seg[2*index+1].mp)
        {
            seg[index].mp[x.first]+=x.second;
        }
        for(auto x:seg[2*index+2].mp)
        {
            seg[index].mp[x.first]+=x.second;
        }

    }
    int query_tree(int index,int low,int high,int &l,int &r,int &value)
    {
        if(high<l || r<low)
        {
            return 0;
        }
        
        if(low>=l && high<=r)
        {
            return seg[index].mp[value];
        }
            
        int mid=(low+high)/2;
        int left=query_tree(2*index+1,low,mid,l,r,value);
        int right=query_tree(2*index+2,mid+1,high,l,r,value);

        return left+right;
    }
        
        
    RangeFreqQuery(vector<int>& arr) 
    {
        n=arr.size();
        build_tree(arr,0,n-1,0);
        
    }
    
    int query(int left, int right, int value) 
    {
        return query_tree(0,0,n-1,left,right,value);
    }
};
