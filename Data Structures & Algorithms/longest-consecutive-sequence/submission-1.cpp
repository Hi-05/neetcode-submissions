class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> s (nums.begin(),nums.end());
        int n = nums.size();
        
        int ans = 0;

        for(int i = 0; i < n; i++){

            if(s.find(nums[i] -1) == s.end()){

                int len =  1;
                while(s.find(nums[i] + len) != s.end()){
                    len++;
                }

                ans = max(ans,len);
            }
        }
        

        return ans;
    }
};
