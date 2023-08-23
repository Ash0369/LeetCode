#define ll long long
class segment_tree
{
    public:
    struct data
    {
        ll int value=0;
    };
    vector<data>sg;
    vector<data>lazy;
    segment_tree(int n)
    {
        data d;
        d.value=0;
        sg.resize(4*(n+1));
        lazy.resize(4*(n+1),d);
    }
    data make(ll int val)
    {
        data res;
        res.value=val;
        return res;
    }
    data combine(data a,data b)
    {
        a.value=a.value+b.value;
        return a;
    }
    void push(int index,int low,int high)
    {
        int mid=(low+high)/2;
        if(lazy[index].value%2!=0)
        {
            sg[(2*index)+1].value=(mid-low+1)-sg[(2*index)+1].value;
            lazy[(2*index)+1].value+=lazy[index].value;
            sg[(2*index)+2].value=(high-mid)-sg[(2*index)+2].value;
            lazy[(2*index)+2].value+=lazy[index].value;
        }
        lazy[index].value=0;
    }
    void build(int low,int high,vector<int>&arr,int index=0)
    {
        if(low>high)
        {
            return;
        }
        if(low==high)
        {
            sg[index]=make(arr[low]);
            return;
        }
        int mid=(low+high)/2;
        build(low,mid,arr,(2*index)+1);
        build(mid+1,high,arr,(2*index)+2);

        sg[index]=combine(sg[(2*index)+1],sg[(2*index)+2]);
    }
    data query(int low,int high,int lq,int rq,int index=0)
    {
        
        if(lq>rq)
        {
            return make(0);
        }
        if(low==lq && high==rq)
        {
            return sg[index];
        }
        push(index,low,high);
        int mid=(low+high)/2;
        data left=query(low,mid,lq,min(rq,mid),(2*index)+1);
        data right=query(mid+1,high,max(lq,mid+1),rq,(2*index)+2);
        return combine(left,right);
    }
    /*void update(int low,int high,int pos,ll int val,int index=0)
    {
        if(low==high)
        {
            sg[index]=make(val);
        }
        else
        {
            int mid=(low+high)/2;
            if(pos<=mid)
            {
                update(low,mid,pos,val,(2*index)+1);
            }
            else
            {
                update(mid+1,high,pos,val,(2*index)+2);
            }
            sg[index]=combine(sg[(2*index)+1],sg[(2*index)+2]);
        }
    }*/
    void lazy_update(int low,int high,int left,int right,int index=0)
    {
        if(left>right)
        {
            return;
        }
        else if(left==low && right==high)
        {
            
            if(left==right)
            {
                if(sg[index].value==0)
                {
                    sg[index].value=1;
                }
                else
                {
                    sg[index].value=0;
                }
            }
            else
            {
                push(index,low,high);
                lazy[index].value+=1;
                if(lazy[index].value%2!=0)
                {
                    sg[index].value=(high-low+1)-sg[index].value;
                }
            }
            
        }
        else
        {
            push(index,low,high);
            int mid=(low+high)/2;
            lazy_update(low,mid,left,min(right,mid),(2*index)+1);
            lazy_update(mid+1,high,max(left,mid+1),right,(2*index)+2);
            sg[index]=combine(sg[(2*index)+1],sg[(2*index)+2]);
        }
    }

};
class Solution 
{
public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) 
    {
        int n=nums1.size();
        segment_tree st(n+1);
        int n1=nums2.size();
        ll int tot=0;
        for(auto x:nums2)
        {
            tot+=x;
        }
        st.build(0,n-1,nums1);
        
        vector<ll int>ans;
        for(auto x:queries)
        {
            int l=x[1];
            int r=x[2];
            if(x[0]==1)
            {
                
                //Flip from l to r
                st.lazy_update(0,n-1,l,r);
            }
            else if(x[0]==2)
            {
                //count no of 1
                int cnt=st.query(0,n-1,0,n-1).value;
                tot+=1LL*cnt*l;
            }
            else
            {
                ans.push_back(tot);
            }
        }
        return ans;
    }
};
