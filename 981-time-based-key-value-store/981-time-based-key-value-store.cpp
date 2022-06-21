class TimeMap {
public:
    map<string,vector<pair<string,int>>> mp;
    TimeMap() {
        mp.clear();
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key)!=mp.end()){
            string ans="";
            
            int left=0,right=mp[key].size()-1;
            
            while(left<=right)
            {
                int middle=left+(right-left)/2;
                
                if(mp[key][middle].second<=timestamp)
                {
                    ans=mp[key][middle].first;
                    left=middle+1;
                }
                else
                {
                    right=middle-1;
                }
            }
            
            return ans;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */