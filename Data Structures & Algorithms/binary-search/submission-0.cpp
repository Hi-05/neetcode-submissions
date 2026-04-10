class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        auto idx = lower_bound(nums.begin(),nums.end(),target) - nums.begin();

        if(nums[idx] == target) return idx;
        return -1;
    }
};
