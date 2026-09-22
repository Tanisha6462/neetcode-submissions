class Solution {
public:
    bool isPalindrome(string s) {
        string cleaned = "";
        for (char c : s) {
            if (isalnum(c)) {
                cleaned += tolower(c);
            }
        }

        int i = 0, j = cleaned.size() - 1;
        while (i < j) {
            if (cleaned[i] != cleaned[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
    bool isalnum(char c){
        return (c >= 'A' && c <= 'Z' || 
                c >= 'a' && c <= 'z' || 
                c >= '0' && c <= '9');
    }
};
