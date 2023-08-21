Approach
This code aims to determine if a given string s can be formed by repeating a single substring. It does this by iterating through potential substring lengths from half the length of s down to 1.

For each potential substring length i, it checks if s can be evenly divided into segments of length i. If it can, the code constructs a repeated string by concatenating the potential substring sub.

If the constructed string matches the original s, the function returns true, indicating a repeated substring pattern.
If no match is found for any substring length, the function returns false.
Why traverse from half the length to s[1] ?
The code iterates through potential substring lengths from half of s's length down to 1 because, in a repeated substring pattern, the repeated substring's length cannot exceed half the original string's length. If a substring longer than half is used, it would require overlapping repetitions, which contradicts the pattern.

For example, let's take the string s = "abcabcabc". The substring "abc" can be repeated three times to form s. In general, a repeated substring pattern would look something like "substringsubstringsubstring...". In this case, the length of the repeated part is equal to the length of the substring, and the total length of the repeated string is a multiple of the substring length.

Complexity
Time complexity: O(n^20 
2
 )

Space complexity: O(n)

Code
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for(int i = s.length()/2; i >= 1; i--) {
            if(s.length() % i == 0) {
                string sub = s.substr(0, i);
                string constructedString = "";
                int n = s.length() / i;
                
                for(int j = 1; j <= n; j++) 
                    constructedString += sub;
                
                if(constructedString == s) return true;
            }
        }
        return false;
    }
};