class Solution {
public:
    vector<int> getDiff(string &word) {
        vector<int> diff;
        for (int i = 0; i < word.size() - 1; i++) {
            diff.push_back(word[i+1] - word[i]);
        }
        return diff;
    }
    
    string oddString(vector<string>& words) {
        vector<int> d1 = getDiff(words[0]);
        vector<int> d2 = getDiff(words[1]);
        vector<int> d3 = getDiff(words[2]);
        
        if (d1 == d2) {
            for (int i = 2; i < words.size(); i++) {
                if (getDiff(words[i]) != d1) return words[i];
            }
        } else if (d1 == d3) {
            return words[1];
        } else {
            return words[0];
        }
        return "";
    }
};
