#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

// logs, int k
// logs[i] = [id, time]
// user active minutes: # of users having i UAM, from 1 to k


template<typename T>
void printVector(const T& t) {
    copy(t.cbegin(), t.cend(), ostream_iterator<typename T::value_type>(cout, ", "));
}

/* Definition for a binary tree node.*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// considering the 1/3 bound in Byzantine Fault Tolerance
// 
class Solution {
    int l_x = 0, r_x = 0, x;
public:
    int get_child_number(TreeNode* root) {
        if (root == nullptr) return 0;
        int lc_num = get_child_number(root->left);
        int rc_num = get_child_number(root->right);
        if (root->val == x) { l_x = lc_num; r_x = rc_num; }
        return lc_num + rc_num + 1;
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        this->x = x;
        int total = get_child_number(root);
        int max_y = max(l_x, r_x);
        max_y = max(max_y, total - l_x - r_x - 1);
        return max_y > n/2;
    }
};


int main() {
    Solution sol;
    
    system("pause");
    return 0;

}