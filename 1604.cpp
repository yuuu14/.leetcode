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


class Solution {
public:
    int solution() {
        return 0;
    }
};

int main() {
    Solution sol;
    
    system("pause");
    return 0;

}