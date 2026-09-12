class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> count;
        for (char c : s) count[c]++;
        
        vector<pair<char, int>> freq(count.begin(), count.end());
        sort(freq.begin(), freq.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second;
        });
        
        string result;
        for (auto& [ch, cnt] : freq) {
            result += string(cnt, ch);
        }
        return result;
    }
};