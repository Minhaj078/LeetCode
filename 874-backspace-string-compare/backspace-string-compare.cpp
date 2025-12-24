class Solution {
public:
    bool backspaceCompare(string s, string t) {

        string a = "";
        string b = "";

        // process s
        for(char c : s) {
            if(c == '#') {
                if(!a.empty()) a.pop_back();
            } else {
                a.push_back(c);
            }
        }

        // process t
        for(char c : t) {
            if(c == '#') {
                if(!b.empty()) b.pop_back();
            } else {
                b.push_back(c);
            }
        }

        return a == b;
    }
};
