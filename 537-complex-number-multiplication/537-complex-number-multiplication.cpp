class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int m=a.length(),n=b.length();
        
        int i,j;
        int r1=0,r2=0,i1=0,i2=0;
        int sign1=0,sign2=0,sign3=0,sign4=0;
        int real=0,imag=0;
        
        i=0;
        while(i<m and a[i]!='+') 
        {
            if(a[i]=='-') sign1=1;
            if(a[i]>='0' and a[i]<='9')
            r1=(r1*10)+(a[i]-'0');
            i++;
        }
        
        while(i<m and a[i]!='i') 
        {
            if(a[i]=='-') sign2=1;
            if(a[i]>='0' and a[i]<='9') i1=(i1*10)+(a[i]-'0');
            i++;
        }
        
        
        i=0;
        while(i<n and b[i]!='+') 
        {
            if(b[i]=='-') sign3=1;
            if(b[i]>='0' and b[i]<='9')
            r2=(r2*10)+(b[i]-'0');
            i++;
        }
        
        while(i<n and b[i]!='i') 
        {
            if(b[i]=='-') sign4=1;
            if(b[i]>='0' and b[i]<='9') i2=(i2*10)+(b[i]-'0');
            i++;
        }
        if(sign1) r1=-r1;
        if(sign2) i1=-i1;
        if(sign3) r2=-r2;
        if(sign4) i2=-i2;
        
        real=(r1*r2)-(i1*i2);
        imag=(r1*i2)+(i1*r2);
        
        string ans="";
        
        ans+=to_string(real);
        ans+='+';
        ans+=to_string(imag);
        ans+='i';
        
        return ans;
    }
};