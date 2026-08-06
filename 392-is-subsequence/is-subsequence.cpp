class Solution {
public:

    bool check(string s, string t, int m, int n){
        if(m < 0)return true;
        if(n < 0)return false;

        if(s[m] == t[n]){
            return check(s,t,m-1,n-1);
        }else{
            return check(s,t,m,n-1);
        }
    }

    bool isSubsequence(string s, string t) {
        int m = s.size()-1;
        int n = t.size()-1;

        return check(s,t,m,n);
    }
};