class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> ans;
        
        int i,j,n=paths.size();
        map<string,vector<string>> mp;
        
        for(i=0;i<n;i++)
        {
            j=0;
            string directory="";
            while(paths[i][j]!=' ')
            {
                directory+=paths[i][j];
                j++;
            }
            j++;
            string val="";
            string path="";
            bool flag=0;
            
            while(j<paths[i].length())
            {
                if(paths[i][j]==' ')
                {
                    string finalPath = directory+'/'+path;
                    mp[val].push_back(finalPath);
                    path="";
                    val="";
                }
                else
                {
                    if(paths[i][j]=='(') flag=1;
                    else if(paths[i][j]==')') flag=0;
                    else if(flag==0)
                    {
                        path+=paths[i][j];
                    }
                    else
                    {
                        val+=paths[i][j];
                    }
                }
                j++;
            }
            string finalPath = directory+'/'+path;
            mp[val].push_back(finalPath);   
        }
        
        for(auto x: mp)
        {
            if(x.second.size()>=2)
            {
                vector<string> tp;
                for(auto y: x.second) tp.push_back(y);
                ans.push_back(tp);
            }
        }
        
        return ans;
    }
};