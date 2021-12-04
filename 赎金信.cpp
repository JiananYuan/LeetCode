class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m_map;
        int m_len = int(magazine.size());
        // 统计 magazine 内字符出现的次数
        for (int i = 0; i < m_len; i += 1) {
            char ch = magazine[i];
            if (m_map.count(ch) == 0) {
                m_map.insert(make_pair(ch, 1));
            } 
            else {
                m_map[ch] += 1;
            }
        }
        int r_len = int(ransomNote.size());
        bool can_compose = true;
        // 判断 ransomNote 能不能由 magazines 里面的字符构成
        for (int i = 0; i < r_len; i += 1) {
            char ch = ransomNote[i];
            if (m_map.count(ch) == 0 || m_map[ch] == 0) {
                can_compose = false;
                break;
            }
            else {
                m_map[ch] -= 1;
            }
        }
        return can_compose;
    }
};
