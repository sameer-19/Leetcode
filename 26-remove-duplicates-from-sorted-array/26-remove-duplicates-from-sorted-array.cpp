class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int n=a.size();
        if(n < 2) return n;
        int id = 1;
        for(int i = 1; i < n; ++i) 
            if(a[i] != a[i-1]) a[id++] = a[i];
        return id;
    }
};