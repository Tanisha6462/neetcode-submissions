class Solution {
public:
    bool isValid(string s) {
        // while (!s.empty()) {

        //     bool found = false;

        //     for (int j = 0; j + 1 < s.size(); j++) {

        //         if ((s[j] == '{' && s[j + 1] == '}') ||
        //             (s[j] == '(' && s[j + 1] == ')') ||
        //             (s[j] == '[' && s[j + 1] == ']')) {

        //             s.erase(j, 2);
        //             found = true;
        //             break;
        //         }
        //     }

        //     if (!found) {
        //         return false;
        //     }
        // }

        // return true;

        stack<char>st;
        
        for(int i = 0 ; i < s.size() ;i++){
            if(s[i] == '{' || s[i] == '[' || s[i] == '('){
                st.push(s[i]);
            }
            else {
                if(st.empty()) return false;
                char p = st.top();
                st.pop();
                if(s[i] == '}' && p != '{'){
                    return false;
                }
                else if(s[i] == ']' && p != '['){
                    return false;
                }
                else if(s[i] == ')' && p != '('){
                    return false;
                }
            }
        }

        return st.empty();
    }
};
