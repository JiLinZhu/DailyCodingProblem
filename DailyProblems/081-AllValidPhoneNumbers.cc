/* 81. Yelp
Given a mapping of digits to letters (as in a phone number), and a digit string, return all possible letters the number could represent.
You can assume each valid number in the mapping is a single digit.

For example if {“2”: [“a”, “b”, “c”], 3: [“d”, “e”, “f”], …} then “23” should return [“ad”, “ae”, “af”, “bd”, “be”, “bf”, “cd”, “ce”, “cf"].
*/

class Solution {
public:
    void backtrack(string s, int index) {
        if(index >= length) {
            res.push_back(s);
            return;
        }
        vector<char> cur = m[stringDigits[index]];
        string temp;
        for(char c: cur) {
            temp = s + c;
            backtrack(temp, index+1);
        }
    }

    vector<string> letterCombinations(string digits) {
        stringDigits = digits;
        length = digits.length();
        if(length==0) return res;
        m['2'] = { 'a', 'b', 'c' };
        m['3'] = { 'd', 'e', 'f' };
        m['4'] = { 'g', 'h', 'i' };
        m['5'] = { 'j', 'k', 'l' };
        m['6'] = { 'm', 'n', 'o' };
        m['7'] = { 'p', 'q', 'r', 's' };
        m['8'] = { 't', 'u', 'v' };
        m['9'] = { 'w', 'x', 'y', 'z' };


        backtrack("", 0);
        return res;
    }

private:
    int length;
    string stringDigits;
    vector<string> res;
    unordered_map<char, vector<char>> m;
};
