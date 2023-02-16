#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <cstdio>

using namespace std;


template<typename T>
void printVector(const T& t) {
    copy(t.cbegin(), t.cend(), ostream_iterator<typename T::value_type>(cout, ", "));
    cout << "\n";
}


class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        vector<int> ctr(101, 0), res(2, 0);
        for (auto const& n : nums) ++ctr[n];
        for (auto const& c : ctr) res[0] += c/2;
        res[1] = nums.size() - 2*res[0];
        return res;
    }
};


int main() {
    Solution sol;
    vector<int> nums{1,3,2,1,3,2,2};
    vector<int> res = sol.numberOfPairs(nums);
    printVector(res);
    
    system("pause");
    return 0;

}
