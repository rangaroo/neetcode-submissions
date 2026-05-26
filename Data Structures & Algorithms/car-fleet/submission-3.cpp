class Solution {

/*
    [4,1,0,7]


    [7, 4, 1, 0]
    [1, 2, 2, 1]


*/


public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars(position.size());

        for (int i = 0; i < position.size(); ++i) {
            cars[i].first = position[i];
            cars[i].second = speed[i];
        }

        sort(cars.rbegin(), cars.rend());

        stack<double> s;

        for (auto& [pos, spd] : cars) {
            double time = (double)(target - pos) / spd;
            if (s.empty() || time > s.top()) {
                s.push(time);
            }
        }

        return s.size();
    }
};

