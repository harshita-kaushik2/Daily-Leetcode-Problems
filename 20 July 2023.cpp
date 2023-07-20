/*Approach 1 : Using Stack
Create an empty stack, asteroidStack, to simulate the collision of asteroids and store the remaining asteroids after the collisions.
Iterate through each asteroid in the input vector, asteroids.
For each asteroid, check if it will collide with the top asteroid in the asteroidStack.
If the asteroidStack is empty, or if the current asteroid is moving to the right (positive), or the top asteroid in the stack is moving to the left (negative), push the current asteroid onto the stack since no collision will occur.
KEY STEP : If the current asteroid is moving to the left (negative) and the top asteroid in the asteroidStack is moving to the right (positive), handle the collision as follows:
If the absolute value of the current asteroid is greater than the top asteroid in the stack, remove the top asteroid from the stack (it gets destroyed), and keep checking for further collisions with other asteroids in the stack.
If the absolute value of the current asteroid is equal to the top asteroid in the stack, both asteroids get destroyed, so remove the top asteroid from the stack.
If the absolute value of the current asteroid is smaller than the top asteroid in the stack, the current asteroid gets destroyed, and no further collision occurs with other asteroids.
After processing all the asteroids, create a new vector, ans, of size equal to the number of asteroids left in the stack.
Pop the remaining asteroids from the stack and store them in the ans vector in reverse order (to maintain the original order).
Return the ans vector, which contains the asteroids that remain after all the collisions have been resolved.*/
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> asteroidStack;

        for (int i = 0; i < n; i++) {
            int collisionFlag = 0;

            if (asteroidStack.empty()) {
                asteroidStack.push(asteroids[i]);
                continue;
            }

            while (!asteroidStack.empty() && asteroids[i] < 0 && asteroidStack.top() > 0) {
                if (asteroidStack.top() < abs(asteroids[i]))
                    asteroidStack.pop();
                else {
                    collisionFlag = 1;
                    if (asteroidStack.top() == abs(asteroids[i]))
                        asteroidStack.pop();
                    break;
                }
            }
            if (collisionFlag)  continue;
            asteroidStack.push(asteroids[i]);
        }

        vector<int> ans(asteroidStack.size());
        while (!asteroidStack.empty()) {
            int size = asteroidStack.size();
            ans[size - 1] = asteroidStack.top();
            asteroidStack.pop();
        }
        return ans;
    }
};
/*Approach 2 : Using Vector
This solution efficiently handles asteroid collisions in a given vector of integers. It iterates through the asteroids one by one, simulating the collisions and storing the surviving asteroids in a new result array.
We initialize resultIndex to keep track of the current position in the result array.
For each asteroid in the input vector, we do the following:

a. If the current asteroid is negative (moving to the left) and the last asteroid in the result array is positive (moving to the right) and the current asteroid is larger in magnitude, we remove the last asteroid from the result array as it gets destroyed in the collision. We keep doing this until no more collisions can happen in the current situation.
b. If the result array is empty, or the current asteroid is positive (moving to the right), or the last asteroid in the result array is negative (moving to the left), we add the current asteroid to the result array, and increment resultIndex.
c. If the last asteroid in the result array and the current asteroid have the same magnitude (one positive and the other negative), both asteroids get destroyed, and we skip adding the current asteroid to the result array by decrementing resultIndex.

After processing all asteroids, we create a new vector result from the beginning of the asteroids vector up to the resultIndex position, effectively removing any remaining unused elements.
The result vector is then returned as the final output, containing the surviving asteroids after all collisions have been resolved.*/

Code
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        int resultIndex = 0;

        for (int i = 0; i < n; i++) {
            int currentAsteroid = asteroids[i];

            while (resultIndex > 0 && asteroids[resultIndex - 1] > 0 && currentAsteroid < 0 && asteroids[resultIndex - 1] < abs(currentAsteroid)) {
                resultIndex--;
            }

            if (resultIndex == 0 || currentAsteroid > 0 || asteroids[resultIndex - 1] < 0) {
                asteroids[resultIndex++] = currentAsteroid;
            } else if (asteroids[resultIndex - 1] == abs(currentAsteroid)) {
                resultIndex--;
            }
        }

        vector<int> result(asteroids.begin(), asteroids.begin() + resultIndex);

        return result;
    }
};