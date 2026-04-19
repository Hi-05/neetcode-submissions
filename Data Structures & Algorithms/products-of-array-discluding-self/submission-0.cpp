class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        int prod = 1;
        int cnt = 0;

        for(int i = 0; i < n; i++){

            if(nums[i] == 0) cnt++;
            else prod *= nums[i];
        }

        vector<int> res(n,0);

        for(int i = 0; i < n; i++){

            if(nums[i] == 0){

                if(cnt > 1){
                    continue;
                }
                else{
                    res[i] = prod;
                }
            }
            else{

                if(cnt > 0){
                    continue;
                }
                res[i] = (prod / nums[i]);
            }
        }

        return res;
    }
};
