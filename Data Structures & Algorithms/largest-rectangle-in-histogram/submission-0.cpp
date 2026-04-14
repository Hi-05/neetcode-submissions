class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int area = 0;
        int n = heights.size();

        for(int i = 0; i < n ; i++){

            int h = heights[i];
            for(int j = i; j < n;j++){

                h = min(h,heights[j]);
                area = max(area,h * (j - i + 1));
            }
        }

        return area;
    }
};
