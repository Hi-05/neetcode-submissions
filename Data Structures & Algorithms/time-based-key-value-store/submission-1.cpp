class TimeMap {
public:

    unordered_map<string,vector<pair<int,string>>> mp;
    TimeMap() {
        
        mp.clear();
    }
    
    void set(string key, string value, int timestamp) {
        
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        

        string res = "";

        if(mp.find(key) == mp.end()) return res;

        // vector<pair<int,string>> v = mp[key];

        int l = 0, h = mp[key].size() - 1;

        while(l <= h){

            int mid = (l + h) / 2;

            if(mp[key][mid].first <= timestamp){
                res = mp[key][mid].second;
                l = mid + 1;
            }
            else{
                h = mid - 1;
            }
        }

        return res;

    }
};
