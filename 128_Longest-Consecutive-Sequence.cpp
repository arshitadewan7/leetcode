// leetcode/128_Longest-Consecutive-Sequence.cpp
/**
 * Date  : 12-July-2025
 * Repo: https://github.com/arshitadewan7/
 *
 * Problem   :  Longest Consecutive Sequence
 * Difficulty:  🟡Medium
 *
 * Leetcode 0128 :  https://leetcode.com/problems/longest-consecutive-sequence
 * Lintcode 0124 :  https://www.lintcode.com/problem/124
 */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public: 
    int longestConsecutive(vector<int>& nums) {
        // step 1 : we put all of the numbers in the array, into a hash set for 0(1) lookups
        unordered_set<int> numSet (nums.begin(), nums.end());
        int longestStreak = 0; // this count stores the maximum length of sequence found

        // step 2 : iterate through the set
        for (int num : numSet) {
            // we only consider numbers who dont have num-1 and we set it to the current num
            // that is our first num
            if (numSet.find(num-1) == numSet.end()){
                int currentNum = num;
                int currentStreak = 1; // we set a streak that starts with our current number

                // step 3 : we run a while loop to keep searching further until num has no consecutive numbers 
                while (numSet.find(currentNum + 1) != numSet.end()){
                    currentNum++;
                    currentStreak++;
            }
            
            // step 4 : we check if the current streak is longer than the longest streak, if yes , we set it to the longest.
            longestStreak = max(longestStreak,currentStreak);
            
            }    
        }
        return longestStreak;
    }
};

// main function for testing
int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    Solution sol;
    int result = sol.longestConsecutive(nums);
    cout << "Longest consecutive sequence length: " << result << endl;
    return 0;
}