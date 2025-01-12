class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        int prevValue = 0;
        unordered_map<char, int> value = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        for (char c : s) {
            int currentValue = value[c];
            sum += (currentValue > prevValue) ? (currentValue - 2 * prevValue) : currentValue;
            prevValue = currentValue;
        }
        return sum;
    }
};
