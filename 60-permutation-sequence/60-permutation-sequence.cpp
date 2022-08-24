class Solution {
public:
    
    string getPermutation(int n, int k) {
        vector<int> numbers;
        
        string ans="";
        int i,cnt=1;
        
        int fact=1;
        for(i=1;i<=n;i++)
        {
            fact*=i;
            numbers.push_back(i);
        }
        fact/=n;
        k--;
        
        int c=0;
        
        while(1)
        {
            ans=ans+to_string(numbers[k/fact]);
            
            numbers.erase(numbers.begin()+ k/fact);
            
            if(numbers.size()==0) break;
            
            k=k%fact;
            fact/=numbers.size();
        }
        
        return ans;
    }
};