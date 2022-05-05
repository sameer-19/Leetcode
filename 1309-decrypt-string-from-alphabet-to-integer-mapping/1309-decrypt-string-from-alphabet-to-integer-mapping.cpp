class Solution {
public:
    string freqAlphabets(string s) {
        int n=s.length();
        
        map<string,char> mp;
        mp["1"]='a';mp["2"]='b';mp["3"]='c';mp["4"]='d';mp["5"]='e';mp["6"]='f';
        mp["7"]='g';mp["8"]='h';mp["9"]='i';
        mp["10#"]='j';mp["11#"]='k';mp["12#"]='l';mp["13#"]='m';mp["14#"]='n';mp["15#"]='o';
        mp["16#"]='p';mp["17#"]='q';mp["18#"]='r';mp["19#"]='s';mp["20#"]='t';mp["21#"]='u';
        mp["22#"]='v';mp["23#"]='w';mp["24#"]='x';mp["25#"]='y';mp["26#"]='z';
        
        int i,f=0;
        
        string ans="",z="";
        
        for(i=n-1;i>=0;i--)
        {
            if(s[i]=='#' and f==0) 
            {
                f=1;
                continue;
            }
            else if(s[i]=='#' and f==1)
            {
                reverse(z.begin(),z.end());
                z+='#';
                ans+=mp[z];
                z="";
                continue;
            }
            
            if(f==1)
            {
                z+=s[i];
                string st=z;
                reverse(st.begin(),st.end());
                if(stoi(st)>26)
                {
                    z.pop_back();
                    reverse(z.begin(),z.end());
                    z+='#';
                    ans+=mp[z];
                    f=0;
                    z="";
                    z+=s[i];
                    ans+=mp[z];
                    z="";
                }
            }
            else
            {
                string z="";
                z+=s[i];
                ans+=mp[z];
            }
            
        }
        
        if(z.length()>0)
        {
            // cout<<"*";
            reverse(z.begin(),z.end());
            z+='#';
            ans+=mp[z];
            z="";
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};