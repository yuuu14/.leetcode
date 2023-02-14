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
    int longestWPI(vector<int>& hours) {
        // longest seq with #hour>8 > #hour<=8
        // -> get max sum of seq of int including negative
        int n = hours.size();
        vector<int> pref(n+1, 0); // sum([0...i])

        for (int i = 0; i < n; i++)
            if (hours[i] > 8) pref[i+1] = pref[i] + 1;
            else pref[i+1] = pref[i] - 1;
        // pref[j] - pref[i] = sum([i+1...j])
        // pref[j] = pref[i] + sum([i+1...j])
        // fix j, find min i make sum>0
        // clearly if i1<i2 with pref[i1]<=pref[i2], i2 will not be considered
        vector<vector<int>> st{};
        int idx = 0;
        for (auto const& p : pref) {    
            if (st.empty() || st.back()[0] > p) 
                st.push_back({p, idx}); // 0 pref0 pref1 ... prefn-1
            ++idx;
        }
        
        printVector(pref);
        int res = 0;
        for (int i = n, top, idx; !st.empty() && i > 0; i--) {
            for (; !st.empty(); st.pop_back()) {
                top = st.back()[0]; idx = st.back()[1];
                if (top >= pref[i]) break;
                // cout << res << ", i=" << i << ", idx=" << idx << "\n";
                res = max(res, i-idx);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> hours
        //{5,3,6,4,1,3,5,10,3,1,4,6,22};
        //{9,9,6,0,6,6,9};
        {6,9,9};
    int res = sol.longestWPI(hours);
    cout << res << "\n";
    //    0   0  0  9  9  6  0  6  6 9
    // 0  -1 -2 -3 -2 -1 -2 -3 -4 -5 -4
    //st 0 -1 -2 -3 -4 -5
    //     9 9 9 9
    //   0 1 2 3 4
    //st 0
    //    6 9 9
    //  0 -1 0 1
    //st0 

    
    system("pause");
    return 0;

}
