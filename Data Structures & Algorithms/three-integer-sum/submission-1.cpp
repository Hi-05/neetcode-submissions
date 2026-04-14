class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int n = nums.size();

        vector<vector<int>> ans;

        for(int i = 0; i < n; i++){

            int j = i + 1;
            int k = n-1;

            while(j < k){

                int curr = nums[j] + nums[k];

                if(curr + nums[i] == 0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    
                    while(j < n && nums[j] == nums[j+1]){
                        j++;
                    }
                    while(k > 0 && nums[k] == nums[k-1]){
                        k--;
                    }

                    j++;
                    k--;
                }
                else if(curr + nums[i] > 0){
                    while(k > 0 && nums[k] == nums[k-1]){
                        k--;
                    }

                    k--;
                }
                else{
                    while(j < n && nums[j] == nums[j+1]){
                        j++;
                    }

                    j++;
                }
            }

            while(i < n && nums[i+1] == nums[i]){
                i++;
            }
        }

        return ans;
    }
};
