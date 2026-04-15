class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>> mp;
        int n = strs.size();

        for(int i = 0 ; i < n; i++){

            vector<int> v(26,0);
            string temp = strs[i];
            for(int i = 0; i < temp.size(); i++){
                v[temp[i] - 'a']++;
            }

            string m = "";
            for(int i = 0; i < 26; i++){

                while(v[i] > 0){
                    m += ('a' + i);
                    v[i]--;
                }
            }

            mp[m].push_back(temp);
        }

        vector<vector<string>> res;
        for(auto &it : mp){
            res.push_back(it.second);
        }

        return res;
    }
};
