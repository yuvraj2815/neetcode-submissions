class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> p;

        for(int i = 0; i < speed.size(); i++) {
            p.push_back({position[i], speed[i]});
        }
        sort(p.rbegin(), p.rend());

        stack<double> s;

        double time = (double)(target - p[0].first) / p[0].second;
        s.push(time);

        for(int i = 1; i < p.size(); i++) {
            double time = (double)(target - p[i].first) / p[i].second;

            if(time <= s.top()) {
                continue;
            } else {
                s.push(time);
            }
        }
        return s.size();
    }
};
