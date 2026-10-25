class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string cur;
        backtrack(s, 0, 0, cur, res);
        return res;
    }

private:
    void backtrack(const string& s, int idx, int parts, string& cur, vector<string>& res) {
        int n = s.size();
        int remaining = n - idx;

        int segsLeft = 4 - parts;
        if (remaining < segsLeft || remaining > segsLeft * 3) return;

        if (parts == 4) {
            if (idx == n) {
                cur.pop_back();          
                res.push_back(cur);
                cur.push_back('.');      
            }
            return;
        }

        int len = cur.size();
        int val = 0;
        for (int i = idx; i < n && i < idx + 3; i++) {
            val = val * 10 + (s[i] - '0');
            if (val > 255) break;

            cur += s.substr(idx, i - idx + 1);
            cur.push_back('.');
            backtrack(s, i + 1, parts + 1, cur, res);
            cur.resize(len);           

            if (val == 0) break;        
        }
    }
};