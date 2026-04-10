class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int l = 0;
        int h = nums.size() - 1;

        int res = -1;

        while(l <= h){

            int mid = (l + h) / 2;

            if(nums[mid] == target){
                res = mid;
                break;
            }
            else if(nums[l] <= nums[mid - 1]){

                if(target >= nums[l] && target <= nums[mid-1]){
                    h = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
            else{

                if(target >= nums[mid + 1] && target <= nums[h]){
                    l = mid + 1;
                }
                else{
                    h = mid - 1;
                }
            }
        }

        return res;
    }
};
