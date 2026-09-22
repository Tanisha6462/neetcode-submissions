class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int> mpp;
        for(int i = 0 ; i < nums.size() ; i++){
            mpp[nums[i]]++;
        }

        int n = nums.size();
        vector<vector<int>> bucket(n+1);
        for(auto &[num , freq] : mpp){
            bucket[freq].push_back(num);
        }

        vector<int> res;
        for(int i = n ; i >= 0 ; i--){
            if(res.size() != k){
                for(int it : bucket[i]){
                    res.push_back(it);
                }
            }
            else if(res.size() == k){
                break;
            }
            
        }
        return res;


        
    }
};
