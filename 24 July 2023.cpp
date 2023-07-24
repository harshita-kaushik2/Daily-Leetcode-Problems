/*Approach
- The function takes two arguments, x (the base) and n (the exponent).

- The first check is whether n == 0. If n is 0, it means any number raised to the power of 0 is 1. So, the function returns 1.

- Next, there's a check to see if n is negative (n < 0). If it is negative, the code enters the if block.

    - Inside the if block, the code converts n to its absolute value using the abs() function, effectively making it positive. 
    Also, since a negative exponent is equivalent to calculating the reciprocal of the number raised to the positive exponent, 
    the code updates x to be 1/x.

- Now, we have a positive value for n, so the next step is to determine whether n is even or odd.

    - If n is even (n % 2 == 0), the code execures if block. In this case, it recursively calls myPow() with the base x*x and 
    exponent n/2. This recursive call reduces the exponent by half, and it squares the base at each step.

    - If n is odd, the code executes the else block. In this case, it calculates x * myPow(x, n-1). This recursive call reduces 
    the exponent by 1 and keeps the base as it is. For example, to calculate myPow(x, 7), it will first calculate x * myPow(x, 6),
     then x * myPow(x, 5), and so on until it reaches myPow(x, 1).

- The recursive calls continue until the base case of n == 0 is reached, at which point the recursion starts to unwind, and the final 
result is calculated by accumulating the intermediate results.*/

class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(n<0) {
            n = abs(n);
            x = 1/x;
        }
        if(n%2==0){
            return myPow(x*x, n/2);
        }
        else{
            return x*myPow(x, n-1);
        }
    }
};