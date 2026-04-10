class Solution {
public:
    int findMin(vector<int> &nums) {
        
        int high = nums.size() - 1;
        int low = 0;

        int res = nums[high];

        while(low <= high){

            int mid = (low + high) / 2;

            res = min(res,nums[mid]);

            if(nums[mid] > nums[high]){

                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return res;
    }
};
