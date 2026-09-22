class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>> mpp;
        for(string word : strs){
            string sorted = word;
            sort(sorted.begin() , sorted.end());
            mpp[sorted].push_back(word);
        }

        vector<vector<string>> res;
        for(auto it : mpp){
            res.push_back(it.second);
        }
        
        return res;

    }
};
