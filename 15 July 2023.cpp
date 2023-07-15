class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
     sort(events.begin(), events.end());
     int n = events.size();
     vector<vector<int>>dp(n+5,vector<int>(k+1,-1));
     return solve(0,events,k,dp);
    }

    int binarySearch(int ind, vector<vector<int>>& events, int val) {
        int low = ind, high = events.size()-1, required = -1;
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(events[mid][0] > val) {
                required = mid;
                high = mid - 1;
            }
            else    low = mid+1;
        }
        return required;
    }

    int solve(int i, vector<vector<int>>& events, int k, vector<vector<int>>& dp) {
        if(k == 0 || i == -1 || i >= events.size())     return 0;
        if(dp[i][k] != -1)       return dp[i][k];

        int ind = binarySearch(i+1, events, events[i][1]);
        int attend = events[i][2] + solve(ind, events, k-1, dp);
        int notAttend = solve(i+1, events, k, dp);

        return dp[i][k] = max(attend, notAttend);   
    }
};