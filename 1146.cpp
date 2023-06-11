class SnapshotArray 
{
public:
    unordered_map<int,vector<int>>mp;
    int id;
    vector<map<int,int>>vec;
    SnapshotArray(int length) 
    {
        vec.resize(length);
        for(int i=0;i<length;i++)
        {
            vec[i][0]=0;
        }
        id=0;
    }
    
    void set(int index, int val) 
    {
        vec[index][id]=val;
    }
    
    int snap() 
    {
        id++;
        return id-1;
    }
    
    int get(int index, int snap_id) 
    {
        if(vec[index].find(snap_id)==vec[index].end()) 
            {
            auto it =--vec[index].lower_bound(snap_id);
            return it->second;

            }
        return vec[index][snap_id];
    }
};
