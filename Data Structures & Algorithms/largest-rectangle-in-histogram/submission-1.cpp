class Solution {
public:
    vector<int>NSL(vector<int>&arr){
        int n = arr.size();
        vector<int>left(n);
        int pseudoIndx = -1;
        stack<pair<int,int>>st;

        for(int i = 0 ; i < n ; i++){
            if(st.empty()){
                left[i] = pseudoIndx;
            }
            else if(!st.empty() && st.top().first < arr[i]){
                left[i] = st.top().second;
            } else {
                while(!st.empty() && st.top().first >= arr[i]){
                    st.pop();
                }
                if(st.empty()){
                    left[i] = pseudoIndx;
                }
                else {
                    left[i] = st.top().second;
                }
            }
            st.push({arr[i],i});
        }
        return left;
    }

    vector<int>NSR(vector<int>&arr){
        int n = arr.size();
        vector<int>right(n);
        int pseudoIndx = n;
        stack<pair<int,int>>st;

        for(int i = n-1 ; i >= 0 ; i--){
            if(st.empty()){
                right[i] = pseudoIndx;
            }
            else if(!st.empty() && st.top().first < arr[i]){
                right[i] = st.top().second;
            } else {
                while(!st.empty() && st.top().first >= arr[i]){
                    st.pop();
                }
                if(st.empty()){
                    right[i] = pseudoIndx;
                }
                else {
                    right[i] = st.top().second;
                }
            }
            st.push({arr[i],i});
        }
        return right;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>left = NSL(heights);
        vector<int>right = NSR(heights);
        vector<int>width(heights.size());

        for(int i = 0 ; i < heights.size() ;i++){
            width[i] = right[i]-left[i]-1;
        }

        int area = INT_MIN;
        for(int i = 0 ; i < width.size();i++){
            area = max(area , width[i]*heights[i]);
        }

        return area;
    }
};
