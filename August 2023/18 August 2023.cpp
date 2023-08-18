Approach
The main logic involved is to use an adjacency list to represent the graph and then iterate through all possible pairs of nodes. For each pair, calculate their total connections, accounting for direct connections. Keep track of the maximum value encountered, which will be the maximal network rank.

Complexity
Time complexity: O(N2)O(N^2)O(N 
2
 )

Space complexity: O(N+R)O(N + R)O(N+R)

Code
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int ans = 0;
        vector<unordered_set<int>> adj(n, unordered_set<int> ());

        for(auto road: roads){
            adj[road[0]].insert(road[1]);
            adj[road[1]].insert(road[0]);
        }

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int tmp = adj[i].size() + adj[j].size();
                if(adj[i].count(j))      tmp--;
                ans = max(ans, tmp);
            }
        }
        return ans;
    }
};
Approach
Maintaining a degree vector to track the number of edges for each node.
Looping through the given roads and updating degrees and the adjacency matrix accordingly.
Iterating through all pairs of nodes and calculating the network rank for each pair by summing their degrees and subtracting the connection status.
Keeping track of the maximal network rank encountered during the iteration.
Finally, returning the maximal network rank as the result, which represents the maximum number of directly connected nodes among all node pairs in the graph.
Complexity
Time complexity: O(R∗N+N2)O(R * N + N^2)O(R∗N+N 
2
 ) where R is number of Roads

Space complexity: O(N2+N)O(N^2 + N)O(N 
2
 +N) O(N^2) for the adjacency matrix and O(N) for the degree vector

Code
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>>graph(n,vector<int>(n,0));
        vector<int>degree(n,0);
        for(int i=0;i<roads.size();i++){
            int u = roads[i][0]; 
            int v = roads[i][1];
            degree[u]++;
            degree[v]++;
            graph[u][v] = 1;
            graph[v][u] = 1;
        }
        
        int ans=0;
        for(int i=0;i<graph.size();i++) {
            for(int j=0;j<graph.size();j++) {
                if(j != i) {
                    int rank=degree[i]+degree[j]-graph[i][j];
                    ans=max(ans,rank);
                }
            }
        }
        return ans;
    }
};