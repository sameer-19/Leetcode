class Solution {
public:
    bool checkNum(string s)
    {
        if(s=="+" || s=="-" || s=="*" || s=="/") return false;
        return true;
    }
    
    int evalRPN(vector<string>& tokens) {
        int ans=0;
        
        int i,j,n=tokens.size();
        
        stack<long long> s;

        for(i=0;i<n;i++)
        {
            if(s.empty())
            {
                int p = stoi(tokens[i]);
                s.push(p);
            }
            else if(checkNum(tokens[i]))
            {
                int p = stoi(tokens[i]);
                s.push(p);
            }
            else
            {
                int first = s.top();
                s.pop();
                int second = s.top();
                s.pop();
                
                if(tokens[i]=="+") s.push(first+second);
                else if(tokens[i]=="-") s.push(second-first);
                else if(tokens[i]=="*") s.push((long long)first*second);
                else if(tokens[i]=="/") s.push(second/first);
            }
        }
        
        ans=s.top();
        
        return ans;
    }
};