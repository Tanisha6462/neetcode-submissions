class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int>st;
        vector<int>result(n,0);
        for(int i = 0 ; i < n ; i++){
            if(st.empty() || temperatures[st.top()] > temperatures[i]){
                st.push(i);
            }
            else {
                while(!st.empty() && temperatures[st.top()] <  temperatures[i]){
                    int indx = st.top();
                    st.pop();
                    result[indx] = i - indx; 
                }
                st.push(i);
            }
        }
        return result;
    }
};
