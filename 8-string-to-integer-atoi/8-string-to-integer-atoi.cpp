class Solution {
public:
    int myAtoi(string s) {
        long long ans=0,n=s.length(),i;
        char ch='+';
        bool f=0;
        int cnt=0;
        for(i=0;i<n;i++)
        {
            if(f==0)
            {
                if(s[i]==' ' && cnt==0) continue;
                else if(s[i]==' ' && cnt==1) return 0;
                else if(s[i]=='-' || s[i]=='+') { cnt++; ch=s[i];}
                else if(s[i]>='0' && s[i]<='9') 
                { 
                    if((ans*10)+(s[i]-'0')<=INT_MAX) { ans=(ans*10)+(s[i]-'0'); f=1;}
                    else 
                    {
                        if(ch=='+')
                            return INT_MAX;
                        else 
                            return INT_MIN;
                    }
                }  
                else return 0;;
                if(cnt>=2) return 0;
            }
            else
            {
                if(s[i]==' ') break;
                else if(s[i]=='-' || s[i]=='+') break;
                else if(s[i]>='0' && s[i]<='9')
                { 
                    if((ans*10)+(s[i]-'0')<=INT_MAX) {ans=(ans*10)+(s[i]-'0'); f=1;}
                    else 
                    {
                        if(ch=='+')
                            return INT_MAX;
                        else 
                            return INT_MIN;
                    }
                }
                else break;
            }
        }
        if(ch=='-') return -ans;
        else return ans;
    }
};