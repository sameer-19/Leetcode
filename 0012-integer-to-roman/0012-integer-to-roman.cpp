class Solution {
public:
    string intToRoman(int num) {
        string s = to_string(num);
        int n=s.length();
        string ans="";
        
        map<string,string> mp;
        mp["1"]="I";
        mp["5"]="V";
        mp["10"]="X";
        mp["50"]="L";
        mp["100"]="C";
        mp["500"]="D";
        mp["1000"]="M";
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0') continue;
            
            if(s[i]<='3')
            {
                int d = n-i-1;
                int cnt=s[i]-'0';
                int power = pow(10,d);
                string res = to_string(power);
                
                if(d==0)
                {
                    for(int j=0;j<cnt;j++) ans+=mp["1"];
                }
                else
                {
                    for(int j=0;j<cnt;j++)
                    {
                        ans+=mp[res];
                    }    
                }
            }
            else if(s[i]=='4')
            {
                int d = n-i-1;
                int power = pow(10,d);
                string res = to_string(power*5);
                
                if(res=="50")
                {
                    ans+='X';
                    ans+=mp[res];
                }
                else if(res=="500")
                {
                    ans+='C';
                    ans+=mp[res];
                }
                else
                {
                    ans+='I';
                    res='5';
                    ans+=mp[res];
                }
            }
            else if(s[i]=='5')
            {
                int d = n-i-1;
                int cnt=s[i]-'0';
                string res="";
                res+=s[i];
                if(d>0)
                {
                    int power = pow(10,d);
                    res = to_string(power*5);    
                }
                
                ans+=mp[res];
            }
            else if(s[i]<='8')
            {
                int d = n-i-1;
                int cnt=s[i]-'0';
                int power = pow(10,d);
                string res = to_string(5*power);
                
                if(res!="5")
                {
                    ans+=mp[res];
                    if(d==1)
                    {
                        for(int j=0;j<(cnt-5);j++) ans+='X';   
                    }
                    else if(d==2)
                    {
                        for(int j=0;j<(cnt-5);j++) ans+='C';
                    }
                }
                else
                {
                    ans+='V';
                    for(int j=0;j<(cnt-5);j++) ans+='I';
                }
            }
            else 
            {
                int d = n-i-1;
                int cnt=s[i]-'0';
                string res=""; 
                res += s[i];
                if(d==0)
                {
                    ans+="IX";
                }
                else if(d==1)
                {
                    ans+="XC";
                }
                else if(d==2)
                {
                    ans+="CM";
                }
            }
            // cout<<ans<<" ";
        }
        
        return ans;
    }
};