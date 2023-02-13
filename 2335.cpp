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
    int fillCups(vector<int>& amount) {
        // type: cold, warm, hot: x,y,z
        // every sec: 2 diff / 1 any type
        sort(amount.begin(), amount.end());
        int x = amount[0], y = amount[1], z = amount[2];
        if (x+y <= z) return z; 
        return (x+y-z+1)/2 + z;

    }
};

int main() {
    Solution sol;
    vector<int> amount
        {1,4,2};
    
    system("pause");
    return 0;

}
