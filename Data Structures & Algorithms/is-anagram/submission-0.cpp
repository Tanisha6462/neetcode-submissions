class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        map<int , int> mpp1;
        map<int , int> mpp2;

        for(int i = 0 ; i < s.size() ; i++){
            mpp1[s[i]]++;
        }

        for(int i = 0 ; i < s.size() ; i++){
            mpp2[t[i]]++;
        }

        if(mpp1 == mpp2){
         return true;
        }
        else{
         return false;
        }
    }
};
