/*
Approach
The problem requires finding the smallest sufficient team, where each team member possesses the required skills for a project.
To represent the required skills, we use a bitmask approach, where each bit corresponds to a specific skill. This allows us to efficiently check if a particular skill is present or not.
The solution uses a backtracking approach to explore different team configurations. It considers each person and decides whether to include them in the team or not.

The backtracking function, solve, takes several parameters:
- i: The current index of the person being considered.
- mask: A bitmask representing the covered skills of the current team configuration.
- people_skill: A vector of pairs containing the person's index and their skill bitmask.
- temp: A temporary vector to store the current team configuration.

Base Cases
The base cases of the recursion is reached when the bitmask mask is equal to the target bitmask, which means all required skills are covered. 
If the current team configuration (temp) is smaller than the previously stored result (ans), or if no result is stored yet, ans is updated with the current team configuration.

Backtracking
During the backtracking process, if the current person's bitmask does not introduce any new skills to the team (i.e., if (mask | people_skill[i].second) == mask), there's no need to include that person in the team.
Hence, that case is skipped.

The function makes two recursive calls:

solve(i + 1, mask, people_skill, temp): Represents the scenario where the current person is not added to the team. 
It moves on to the next person, keeping the current bitmask and team configuration.

solve(i + 1, mask | people_skill[i].second, people_skill, temp): Represents the scenario where the current person is added to the team. 
It updates the bitmask by performing a bitwise OR operation with the person's skill bitmask. The team configuration (temp) is updated accordingly.
*/

class Solution {
public:
    vector<int> ans;
    int m, target;

    void solve(int i, int mask, vector<pair<int, int>>& people_skill, vector<int>& temp) {
        if (mask == target) {
            if (ans.size() == 0 || ans.size() > temp.size()) 
                ans = temp;
            return;
        }
        if (i >= m) return;
        if (ans.size() != 0 && ans.size() <= temp.size()) return;

        solve(i + 1, mask, people_skill, temp);

        if ((mask | people_skill[i].second) != mask) {
            temp.push_back(people_skill[i].first);
            solve(i + 1, mask | people_skill[i].second, people_skill, temp);
            temp.pop_back();
        }
    }

    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = req_skills.size();
        map<string, int> mp;

        for (int i = 0; i < n; i++) {
            mp[req_skills[i]] = i;
        }

        target = (1 << n) - 1;

        map<int, int> tempmap;

        for (int i = 0; i < people.size(); i++) {
            int mask = 0;
            for (int j = 0; j < people[i].size(); j++) {
                int pos = mp[people[i][j]];
                mask |= (1 << pos);
            }
            if (mask == 0) continue;
            if (tempmap.find(mask) != tempmap.end()) continue;
            tempmap[mask] = i;
        }

        vector<pair<int, int>> people_skill;

        for (auto [mask, indx] : tempmap) 
            people_skill.push_back({indx, mask});

        m = people_skill.size();
        ans.clear();
        vector<int> temp;
        solve(0, 0, people_skill, temp);

        return ans;
    }
};
