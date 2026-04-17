class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    
        vector<pair<int,int>> v;
        vector<int> res;
        sort(nums.begin(),nums.end());

        for(int i = 0; i < nums.size(); ){

            int cnt = 0;
            int j = i;

            while(j < nums.size() && nums[j] == nums[i]){
                cnt++;
                j++;
            }

            v.push_back({cnt,nums[i]});
            i = j;
        }

        sort(v.begin(),v.end());
        for(int i = v.size() - 1; res.size() < k ; i--){
            res.push_back(v[i].second);
        }

        return res;
    }
};
