class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ban(banned.begin(), banned.end());
        map<string, int> mp;
        int len = paragraph.size();
        string ans;
        int maxn = 0;
        for (int i = 0; i < len; ++i) {
            if (isalpha(paragraph[i])) {
                string x;
                int c = i;
                while (c < len && isalpha(paragraph[c])) {
                    x += tolower(paragraph[c++]);
                }
                i = c;
                if (ban.count(x)) continue;
                mp[x]++;
                if (mp[x] > maxn) {
                    maxn = mp[x];
                    ans = x;
                }
            }
        }
        return ans;
    }
};

string mostCommonWord(string p, vector<string>& banned) {
        unordered_set<string> ban(banned.begin(), banned.end());
        unordered_map<string, int> count;
        for (auto & c: p) c = isalpha(c) ? tolower(c) : ' ';
        istringstream iss(p);
        string w;
        pair<string, int> res ("", 0);
        while (iss >> w)
            if (ban.find(w) == ban.end() && ++count[w] > res.second)
                res = make_pair(w, count[w]);
        return res.first;
    }