/**
 * Date  : 13-July-2025
 * Repo: https://github.com/arshitadewan7/
 * 
 * Problem    : Valid Parentheses
 * Difficulty : Easy
 * Leetcode   : https://leetcode.com/problems/valid-parentheses/
 * Language   : C++
 * Author     : Arshita Dewan
 
    Problem:
    Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
    determine if the input string is valid.

    A string is valid if:
    1. Open brackets are closed by the same type of brackets.
    2. Open brackets are closed in the correct order.
    3. Every closing bracket must have a corresponding opening bracket.

    Examples:
    Input: s = "()[]{}"      Output: true
    Input: s = "(]"          Output: false
    Input: s = "({[]})"      Output: true

    Solution:
    We use a stack. When we encounter an opening bracket, we push the corresponding 
    expected closing bracket onto the stack. When we encounter a closing bracket, 
    we check whether it matches the top of the stack. If it doesn't, the string 
    is invalid. At the end, if the stack is empty, the string is valid.
*/

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st; // Stack to store expected closing brackets

        for (char c : s) {
            // If it's an opening bracket, push the expected closing bracket
            if (c == '(') st.push(')');
            else if (c == '{') st.push('}');
            else if (c == '[') st.push(']');
            else {
                // If it's a closing bracket
                // If the stack is empty OR top of the stack does not match this bracket
                if (st.empty() || st.top() != c) return false;
                st.pop(); // Pop the matching expected closing bracket
            }
        }

        // If the stack is empty at the end, brackets were balanced
        return st.empty();
    }
};

int main() {
    Solution solution;

    // Example test cases
    string test1 = "()[]{}";
    string test2 = "(]";
    string test3 = "({[]})";

    cout << boolalpha; // Print 'true' or 'false' instead of 1 or 0
    cout << "Test 1: " << solution.isValid(test1) << endl; // true
    cout << "Test 2: " << solution.isValid(test2) << endl; // false
    cout << "Test 3: " << solution.isValid(test3) << endl; // true

    return 0;
}
