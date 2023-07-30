class Solution {
public:
    string minimumString(string a, string b, string c) {
        vector<string>vec={a,b,c};
        
        //abc
        //acb
        //bac
        //bca
        //cab
        //cba
        string ans="";
        
        vector<vector<int>>dp={{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};
        
        for(int i=0;i<6;i++)
        {
            string temp="";
            for(int j=0;j<3;j++)
            {
                int t=dp[i][j];
                if(temp.size()==0)
                {
                    temp=vec[t];
                }
                else
                {
                    string tem=vec[t];
                    if(temp.find(tem)!=string::npos)
                    {
                        continue;
                    }
                    int m=0;
                    bool res=false;
                    while(m<temp.size())
                    {
                        int j=m;
                        int k=0;
                        while(j<temp.size() && k<tem.size() && temp[j]==tem[k])
                        {
                            j++;
                            k++;
                        }
                        if(j==temp.size())
                        {
                            while(k<tem.size())
                            {
                                temp.push_back(tem[k]);
                                k++;
                            }
                            res=true;
                            break;
                        }
                        m++;
                    }
                    if(res==false)
                    {
                        temp+=tem;
                    }
                    
                }
            }
            if(ans.size()==0)
            {
                ans=temp;
            }
            else if(ans.size()>temp.size())
            {
                ans=temp;
            }
            else if(ans.size()==temp.size())
            {
                ans=min(ans,temp);
            }
        }
        return ans;
        
    }
};
