class Solution {
public:

    string encode(vector<string>& strs) {
        string s;

        for(auto it : strs){

            s += to_string(it.size());
            s += "#";
            s += it;
        }

        return s;
    }

    vector<string> decode(string s) {

        vector<string> v;
        string curr = "";

        for(int i = 0; i < s.size(); i++){

            if(s[i] == '#'){

                i++;
                int len = stoi(curr);
                curr = "";
                string temp = s.substr(i,len);
                v.push_back(temp);
                i += len;
            }
            curr += s[i];

        }

        return v;
    }
};
