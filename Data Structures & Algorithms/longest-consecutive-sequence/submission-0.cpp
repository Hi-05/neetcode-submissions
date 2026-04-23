class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = 1;

        if(n == 0) return 0;

        int i = 0;
        while(i < n){

            int cnt = 1;
            while(i < n-1 && (nums[i] == nums[i+1] || nums[i]+1 == nums[i+1])){

                if(nums[i+1] == nums[i]) ;
                else cnt++;
                i++;
            }

            ans = max(ans,cnt);
            i++;
        }

        return ans;
    }
};
