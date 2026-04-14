class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        
        int area = 0;
        int n = h.size();

        stack<int> right,left;
        vector<int> r(n,n),l(n,-1);

        for(int i =  n-1; i >= 0; i--){

            while(!right.empty() && h[right.top()] >= h[i]){
                right.pop();
            }

            if(!right.empty()) {
                r[i] = right.top();
            }
            right.push(i);
        }

        for(int i =  0; i < n; i++){

            while(!left.empty() && h[left.top()] >= h[i]){
                left.pop();
            }

            if(!left.empty()) {
                l[i] = left.top();
            }
            left.push(i);
        }

        for(int i = 0; i < n; i++){

            int w = r[i] - l[i] - 1;
            area = max(area,h[i] * w);
        }

        return area;
    }
};
