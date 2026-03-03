class Solution {
public:
    char findKthBit(int n, int k) {
        string s1="0";
        for(int i=1;i<n;i++){
            string invert=s1;
            reverse(invert.begin(),invert.end());
            for(char &c:invert){
                c=(c=='0')?'1':'0';
            }
            s1=s1+'1'+invert;
        }
        return s1[k-1];
    }
};