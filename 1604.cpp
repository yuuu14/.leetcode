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
    cout << "\n";
}

// hh:mm -> minitues

class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string, vector<int>> km;
        vector<string> res;
        int n = keyName.size();
        for (int i = 0, h = 0, m = 0, t = 0; i < n; i++) {
            string kn = keyName[i], kt = keyTime[i];
            h = 10*(kt[0] - '0') + (kt[1] - '0'); 
            m = 10*(kt[3] - '0') + (kt[4] - '0');
            t = 60*h + m;
            km[kn].emplace_back(t);
        }

        for (auto& [kn, kt] : km) {
            sort(kt.begin(), kt.end());
            for (int i = 2; i < kt.size(); i++) {
                if (kt[i] - kt[i-2] <= 60) { res.emplace_back(kn); break; }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> keyName{"a","a","a","a","a","a","b","b","b","b","b"};
    vector<string> keyTime{"23:27","03:14","12:57","13:35","13:18","21:58","22:39","10:49","19:37","14:14","10:41"};
    vector<string> res = sol.alertNames(keyName, keyTime);
    printVector(res);

    system("pause");
    return 0;

}