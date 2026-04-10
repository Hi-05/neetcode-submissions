class Solution {
public:

    bool check(vector<int> &piles,int h,int k){

        int n = piles.size();

        for(int i = 0; i < n;i++){

            int hours =  ( piles[i] + (k - 1) ) / k;

            h -= hours;

            if(h < 0) return false;
        }

        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int low = 1;
        int high = 1e9;

        int ans = INT_MAX;

        while(low <= high){

            int mid = (low + high) / 2;

            if(check(piles,h,mid)){

                ans = mid;
                high = mid - 1;
            }
            else{

                low = mid + 1;
            }
        }

        return ans;
    }
};
