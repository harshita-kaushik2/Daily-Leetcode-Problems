/*Intuition
Lower limit is minimumum time for which they can work simultaneously. Itcan be said as the minimum battery value of all batteries.
Upper limit by observation is the sum of all batteries/ number of computers.*/

Code
class Solution {
public:
    bool solve(long long mid, int n, vector<int>& batteries) {
        long long target_sum = mid*n;
        long long current_sum = 0;

        for(int val: batteries) {
            if(val < mid)   current_sum += val;
            else    current_sum += mid;
            if(current_sum >= target_sum)   return true;
        }
        return current_sum >= target_sum;
    }

    long long maxRunTime(int n, vector<int>& batteries) {
      long long low = LLONG_MAX;
      long long high, total_sum, mid;
      long long ans = -1;

      for(int val: batteries){
          if(val < low) low = val;
          total_sum += val;
      }
      high = (total_sum/n)+1;

      while(low < high) {
          mid = low + (high-low)/2;
          if(solve(mid, n, batteries)) {
              ans = mid;
              low = mid+1;  //itne minute tak toh chal gaye saare computer simultaneously, par kya isse zada chal sakte hain ? 
          }
          else  high = mid;
      }
      return ans;
    }
};