Approach
The code repeatedly divides the column number by 26, using the remainder to determine the corresponding character. By building the title in reverse and then reversing it again, we achieve the correct order of characters for the Excel column title

We convert a positive integer colNum into its corresponding Excel column title. Here's a step-by-step explanation of the logic:

Initialization: Start with an empty string res to build the Excel column title.

Conversion Loop: Begin a loop that iterates while colNum is positive (greater than zero). This loop ensures that we convert the entire column number into its corresponding title.

Alignment: Decrement colNum by 1. Excel column numbering starts from 1 (A), not 0. This aligns our numbering system with Excel's.

Character Calculation: Calculate the remainder of colNum divided by 26. The remainder represents the value of the rightmost character in the Excel column title (A to Z).

Character Mapping: Convert the remainder to the corresponding character by adding the ASCII value of 'A' to it. This step maps the remainder to the appropriate letter.

Building the Title: Prepend the obtained character to the current res. Since we're iterating from right to left in the title, we add each character to the beginning of the string.

Move to Next Column: Divide colNum by 26, which effectively shifts the focus to the next column. We'll repeat the above steps to determine the character for this column.

Final Result: After the loop, res will hold the Excel column title in reverse order (from right to left). This is because we added characters to the front of the string. Return the reversed title as the result.

Complexity
Time complexity: O(n)

Space complexity: O(1)

Code
class Solution {
public:
    string convertToTitle(int colNum) {
        string res ="";
        while(colNum-- > 0){
            res = char(colNum % 26 + 'A') + res;
            colNum /= 26;
        }
        return res;
    }
};