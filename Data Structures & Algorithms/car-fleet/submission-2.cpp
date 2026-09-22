class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int,int>>v;
        for(int i = 0 ; i < n ; i++){
            v.push_back({position[i],speed[i]});
        }

        sort(v.begin(), v.end(), [](pair<int,int> a, pair<int,int> b) {
        return a.first > b.first;
        });

        vector<double>times(n);
        for(int i = 0 ; i < n ; i++){
            times[i] = (double)(target - v[i].first)/v[i].second;
        }

        stack<double>st;
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            if(st.empty() || st.top() < times[i]){
                st.push(times[i]);
            }
        }

        return st.size();
    }
};
