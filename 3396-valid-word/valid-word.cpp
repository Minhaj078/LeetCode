// class Solution {
// public:
//     bool isValid(string s) {
//         int n = s.length();
//         if (n < 3) return false;

//         int vowels = 0, consonants = 0;
//         string vowelList = "aeiouAEIOU";

//         for (char c : s) {
//             if (isalpha(c)) {
//                 if (vowelList.find(c) != string::npos) {
//                     vowels++;
//                 } else {
//                     consonants++;
//                 }
//             } else if (!isdigit(c)) {
//                 return false; // invalid character
//             }
//         }

//         return vowels >= 1 && consonants >= 1;
//     }
// };


class Solution {
public:
    bool isValid(string word) {
        //word="3ab"
        int vov_cnt=0;
        int con_cnt=0;
        int num=0;
        for(char i:word){
            if(isalpha(i) || isdigit(i)){
                if(isdigit(i))num++; //num=1;
                else{
                    if(i=='a'||i=='e'||i=='i'||i=='o'||i=='u' || i == 'A' || i == 'E' || i == 'I' || i == 'O' || i == 'U'){
                        vov_cnt++; //vov_cnt=1;
                    }else{
                        con_cnt++; //con_cnt=1;
                    }
                }
            }else{
                return false;
            }
        }
        if(vov_cnt>=1 && con_cnt>=1 && vov_cnt+con_cnt+num>=3){
            return true;
        }else{
            return false;
        }
    }
};