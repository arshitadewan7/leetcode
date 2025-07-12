// leetcode/268_Missing-Number.cpp
/**
 * Date  : 12-July-2025
 * Repo: https://github.com/arshitadewan7/
 * 
 * Problem    : Missing Number
 * Difficulty : Easy
 * Leetcode   : https://leetcode.com/problems/missing-number/
 * Language   : C++
 * Author     : Arshita Dewan
 * 
 * Description:
 * Given an array containing n distinct numbers taken from 0 to n,
 * find the one that is missing from the array.
 * 
 * Example:
 * Input: [3, 0, 1]
 * Output: 2
 */

#include <iostream>         // for cout and endl
#include <vector>           // for vector
#include <algorithm>        // for sort
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Check for the first index where value doesn't match
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i) {
                return i;
            }
        }

        // Step 3: If all numbers match, the missing one is n
        return nums.size();
    }
};

int main() {
    // Sample test case
    vector<int> nums = {3, 0, 1};

    Solution sol;
    int missing = sol.missingNumber(nums);

    cout << "Missing number is: " << missing << endl;

    return 0;
}
