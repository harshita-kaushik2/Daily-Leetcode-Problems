/*Approach
We use a recursive approach to generate all possible letter combinations from a string of digits, 
using a pre-defined mapping of each digit to its corresponding letters.

The mapping array is used to store the letters corresponding to each digit.
For example, mapping[2] contains the letters "abc," mapping[3] contains "def," and so on. 
This mapping allows the code to easily access the letters associated with each digit and generate all possible combinations.

The for loop inside the solve function iterates through each letter corresponding to the current digit number (number) 
from the mapping array. It appends each letter to the output string and then makes a recursive call to process the next digit.

Base Case :
When all digits have been processed, the value of index >= digit.length() then current combination is added to the answer vector.

The algorithm explores all possible combinations by backtracking through the recursive calls.*/

class Solution {
private:
    void solve(string digit, string output, int index, vector<string>& ans, string mapping[] ) {
        
        if(index >= digit.length()) {
            ans.push_back(output);
            return;
        }
        
        int number = digit[index] - '0';
        string value = mapping[number];
        
        for(int i=0; i<value.length(); i++) {
            output.push_back(value[i]);
            solve(digit, output, index+1, ans, mapping);
            output.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0)  return ans;

        string output;
        int index = 0;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl","mno","pqrs","tuv","wxyz"};

        solve(digits, output, index, ans, mapping);
        return ans;
    }
};