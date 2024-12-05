class Solution {
public:
    bool canChange(string start, string target) {
        string s1 = "", s2 = "";
        int i=0, n = start.size(), cnt = 0;
        
        while(i<n)
        {
            if(start[i]!='_') s1+=start[i];
            if(target[i]!='_') s2+=target[i];
            
            i++;
        }
        
        if(s1!=s2) return false;
        
        i=0;
        
        while(i<n)
        {
            if(target[i]=='L') cnt++;
            
            if(start[i]=='L') 
            {
                if(cnt>0) 
                {
                    cnt--;
                }
                else return false;
            }
            i++;
        }
        
        cnt = 0; i = n-1;
        
        while(i>=0)
        {
            if(target[i]=='R') cnt++;
            
            if(start[i]=='R') 
            {
                if(cnt>0) 
                {
                    cnt--;
                }
                else return false;
            }
            i--;
        }
        
        return true;
    }
};