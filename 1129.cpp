#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

// logs, int k
// logs[i] = [id, time]
// user active minutes: # of users having i UAM, from 1 to k


template<typename T>
void printVector(const T& t) {
    copy(t.cbegin(), t.cend(), ostream_iterator<typename T::value_type>(cout, ", "));
}


/* N nodes, 0...N-1
red & blue

res: shortest path length from 0 to node X with no same colored neighbor edges
0 1 2 3 4
bfs
for each node, 2 flag: which color the in-edge is

*/

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> res(n);
        // red positive, blue negative
        vector<vector<int>> g(n), dist(n, {-1, -1});
        for (const auto& red : redEdges) g[red[0]].emplace_back(red[1]);
        for (const auto& blue : blueEdges) g[blue[0]].emplace_back(-blue[1]);
        // bfs from 0
        dist[0][0] = 0; dist[0][1] = 0;
        queue<int> q; q.push(0);
        while (!q.empty()) {
            int fr = q.front(); q.pop();
            for (const auto& u : g[fr]) {
                int color = 0, v = u;
                if (u < 0) { color = 1; v = -u; }
                if (dist[fr][1-color] == -1 || dist[v][color] != -1 && dist[fr][1-color]+1 >= dist[v][color]) continue;
                dist[v][color] = dist[fr][1-color] + 1;
                q.push(v);
            }
        }
        //for (const auto& d : dist) printVector(d);
        for (int i = 0; i < n; i++) 
            res[i] = (dist[i][0] == -1 || dist[i][0] > dist[i][1] && dist[i][1] != - 1? dist[i][1] : dist[i][0]);
        return res;
    }
};

int main() {
    Solution sol;
    // red_edges = [[0,1],[0,2]], blue_edges = [[1,0]]
    //[[0,1],[1,2],[2,3],[3,4]]
    //[[1,2],[2,3],[3,1]]
    vector<vector<int>> redEdges{{0,1},{1,2},{2,3},{3,4}}, blueEdges{{1,2},{2,3},{3,1}};
    vector<int> res = sol.shortestAlternatingPaths(5, redEdges, blueEdges);
    printVector(res);
    
    system("pause");
    return 0;

}