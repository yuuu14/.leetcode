#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// logs, int k
// logs[i] = [id, time]
// user active minutes: # of users having i UAM, from 1 to k


template<typename T>
void printVector(const T& t) {
    copy(t.cbegin(), t.cend(), ostream_iterator<typename T::value_type>(cout, ", "));
}

/* 
1 <= logs.length <= 104
0 <= IDi <= 109
1 <= timei <= 105
k \in [用户的最大用户活跃分钟数, 105]
*/

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        // [0,1] [0,1] [0,1] [2,3]
        // using set to preserve the setting of large 
        vector<int> res(k, 0);

        unordered_map<int, unordered_set<int>> uam;
        for (auto const& log : logs) uam[log[0]].insert(log[1]);
        for (auto const& u : uam) res[u.second.size()-1]++;
        return res;
        
    }
};

int main() {

    Solution sol;
    vector<vector<int>> logs{{1,2},{1,2}};
    vector<int> res = sol.findingUsersActiveMinutes(logs, 3);
    printVector(res);

    return 0;

}