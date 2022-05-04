class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int ans=0;
        int i,j,k,n=emails.size();
        
        for(i=0;i<n;i++)
        {
            string s="";
            int m=emails[i].size();
            j=0;
            while(j<m && emails[i][j]!='+')
            {
                j++;
            }
            if(j==m)
            {
                j=0;
                while(j<m and emails[i][j]!='@')
                {
                    if(emails[i][j]!='.') s+=emails[i][j];
                    j++;
                }
                while(j<m)
                {
                    s+=emails[i][j];
                    j++;
                }
                emails[i]=s;
            }
            else
            {
                k=0;
                while(k<j)
                {
                    if(emails[i][k]!='.') s+=emails[i][k];
                    k++;
                }
                while(k<m and emails[i][k]!='@') k++;
                while(k<m) s+=emails[i][k++];
                emails[i]=s;
            }
        }
        set<string> stl;
        for(auto x: emails) stl.insert(x);
        return (int)stl.size();
    }
};