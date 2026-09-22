class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int , int> mpp;
        for(int i = 0 ; i < nums.size() ; i++){
            int difference = target - nums[i];
            if(mpp.find(difference) != mpp.end()){
                res.push_back(mpp[difference]);
                res.push_back(i);
                return res;
            }
            mpp[nums[i]] = i;
        }
    }
};
