/* Intuition
The intuition behind this solution lies in the fact that critical edges directly impact the MST's weight, while pseudo-critical edges 
do not necessarily affect the MST's weight. By building the MST and analyzing the impact of removing edges, the algorithm can categorize
edges into critical and pseudo-critical groups.

Approach
Let's break down the solution step by step :

Understanding the DSU:

You start by understanding that you need a data structure called Disjoint Set Union (DSU) to manage the connectivity of vertices. This data structure has two main operations: finding the parent of a set (group) and uniting two sets.
Sorting Edges for Greedy Selection:

You have a list of edges, each with a weight representing its importance. You realize that you can prioritize selecting edges based on their weights to build the Minimum Spanning Tree (MST) greedily.
So, you sort the edges in ascending order of their weights. This will help you pick edges with the lowest weights first while building the MST.
Building the Minimum Spanning Tree (MST):

Now that the edges are sorted, you're ready to construct the MST using a greedy approach.
You iterate through the sorted edges one by one. For each edge:
You check if the two nodes of the edge are not already in the same group (set) using the DSU.
If they are not, you unite the sets containing those nodes (DSU's union operation), signifying that they are now connected in the MST, and you add the edge to the MST.
Finding Critical Edges:

With the MST constructed, you focus on identifying critical edges, which are edges that, when removed, would increase the total weight of the MST.
To find these, you iterate through the edges in your MST:
For each edge, you temporarily remove it from the MST and calculate the weight of the new MST.
If this new weight is greater than the original MST weight, you mark the edge as critical. Otherwise, you leave it in the MST.
Finding Pseudo-Critical Edges:

Next, you want to find pseudo-critical edges, which are edges that could be in some MSTs but not all.
You iterate through each edge (including the ones not in the MST):
For each edge, you simulate building an MST without that edge.
If the weight of this new MST is the same as the weight of the original MST, you consider the edge as pseudo-critical.
Final Categorization and Cleaning Up:

Now you have two lists: one for critical edges and one for pseudo-critical edges.
However, some edges could be both critical and pseudo-critical, which you don't want. So you make sure to remove those from the pseudo-critical list.
Finally, you have a complete list of critical edges and pseudo-critical edges that you can return as the result.
Complexity
Time complexity: O(E∗logE)O(E * log E)O(E∗logE) mainly comes from the sorting step O(E log E) where E is the number of edges and the DSU operations O(E)

Space complexity: O(n+len)O(n + len)O(n+len) where n is the number of vertices and len is the number of edges in the graph. */

class Solution {
public:
    class DSU {
    public:
        int findParent(int node, vector<int>& par) {
            if (par[node] == node) return node;
            return par[node] = findParent(par[node], par);
        }
        void Union(int u, int v, vector<int>& size, vector<int>& par) {
            int pu = findParent(u, par);
            int pv = findParent(v, par);
            if (pu == pv) return;
            if (size[pu] <= size[pv]) {
                par[pu] = pv;
                size[pv]++;
            } else {
                par[pv] = pu;
                size[pu]++;
            }
        }
    };

    static bool comp(vector<int>& v1, vector<int>& v2) {
        return v1[2] < v2[2];
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int len = edges.size();
        for (int i = 0; i < len; i++)
            edges[i].push_back(i);

        sort(edges.begin(), edges.end(), comp);

        DSU dsu;
        int cost = 0;
        vector<int> par(n);
        vector<int> size(n, 1);
        for (int i = 0; i < n; i++) par[i] = i;
        vector<bool> isPart(len, 0);
        int c = 0;
        for (int i = 0; i < len; i++) {
            if (c == n - 1) break;
            if (dsu.findParent(edges[i][0], par) != dsu.findParent(edges[i][1], par)) {
                dsu.Union(edges[i][0], edges[i][1], size, par);
                isPart[edges[i][3]] = 1;
                cost += edges[i][2];
                ++c;
            }
        }
        vector<int> critical, pseudocritical;
        for (int i = 0; i < len; i++) {
            DSU tempDSU;
            vector<int> tempPar(n, 0);
            for (int j = 0; j < n; j++) tempPar[j] = j;

            vector<int> tempSize(n, 1);
            int tempCost = 0;
            vector<bool> temp(len, 0);
            int c = 0;
            for (int j = 0; j < len; j++) {
                if (c == n - 1) break;
                if (j == i) continue;
                if (tempDSU.findParent(edges[j][0], tempPar) != tempDSU.findParent(edges[j][1], tempPar)) {
                    tempDSU.Union(edges[j][0], edges[j][1], tempSize, tempPar);
                    temp[edges[j][3]] = 1;
                    tempCost += edges[j][2];
                    c++;
                }
            }
            if (tempCost == cost) {
                for (int k = 0; k < len; k++) {
                    if (temp[k]) isPart[k] = 1;
                }
            } else
                critical.push_back(edges[i][3]);
        }

        for (int i = 0; i < len; i++) {
            if (isPart[edges[i][3]]) continue;
            DSU tempDSU;
            vector<int> tempPar(n, 0);
            for (int j = 0; j < n; j++) tempPar[j] = j;
            vector<int> tempSize(n, 1);
            int tempCost = 0;
            tempDSU.Union(edges[i][0], edges[i][1], tempSize, tempPar);
            tempCost += edges[i][2];
            int c = 0;
            for (int j = 0; j < len; j++) {
                if (c == n - 1) break;
                if (j == i) continue;
                if (tempDSU.findParent(edges[j][0], tempPar) != tempDSU.findParent(edges[j][1], tempPar)) {
                    tempDSU.Union(edges[j][0], edges[j][1], tempSize, tempPar);
                    tempCost += edges[j][2];
                    ++c;
                }
            }
            if (tempCost == cost)
                pseudocritical.push_back(edges[i][3]);
        }
        for (auto& it : critical)
            isPart[it] = 0;
        for (int i = 0; i < len; i++) {
            if (isPart[i])
                pseudocritical.push_back(i);
        }
        return { critical, pseudocritical };
    }
};