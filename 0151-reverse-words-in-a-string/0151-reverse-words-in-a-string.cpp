class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        int n = s.size();
        int slow = 0, fast = 0;

        while (fast < n) {
            
            while (fast < n && s[fast] == ' ') fast++;
            if (fast == n) break;

            if (slow != 0) s[slow++] = ' '; 

            int wordStart = slow;
            while (fast < n && s[fast] != ' ') {
                s[slow++] = s[fast++];
            }

            reverse(s.begin() + wordStart, s.begin() + slow);
        }

        s.resize(slow);
        return s;
    }
};