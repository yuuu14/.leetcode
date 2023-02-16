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

// 2,3,1,1,4
// 3,2,1,0,4
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int N = nums.size();
        vector<int> dp(N, 0);
        // 1 2 0 3 0   2 0 2 3 3
        int farthest = 0, idx = 0;
        for (auto const& num : nums) {
            if (idx > farthest) return false;
            farthest = max(farthest, idx++ + num);
        }
        return true;
    }
};

int main() {
    Solution sol;
    
    system("pause");
    return 0;

}
