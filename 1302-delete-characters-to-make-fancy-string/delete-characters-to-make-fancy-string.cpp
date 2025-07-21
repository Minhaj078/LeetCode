#include <string>
using namespace std;

class Solution {
public:
    string makeFancyString(string s) {
        string result;
        
        for (char ch : s) {
            int n = result.size();
            
            // Check if last two characters are the same as the current one
            if (n >= 2 && result[n - 1] == ch && result[n - 2] == ch) {
                continue;  // Skip this character to avoid three consecutive duplicates
            }
            
            result += ch;  // Add character to result if it's not a duplicate
        }
        
        return result;
    }
};
