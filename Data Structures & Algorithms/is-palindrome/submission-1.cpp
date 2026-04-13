class Solution {
public:
    bool isPalindrome(string s) {
        
        string str = "";
        for(auto it : s){
            if(it >= 'a' && it <= 'z') str += tolower(it);
            else if(it >= 'A' && it <= 'Z') str += tolower(it);
            else if(it >= '0' && it <= '9') str += it;
        }
        string t = str;
        reverse(t.begin(),t.end());

        return (t == str);
    }
};
