//Method-1 : Brute Force,15ms

string s;
void find_different(map<string,int>&mp,string formed,int n)
{
    if(mp.find(formed)==mp.end())
    {
        s=formed;
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(formed[i]=='0')
        {
            formed[i]='1'; //Turning on ith bit and calling recurssion
            find_different(mp,formed,n);
            formed[i]='0';
        }  
    }
}
class Solution 
{
public:
    string findDifferentBinaryString(vector<string>&nums) 
    {
        map<string,int>mp;
        string formed;
        for(int i=0;i<nums.size();i++)
        {
            formed.push_back('0');
            mp[nums[i]]++;
        }
        find_different(mp,formed,nums.size());
        return s;
    }
};


//Method-2 : Optimized Brute Force ,10ms

string s;
bool find_different(map<string,int>&mp,string &formed,int n)
{
    if(mp.find(formed)==mp.end())
    {
        s=formed;
        return true;
    }
    bool res=false;
    for(int i=0;i<n && res==false;i++)
    {
        if(formed[i]=='0')
        {
            formed[i]='1'; //Turning on ith bit and calling recurssion
            res=find_different(mp,formed,n);
            formed[i]='0';
        }  
    }
    return res;
}
class Solution 
{
public:
    string findDifferentBinaryString(vector<string>&nums) 
    {
        map<string,int>mp;
        string formed;
        for(int i=0;i<nums.size();i++)
        {
            formed.push_back('0');
            mp[nums[i]]++;
        }
        find_different(mp,formed,nums.size());
        return s;
    }
};

//Method-3 : Atleast taking 1 bit opposite of every string

class Solution 
{
public:
    string findDifferentBinaryString(vector<string>& nums) 
    {
        string res;
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i][i] == '0' ? nums[i][i]='1' : nums[i][i]='0'; 
            res=res+nums[i][i];
        } 
        
        return res; 
    }
};
