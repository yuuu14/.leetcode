#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
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
    int movesToMakeZigzag(vector<int>& nums) {
        // [0]>[1]<...
        int res1 = 0, res2 = 0, n = nums.size();
        if (n == 1) return 0;
        for (int i = 1, m, l, r; i < n; i += 2) {
            if (i == n-1) m = nums[i-1];
            else m = min(nums[i-1], nums[i+1]);
            res1 += max(0, nums[i]-m+1);
        }
        // [0]<[1]>...
        for (int i = 0, m, l, r; i < n; i += 2) {
            if (i == 0) m = nums[1];
            else if (i == n-1) m = nums[i-1];
            else m = min(nums[i-1], nums[i+1]);
            res2 += max(0, nums[i]-m+1);
        } 
        return min(res1, res2);
    }
};


int main() {
    Solution sol;
    vector<int> nums{9,6,1,6,2};
    int res = sol.movesToMakeZigzag(nums);
    cout << res << "\n";
    
    system("pause");
    return 0;

}
