class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        unordered_map<char,int> mp;

        for(auto it : s1){
            mp[it]++;
        }

        int n = s2.size();
        int j = 0;

        for(int i = 0; i < n; i++){

            j = max(j,i);

            while(j < n && mp[s2[j]] > 0){
                mp[s2[j]]--;
                j++;
            }

            if(j - i == s1.size()) return true;
            if(mp.find(s2[i]) != mp.end() && j > i) mp[s2[i]]++;
        }

        return false;
    }
};
