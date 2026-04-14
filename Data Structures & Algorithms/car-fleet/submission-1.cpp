class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (n == 0) return 0;
 
        vector<pair<int, int>> cars(n);
        for (int i = 0; i < n; i++) {
            cars[i] = {position[i], speed[i]};
        }
        
     
        sort(cars.begin(), cars.end());
        
        int fleets = 0;
        double maxTimeSoFar = 0.0;
        
        for (int i = n - 1; i >= 0; i--) {

            double timeToTarget = (double)(target - cars[i].first) / cars[i].second;
            
            if (timeToTarget > maxTimeSoFar) {
                fleets++;
                maxTimeSoFar = timeToTarget; 
            }
        }
        
        return fleets;
    }
};