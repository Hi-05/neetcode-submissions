class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int n = numbers.size();
        int i = 0, j = n-1;

        while(i < j){

            int curr = numbers[i] + numbers[j];
            if(curr == target){
                return {i+1,j+1};
            }
            else if(curr > target){
                j--;
            }
            else{
                i++;
            }
        }

        return {-1,-1};
    }
};
