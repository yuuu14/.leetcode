#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;


template<typename T>
void printVector(const T& t) {
    copy(t.cbegin(), t.cend(), ostream_iterator<typename T::value_type>(cout, ", "));
}


// combination of num list, find max length of consecutive numbers.
// 1 1 3 4 10
// 1 2 5
// 2 3 4 10    3 4 6 7 
// 
class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        // [0, x] -> [y, x+y] if x+1 >= y
        int res = 0;
        for (auto const& coin : coins) 
            if (res+1 >= coin) res += coin;
            else break;
        return res;
        
    }
};

int main() {
    Solution sol;
    
    system("pause");
    return 0;

}