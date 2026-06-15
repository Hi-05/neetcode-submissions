class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        
        int n = words.size() ;
        vector<unordered_set<int>> v(26) ;
        unordered_map<int,int> mp;

        unordered_set<int> uniqueChars;
        for(const string& w : words) {
            for(char c : w) uniqueChars.insert(c - 'a');
        }
        for(int c : uniqueChars) mp[c] = 0;

        for(int i = 0; i < n-1; i++){

            int idx = 0;
            bool flag = false ;

            if(words[i] == words[i+1]) continue ;

            int minLen = min(words[i].size(), words[i+1].size());
            while(idx < minLen){

                if(words[i][idx] != words[i+1][idx]){

                    int a = words[i][idx] - 'a' ;
                    int b = words[i+1][idx] - 'a' ;


                    if(v[a].find(b) == v[a].end()) {
                        mp[b]++ ;
                        v[a].insert(b) ;
                    }

                    flag = true ;

                    break ;
                }
                idx++;
            }

            if(!flag && words[i].size() > words[i+1].size()) return "" ;
        }

        string res = "" ;
        queue<int> q;
        for(auto it : mp){
            if(it.second == 0) q.push(it.first) ;
        }

        while(!q.empty()){

            int val = q.front();
            q.pop();

            res += ('a' + val);

            for(auto it : v[val]){

                mp[it]--;
                if(mp[it] == 0){
                    q.push(it) ;
                } 
            }
        }

        if (res.size() < mp.size()) return "";
        return res;
    }
};
