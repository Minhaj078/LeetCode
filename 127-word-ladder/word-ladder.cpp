class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Queue for BFS: stores pair of (currentWord, stepsFromBegin)
        queue<pair<string, int>> q;
        q.push({beginWord, 1}); // starting word with step count = 1

        // Set for quick lookup of words in wordList
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord); // remove beginWord to avoid revisiting

        // Start BFS
        while (!q.empty()) {
            string word = q.front().first;   // get current word
            int steps = q.front().second;    // get number of steps
            q.pop(); // remove from queue as we are processing it

            // Check if we have reached the endWord
            if (word == endWord) return steps;

            // Try changing every character of current word
            for (int i = 0; i < word.size(); i++) {
                char original = word[i]; // store the original character

                // Try replacing with every alphabet from a to z
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;

                    // If the new word is in the set, it is a valid transformation
                    if (st.find(word) != st.end()) {
                        st.erase(word); // erase to avoid revisiting
                        q.push({word, steps + 1}); // push new word with step+1
                    }
                }

                word[i] = original; // restore the original character
            }
        }

        // If we couldn't reach the endWord
        return 0;
    }
};
