/*Intuition
Why Binary Search ?
There will be a minimum particular speed at which you can reach in time. At any speed more than that, you can still reach within time.
But at any speed less than that, you cannot reach in time.
Thus whenever we come across such a problem that requires us to find the point of inflection, we should think of Binary Search.

Approach
Edge Case :
Check for Impossible Journey: If the available hour value is less than or equal to (n-1), it means it's not possible to reach all
the cities within the given time. Here, n represents the number of cities to visit. In such cases, the function returns -1.

Adding this to the code only makes it more efficient.

Working of the code :
While l is less than or equal to r, perform the following steps:

Calculate the mid-point of the search space as mid = (l + r) / 2
Initialize a variable ans to keep track of the total time required for the journey with the current mid speed.
Traverse through the distances between consecutive cities in the dist vector and update the ans by adding the time taken to travel
each distance with the current speed mid.
If the ans is less than or equal to the given hour, it means the current speed mid allows us to complete the journey on time. 
Update the result res to the current mid speed and move the left boundary l to mid + 1 to search for a potentially smaller speed.
If the ans is greater than the given hour, it means the current speed mid is not sufficient to complete the journey on time. 
So, move the right boundary r to mid - 1 to search for a larger speed.*/

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l=1,r=1e7;
        int n = dist.size(),res=-1;
        if (hour <= (double)(n - 1))
            return res;
        while(l<=r){
            int mid=(l+r)/2;
            double ans=0;
            for(auto q:dist){
                ans=ceil(ans);
                ans+=((double)q)/(mid);
            } 
            if(ans<=hour) res=mid,r=mid-1;
            else l=mid+1; 
        }
        return res;
    }
}