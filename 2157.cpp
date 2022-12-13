unordered_map<int,int>mp;
unordered_map<int,int>parent;

int find(int x)
{
    if(parent[x]==-1)
        return x;
    else
        return parent[x]=find(parent[x]);
}

void uni_on(int a,int b)
{
    int p1=find(a);
    int p2=find(b);
    
    if(p1==p2)
        return;
    else
    {
        parent[p1]=p2;
        mp[p2]=mp[p2]+mp[p1];
    }
}
class Solution 
{
public:
    vector<int> groupStrings(vector<string>& words) 
    {
        mp.clear();
        parent.clear();
        for(auto x:words)
        {
            int temp=0;
            for(char c:x)
            {
                temp=temp|(1<<(c-'a'));
            }
            mp[temp]++;
            parent[temp]=-1;
        }
        for(auto x:mp)
        {
            int num=x.first;
            for(int i=0;i<26;i++)
            {
                if(num&(1<<i))
                {
                    //Removing the set bit and checking
                    int ne=1<<i;
                    int nnum=(num&(~ne));
                    
                    if(parent.find(nnum)!=parent.end())
                    {
                        uni_on(nnum,num);
                    }
                    
                    //Replacing
                    
                    for(int j=0;j<26;j++)
                    {
                        if(i==j)
                        {
                            continue;
                        }
                         
                        if((num&(1<<j))==0)//that replacing bit should not be set
                        {
                           
                            int temp=nnum;//Taken after unsetting the current bit
                            
                            temp=temp|(1<<j); //Setting the replacing bit
                            
                            if(parent.find(temp)!=parent.end())
                                uni_on(temp,num);
                            
                        }
                    }
                    
                }
                else
                {
                    //If current bit is not set then we can set it and try
                    int temp=num;
                    temp=temp|(1<<i);
                    if(parent.find(temp)!=parent.end())
                        uni_on(temp,num);
                }
            }
        }
        
        int mx_size=0;
        int grp=0;
        
        for(auto x:parent)
        {
            if(x.second==-1)
            {
                grp++;
                mx_size=max(mx_size,mp[x.first]);
            }
        }
        
        return {grp,mx_size};
    }
};
