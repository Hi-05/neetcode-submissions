class Solution {
public:

    string encode(vector<string>& strs) {

        string encoded = "" ;

        for(auto it : strs){
            encoded += it;
            encoded += '-';
        }

        return encoded;
    }

    vector<string> decode(string s) {

        vector<string> v;
        string curr = "";

        for(int i = 0; i < s.size(); i++){

            if(s[i] == '-'){
                v.push_back(curr);
                curr = "";
                continue;
            }
            curr += s[i];
        }

        return v;
    }

};
