class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> window;
    int left = 0, right = 0, maxLen = 0;

    while (right < s.size()) {
        // If current char not in window → expand
        if (window.find(s[right]) == window.end()) {
            window.insert(s[right]);
            maxLen = std::max(maxLen, right - left + 1);
            right++;
        } else {
            // Duplicate found → shrink from left
            window.erase(s[left]);
            left++;
        }
    }
    return maxLen;
    }
};
