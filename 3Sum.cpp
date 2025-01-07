#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Iterate through the array
        for (int i = 0; i < nums.size() - 2; ++i) {
            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    // Found a triplet
                    result.push_back({nums[i], nums[left], nums[right]});

                    // Move left and right to skip duplicates
                    ++left;
                    while (left < right && nums[left] == nums[left - 1])
                        ++left;

                    --right;
                    while (left < right && nums[right] == nums[right + 1])
                        --right;
                } 
                else if (sum < 0) {
                    ++left;  // Increase the sum
                } 
                else {
                    --right;  // Decrease the sum
                }
            }
        }

        return result;
    }
};
