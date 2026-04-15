class Solution {
public:
    int maxArea(vector<int>& h) {
        
        int n = h.size();
        int mx = 0;

        int i = 0, j = n-1;

        while(i < j){

            int curr = (j - i) * min(h[i],h[j]);
            mx = max(mx,curr);

            if(h[i] < h[j]){
                i++;
            }
            else{
                j--;
            }
        }

        return mx;
    }
};
