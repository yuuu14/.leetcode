#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;


template<typename T>
void printVector(const T& t) {
    copy(t.cbegin(), t.cend(), ostream_iterator<typename T::value_type>(cout, ", "));
    cout << "\n";
}


class Solution {
public:
    int balancedString(string s) {
        int n = s.length(), m = n/4, ctr['X']{};
        for (auto const& c : s) ++ctr[c];
        if (ctr['Q'] == m && ctr['W'] == m && ctr['E'] == m && ctr['R'] == m) 
            return 0;
        int res = n-1;
        for (int i = 0, j = 0; j < n; j++) { // [xxx...xxx...xxx]
            --ctr[s[j]]; // [i...j]
            for (; ctr['Q'] <= m && ctr['W'] <= m && ctr['E'] <= m && ctr['R'] <= m; ++ctr[s[i++]])
                res = min(res, j-i+1);
        }
        return res;
    }
};


int main() {
    Solution sol;
    string s{"QQQW"};
    int res = sol.balancedString(s);
    cout << res << "\n";

    system("pause");
    return 0;

}
